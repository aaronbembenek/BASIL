#!/usr/bin/env python3
"""Build every seahorn-benchmarks benchmark through BASIL's pipeline.

For each test/**/<name>/<name>.c benchmark, this produces:
  - 5 compiled variants (gcc -O0, gcc -O2, gcc -O2 -fwrapv, clang -O0, clang -O2),
    each lifted through ddisasm/gtirb-semantics/readelf and run through BASIL
    (java -jar the assembly jar) to produce a .bpl file.
  - 1 preprocessed .c file (gcc -E -P, no -D__BASIL__) suitable for feeding
    directly into UAutomizer.

Every stage's outcome is recorded per benchmark/variant in a *.status.json
file next to the artifacts, plus aggregate build/summary.json and
build/summary.csv files. See seahorn-benchmarks/README.md for the manual
recipe this automates.
"""
from __future__ import annotations

import argparse
import csv
import json
import os
import shutil
import signal
import subprocess
import sys
import time
from collections import Counter
from concurrent.futures import ThreadPoolExecutor, as_completed
from pathlib import Path
from threading import Lock

SCRIPT_DIR = Path(__file__).resolve().parent
SEAHORN_DIR = SCRIPT_DIR.parent
BASIL_ROOT = SEAHORN_DIR.parent
TEST_DIR = SEAHORN_DIR / "test"
INCLUDE_DIR = SEAHORN_DIR / "include"
VERIFICATION_H = INCLUDE_DIR / "verification.h"

REQUIRED_TOOLS = [
    "aarch64-linux-gnu-gcc",
    "aarch64-linux-gnu-readelf",
    "clang-14",
    "gcc",
    "ddisasm",
    "gtirb-semantics",
    "java",
]

BASIL_ARGS = [
    "--simplify",
    "--dsa=",
    "--dsa-split",
    "--dsa-checks",
    "--transform-memory",
    "--noif",
]


def gcc_cmd(src: Path, out: Path, opt_flags: list[str]) -> list[str]:
    return [
        "aarch64-linux-gnu-gcc",
        "-D__BASIL__",
        "-include", str(VERIFICATION_H),
        "-I", str(INCLUDE_DIR),
        "-Wno-attributes",
        "-march=armv8.1-a",
        "-Werror=uninitialized",
        *opt_flags,
        str(src),
        "-o", str(out),
    ]


def clang_cmd(src: Path, out: Path, opt_flags: list[str]) -> list[str]:
    return [
        "clang-14",
        "--target=aarch64-linux-gnu",
        "-D__BASIL__",
        "-include", str(VERIFICATION_H),
        "-I", str(INCLUDE_DIR),
        "-march=armv8.1-a",
        "-Werror=uninitialized",
        *opt_flags,
        str(src),
        "-o", str(out),
    ]


VARIANTS = {
    "gcc_O0": lambda src, out: gcc_cmd(src, out, ["-O0"]),
    "gcc_O2": lambda src, out: gcc_cmd(src, out, ["-O2"]),
    "gcc_O2_fwrapv": lambda src, out: gcc_cmd(src, out, ["-O2", "-fwrapv"]),
    "clang_O0": lambda src, out: clang_cmd(src, out, ["-O0"]),
    "clang_O2": lambda src, out: clang_cmd(src, out, ["-O2"]),
}


class StageResult:
    def __init__(self, name: str, ok: bool, timed_out: bool, returncode: int | None,
                 duration_s: float, output: str):
        self.name = name
        self.ok = ok
        self.timed_out = timed_out
        self.returncode = returncode
        self.duration_s = duration_s
        self.output = output


def run_cmd(cmd: list[str], cwd: Path, timeout: float, stdout_to: Path | None = None) -> StageResult:
    """Run cmd, killing its whole process group on timeout. Optionally write
    captured stdout to stdout_to (used for the readelf step's redirection)."""
    start = time.monotonic()
    try:
        proc = subprocess.Popen(
            cmd, cwd=str(cwd), stdout=subprocess.PIPE, stderr=subprocess.STDOUT,
            text=True, start_new_session=True,
        )
    except OSError as e:
        return StageResult(cmd[0], False, False, None, 0.0, f"failed to start: {e}")

    try:
        out, _ = proc.communicate(timeout=timeout)
        duration = time.monotonic() - start
        ok = proc.returncode == 0
        if ok and stdout_to is not None:
            stdout_to.write_text(out)
        return StageResult(cmd[0], ok, False, proc.returncode, duration, out)
    except subprocess.TimeoutExpired:
        try:
            os.killpg(os.getpgid(proc.pid), signal.SIGTERM)
            proc.wait(timeout=5)
        except (ProcessLookupError, subprocess.TimeoutExpired):
            try:
                os.killpg(os.getpgid(proc.pid), signal.SIGKILL)
            except ProcessLookupError:
                pass
        try:
            out, _ = proc.communicate(timeout=5)
        except Exception:
            out = ""
        duration = time.monotonic() - start
        return StageResult(cmd[0], False, True, None, duration, out or "(timed out)")


def write_status(status_path: Path, stages: dict, reached: str, outcome: str,
                  cached: bool = False) -> None:
    status_path.write_text(json.dumps({
        "stages": stages,
        "reached": reached,
        "outcome": outcome,
        "cached": cached,
    }, indent=2))


def load_cached_success(status_path: Path, final_artifact: Path) -> dict | None:
    if not status_path.exists() or not final_artifact.exists():
        return None
    try:
        data = json.loads(status_path.read_text())
    except (json.JSONDecodeError, OSError):
        return None
    if data.get("outcome") == "success":
        data["cached"] = True
        return data
    return None


def process_variant(bench_src: Path, bench_rel: Path, variant: str,
                     cmd_builder, out_dir: Path, jar_path: Path,
                     basil_timeout: float, stage_timeout: float, force: bool) -> dict:
    base = bench_src.stem
    binary = out_dir / f"{base}_{variant}"
    gtirb = out_dir / f"{base}_{variant}.gtirb"
    gts = out_dir / f"{base}_{variant}.gts"
    relf = out_dir / f"{base}_{variant}.relf"
    bpl = out_dir / f"{base}_{variant}.bpl"
    log_path = out_dir / f"{base}_{variant}.log"
    status_path = out_dir / f"{base}_{variant}.status.json"

    if not force:
        cached = load_cached_success(status_path, bpl)
        if cached is not None:
            return {"benchmark": str(bench_rel), "variant": variant, **cached}

    out_dir.mkdir(parents=True, exist_ok=True)
    log_chunks = []
    stages: dict[str, str] = {}

    def record(stage: StageResult) -> bool:
        stages[stage.name_key] = "timeout" if stage.timed_out else ("ok" if stage.ok else "fail")
        log_chunks.append(f"=== {stage.name_key} ===\n$ {stage.cmdline}\n{stage.output}\n")
        return stage.ok

    steps = [
        ("compile", cmd_builder(bench_src, binary), stage_timeout, None),
        ("ddisasm", ["ddisasm", str(binary), "--ir", str(gtirb)], stage_timeout, None),
        ("gtirb-semantics", ["gtirb-semantics", str(gtirb), str(gts)], stage_timeout, None),
        ("readelf", ["aarch64-linux-gnu-readelf", "-s", "-r", "-W", str(binary)], stage_timeout, relf),
        ("basil", ["java", "-jar", str(jar_path), "--input", str(gts), "--relf", str(relf),
                    "-o", str(bpl)] + BASIL_ARGS, basil_timeout, None),
    ]

    reached = "none"
    outcome = "fail"
    for stage_name, cmd, timeout, redirect in steps:
        reached = stage_name
        result = run_cmd(cmd, cwd=SEAHORN_DIR, timeout=timeout, stdout_to=redirect)
        result.name_key = stage_name
        result.cmdline = " ".join(cmd)
        ok = record(result)
        if not ok:
            outcome = "timeout" if result.timed_out else "fail"
            break
    else:
        outcome = "success"

    log_path.write_text("\n".join(log_chunks))
    write_status(status_path, stages, reached, outcome)
    return {"benchmark": str(bench_rel), "variant": variant, "stages": stages,
            "reached": reached, "outcome": outcome, "cached": False}


def process_preprocess(bench_src: Path, bench_rel: Path, out_dir: Path,
                        stage_timeout: float, force: bool) -> dict:
    base = bench_src.stem
    out_c = out_dir / f"{base}.preprocessed.c"
    status_path = out_dir / f"{base}.preprocess.status.json"

    if not force:
        cached = load_cached_success(status_path, out_c)
        if cached is not None:
            return {"benchmark": str(bench_rel), "variant": "preprocess", **cached}

    out_dir.mkdir(parents=True, exist_ok=True)
    cmd = ["gcc", "-E", "-P", "-I", str(INCLUDE_DIR), "-include", str(VERIFICATION_H),
           str(bench_src), "-o", str(out_c)]
    result = run_cmd(cmd, cwd=SEAHORN_DIR, timeout=stage_timeout)
    stages = {"preprocess": "ok" if result.ok else ("timeout" if result.timed_out else "fail")}
    outcome = "success" if result.ok else stages["preprocess"]
    write_status(status_path, stages, "preprocess", outcome)
    (out_dir / f"{base}.preprocess.log").write_text(f"$ {' '.join(cmd)}\n{result.output}\n")
    return {"benchmark": str(bench_rel), "variant": "preprocess", "stages": stages,
            "reached": "preprocess", "outcome": outcome, "cached": False}


def check_tools() -> list[str]:
    return [t for t in REQUIRED_TOOLS if shutil.which(t) is None]


def build_assembly_jar() -> Path:
    mill = BASIL_ROOT / "mill"
    print("Building BASIL assembly jar (./mill show assembly)...", file=sys.stderr)
    proc = subprocess.run([str(mill), "show", "assembly"], cwd=str(BASIL_ROOT),
                           capture_output=True, text=True, timeout=1800)
    if proc.returncode != 0:
        print(proc.stdout, file=sys.stderr)
        print(proc.stderr, file=sys.stderr)
        raise SystemExit("./mill show assembly failed; see output above")
    line = proc.stdout.strip().splitlines()[-1]
    ref = json.loads(line)
    # format: "ref:v0:<hash>:<path>"
    path_str = ref.split(":", 3)[3] if ref.startswith("ref:") else ref
    jar_path = Path(path_str)
    if not jar_path.exists():
        raise SystemExit(f"assembly jar not found at reported path: {jar_path}")
    print(f"Assembly jar: {jar_path}", file=sys.stderr)
    return jar_path


def write_summary(build_dir: Path, results: list[dict]) -> None:
    (build_dir / "summary.json").write_text(json.dumps(results, indent=2))
    with (build_dir / "summary.csv").open("w", newline="") as f:
        writer = csv.writer(f)
        writer.writerow(["benchmark", "variant", "reached", "outcome", "cached"])
        for r in results:
            writer.writerow([r["benchmark"], r["variant"], r["reached"], r["outcome"], r["cached"]])


def print_report(results: list[dict]) -> None:
    by_variant: dict[str, Counter] = {}
    fail_stage_by_variant: dict[str, Counter] = {}
    for r in results:
        v = r["variant"]
        by_variant.setdefault(v, Counter())[r["outcome"]] += 1
        if r["outcome"] != "success":
            fail_stage_by_variant.setdefault(v, Counter())[r["reached"]] += 1

    total = len(set(r["benchmark"] for r in results))
    print(f"\n=== Build report ({total} benchmarks) ===")
    for v in sorted(by_variant):
        c = by_variant[v]
        n = sum(c.values())
        print(f"{v}: {c.get('success', 0)}/{n} succeeded", end="")
        fails = fail_stage_by_variant.get(v)
        if fails:
            breakdown = ", ".join(f"{stage}={n}" for stage, n in sorted(fails.items()))
            print(f"  (failures by stage: {breakdown})")
        else:
            print()


def main() -> None:
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("--jobs", type=int, default=os.cpu_count() or 4,
                     help="parallel worker threads (default: cpu count)")
    ap.add_argument("--timeout-basil", type=float, default=120.0,
                     help="timeout in seconds for the BASIL step (default: 120)")
    ap.add_argument("--stage-timeout", type=float, default=300.0,
                     help="timeout in seconds for compile/ddisasm/gtirb-semantics/readelf/preprocess steps")
    ap.add_argument("--filter", default=None,
                     help="only process benchmarks whose relative path contains this substring")
    ap.add_argument("--variants", default=",".join(VARIANTS),
                     help=f"comma-separated subset of variants to build (default: all: {','.join(VARIANTS)})")
    ap.add_argument("--no-preprocess", action="store_true",
                     help="skip generating UAutomizer preprocessed .c files")
    ap.add_argument("--force", action="store_true",
                     help="ignore cached successful results and rebuild everything")
    ap.add_argument("--build-dir", default=str(SEAHORN_DIR / "build"),
                     help="output directory (default: seahorn-benchmarks/build)")
    ap.add_argument("--dry-run", action="store_true",
                     help="only discover benchmarks and print counts, then exit")
    args = ap.parse_args()

    variants = args.variants.split(",")
    unknown = [v for v in variants if v not in VARIANTS]
    if unknown:
        raise SystemExit(f"unknown variant(s): {unknown}; choices are {list(VARIANTS)}")

    benchmarks = sorted(TEST_DIR.rglob("*.c"))
    if args.filter:
        benchmarks = [b for b in benchmarks if args.filter in str(b.relative_to(TEST_DIR))]

    print(f"Discovered {len(benchmarks)} benchmark(s) under {TEST_DIR}"
          + (f" matching filter {args.filter!r}" if args.filter else ""))

    if args.dry_run:
        n_jobs = len(benchmarks) * len(variants) + (0 if args.no_preprocess else len(benchmarks))
        print(f"Would run {n_jobs} job(s) across {len(variants)} variant(s) "
              f"{'(+ preprocess)' if not args.no_preprocess else ''}")
        return

    missing = check_tools()
    if missing:
        raise SystemExit(f"missing required tool(s) on PATH: {missing}")

    build_dir = Path(args.build_dir)
    build_dir.mkdir(parents=True, exist_ok=True)

    jar_path = build_assembly_jar()

    jobs = []
    for src in benchmarks:
        rel = src.relative_to(TEST_DIR)
        out_dir = build_dir / rel.parent
        for v in variants:
            jobs.append(("variant", src, rel, v, out_dir))
        if not args.no_preprocess:
            jobs.append(("preprocess", src, rel, None, out_dir))

    results: list[dict] = []
    lock = Lock()
    completed = 0
    total = len(jobs)
    checkpoint_every = 200

    def run_job(job):
        kind, src, rel, variant, out_dir = job
        if kind == "variant":
            return process_variant(src, rel, variant, VARIANTS[variant], out_dir, jar_path,
                                    args.timeout_basil, args.stage_timeout, args.force)
        else:
            return process_preprocess(src, rel, out_dir, args.stage_timeout, args.force)

    print(f"Running {total} job(s) with {args.jobs} worker(s)...")
    with ThreadPoolExecutor(max_workers=args.jobs) as pool:
        futures = [pool.submit(run_job, job) for job in jobs]
        for fut in as_completed(futures):
            result = fut.result()
            with lock:
                results.append(result)
                completed += 1
                if completed % checkpoint_every == 0 or completed == total:
                    write_summary(build_dir, results)
                    print(f"  {completed}/{total} done", file=sys.stderr)

    write_summary(build_dir, results)
    print_report(results)
    print(f"\nFull results: {build_dir / 'summary.json'} / {build_dir / 'summary.csv'}")


if __name__ == "__main__":
    main()
