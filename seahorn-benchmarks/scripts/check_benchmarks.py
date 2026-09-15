#!/usr/bin/env python3
"""Check seahorn-benchmarks sources for traits that make a benchmark vacuous for
CHC-based verification.

For each test/**/<name>/<name>.c benchmark, this reports:
  - loop: whether code reachable from main in the benchmark itself (not the
    shared include/verification.h) contains a while/do/for loop or a backward
    goto.
  - recursion: whether the functions reachable from main call each other in a
    cycle (direct or mutual recursion).
  - reachable_assertion: whether a call to __VERIFIER_error, the error sink that
    __VERIFIER_assert, sassert and __assert_fail all lead to, is reachable from
    main: "yes"; "unreachable" if the benchmark calls __VERIFIER_error (directly
    or through a helper) only in code that cannot be reached; or "none".

A benchmark with neither a loop nor recursion yields an acyclic CHC system, so no
invariant inference is needed; one without a reachable assertion has no property
to verify. See README.md for how these are used to decide removals. The script
only reports; it never modifies the corpus.

Each benchmark is parsed with clang using the same preprocessor setup as the
build (-D__BASIL__ -include include/verification.h -I include), in a single
invocation that dumps the AST as JSON and emits -Wunreachable-code diagnostics.
Within a function, a statement is dead if:
  - clang reports it as unreachable, or it is nested in a dead statement;
  - it follows, in the same block, a statement that clang reports as unreachable
    or that never falls through (return, goto, break, continue); or
  - it is the branch of an `if` whose condition is an integer literal that
    selects the other branch (e.g. CIL's `if (0) { goto ERROR; }`);
unless it contains an entry point: a label targeted by a live goto, or a
case/default label. Which gotos are live depends on which labels are targeted,
so this is iterated to a fixpoint. clang alone is not enough: it does not report
code behind a label as unreachable, even when only dead gotos target the label
(e.g. `return 0; ERROR: __VERIFIER_error();`). Calls in dead code are ignored
when computing which functions are reachable from main.

Limitations:
  - Only direct calls are followed. Calls through function pointers are listed in
    the notes column; a function reached only that way is treated as dead, which
    could hide a loop, so such benchmarks need manual review.
  - A goto counts as a loop only if its target label appears earlier in the same
    function; a cycle formed purely by forward gotos is not detected.
  - Other dead code (e.g. behind a condition that is only false after constant
    propagation) is treated as live, so a loop or assertion there still counts.
"""
from __future__ import annotations

import argparse
import json
import re
import subprocess
import sys
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

SCRIPT_DIR = Path(__file__).resolve().parent
SEAHORN_DIR = SCRIPT_DIR.parent
TEST_DIR = SEAHORN_DIR / "test"
INCLUDE_DIR = SEAHORN_DIR / "include"
VERIFICATION_H = INCLUDE_DIR / "verification.h"

CLANG = "clang-14"
ERROR_SINK = "__VERIFIER_error"
STDIN_NAME = "<stdin>"
LOOP_KINDS = {"WhileStmt": "while", "DoStmt": "do", "ForStmt": "for"}
NO_FALLTHROUGH_KINDS = {"ReturnStmt", "GotoStmt", "BreakStmt", "ContinueStmt"}
SWITCH_LABEL_KINDS = {"CaseStmt", "DefaultStmt"}

# Preprocessor line markers (e.g. `# 1 "/tmp/tmp.c"`) make clang report
# diagnostics at remapped locations, while the JSON AST records the real line
# numbers. Blanking them keeps both in terms of the same lines.
LINE_MARKER = re.compile(r"^\s*#\s*(line\s+)?\d+\b.*$")
UNREACHABLE_DIAGNOSTIC = re.compile(
    r"^(?P<file>.*?):(?P<line>\d+):(?P<col>\d+): warning: .*\[-Wunreachable-code\]"
)


def run_clang(src: Path) -> subprocess.CompletedProcess:
    lines = src.read_text(errors="replace").split("\n")
    text = "\n".join("" if LINE_MARKER.match(line) else line for line in lines)
    cmd = [
        CLANG, "-x", "c", "-fsyntax-only",
        "-Wno-everything", "-Wunreachable-code",
        "-D__BASIL__", "-include", str(VERIFICATION_H),
        "-I", str(INCLUDE_DIR), "-I", str(src.parent),
        "-Xclang", "-ast-dump=json", "-",
    ]
    return subprocess.run(cmd, input=text, capture_output=True, text=True, cwd=SEAHORN_DIR)


def annotate_locations(ast: dict) -> None:
    """
    Resolve each node's location to (file, line, column, offset). clang's JSON
    dumper omits the file and line when they are unchanged since the previously
    printed location, so they are tracked across the whole dump in output order
    (a pre-order traversal, with a node's loc and range before its children).
    Macro locations are resolved to their expansion.
    """
    file = line = None

    def bare(loc):
        nonlocal file, line
        if "offset" not in loc:
            return None
        file = loc.get("file", file)
        line = loc.get("line", line)
        return (file, line, loc.get("col"), loc["offset"])

    def resolve(loc):
        if "spellingLoc" in loc:
            bare(loc["spellingLoc"])
            return bare(loc.get("expansionLoc", {}))
        return bare(loc)

    stack = [ast]
    while stack:
        node = stack.pop()
        if "loc" in node:
            node["_loc"] = resolve(node["loc"])
        if "range" in node:
            node["_begin"] = resolve(node["range"].get("begin", {}))
            resolve(node["range"].get("end", {}))
        stack.extend(reversed(node.get("inner", [])))


def strip_implicit(node: dict | None) -> dict | None:
    while node is not None and node.get("kind") in ("ImplicitCastExpr", "ParenExpr"):
        node = (node.get("inner") or [None])[0]
    return node


def callee_name(call: dict) -> str | None:
    node = strip_implicit((call.get("inner") or [None])[0])
    if node is not None and node.get("kind") == "DeclRefExpr":
        ref = node.get("referencedDecl", {})
        if ref.get("kind") == "FunctionDecl":
            return ref.get("name")
    return None


def constant_condition(if_stmt: dict) -> bool | None:
    """The truth value of an `if` condition that is an integer literal, else None."""
    cond = strip_implicit((if_stmt.get("inner") or [None])[0])
    if cond is not None and cond.get("kind") == "IntegerLiteral":
        return int(cond.get("value", "1")) != 0
    return None


def walk(root: dict):
    stack = [root]
    while stack:
        node = stack.pop()
        yield node
        stack.extend(node.get("inner", []))


def scan_function(body: dict, dead: set, targets: set) -> tuple[list, list, set]:
    """
    One pass over a function body, given the set of label decl ids targeted by
    live gotos. Returns (calls, loops, targets of gotos found live): calls as
    (callee or None, is_dead, line); loops described for live code only.
    """
    contains_entry = {}
    for node in reversed(list(walk(body))):  # children before parents
        kind = node.get("kind")
        contains_entry[id(node)] = (
            kind in SWITCH_LABEL_KINDS
            or (kind == "LabelStmt" and node["declId"] in targets)
            or any(contains_entry[id(c)] for c in node.get("inner", []))
        )

    def is_reported(node):
        begin = node.get("_begin")
        return begin is not None and begin[:3] in dead

    calls, loops, gotos, labels = [], [], [], {}
    stack = [(body, False)]
    while stack:
        node, in_dead = stack.pop()
        in_dead = in_dead or is_reported(node)
        begin = node.get("_begin") or (None, None, None, None)
        kind = node.get("kind")
        if kind in LOOP_KINDS and not in_dead:
            loops.append(f"{LOOP_KINDS[kind]}@{begin[1]}")
        elif kind == "LabelStmt":
            labels[node["declId"]] = begin[3]
        elif kind == "GotoStmt":
            gotos.append((node["targetLabelDeclId"], begin[3], begin[1], in_dead))
        elif kind == "CallExpr":
            calls.append((callee_name(node), in_dead, begin[1]))

        children = node.get("inner", [])
        flags = [in_dead] * len(children)
        if kind == "CompoundStmt":
            unreachable = False
            for i, child in enumerate(children):
                if contains_entry[id(child)]:
                    unreachable = False
                flags[i] = in_dead or unreachable
                if is_reported(child) or child.get("kind") in NO_FALLTHROUGH_KINDS:
                    unreachable = True
        elif kind == "IfStmt":
            taken = constant_condition(node)
            if taken is not None:
                # inner is [condition, then, else?]; mark the branch that is never taken
                never = 1 if taken is False else 2
                if never < len(children) and not contains_entry[id(children[never])]:
                    flags[never] = True
        stack.extend(reversed(list(zip(children, flags))))

    for target, offset, line, in_dead in gotos:
        if not in_dead and target in labels and labels[target] < offset:
            loops.append(f"backward goto@{line}")
    live_targets = {target for target, _, _, in_dead in gotos if not in_dead}
    return calls, loops, live_targets


def summarize_function(body: dict, dead: set) -> tuple[list, list]:
    """
    Return (calls, loops) for a function body, iterating until the set of labels
    targeted by live gotos is stable (it can only shrink).
    """
    targets = {n["targetLabelDeclId"] for n in walk(body) if n.get("kind") == "GotoStmt"}
    while True:
        calls, loops, live_targets = scan_function(body, dead, targets)
        if live_targets == targets:
            return calls, loops
        targets = live_targets


def cyclic_components(nodes: set, edges: dict) -> list[list[str]]:
    """Tarjan's algorithm; returns the strongly connected components with a cycle."""
    index, low, on_stack, stack, result = {}, {}, set(), [], []

    def visit(v):
        index[v] = low[v] = len(index)
        stack.append(v)
        on_stack.add(v)
        for w in edges.get(v, ()):
            if w not in nodes:
                continue
            if w not in index:
                visit(w)
                low[v] = min(low[v], low[w])
            elif w in on_stack:
                low[v] = min(low[v], index[w])
        if low[v] == index[v]:
            component = []
            while True:
                w = stack.pop()
                on_stack.discard(w)
                component.append(w)
                if w == v:
                    break
            if len(component) > 1 or v in edges.get(v, ()):
                result.append(sorted(component))

    for v in sorted(nodes):
        if v not in index:
            visit(v)
    return result


def check(src: Path, test_dir: Path) -> dict:
    row = {"benchmark": str(src.parent.relative_to(test_dir)), "loop": "?", "recursion": "?",
           "reachable_assertion": "?", "details": "", "notes": ""}
    proc = run_clang(src)
    if proc.returncode != 0:
        first_error = next((l for l in proc.stderr.splitlines() if "error:" in l), proc.stderr.strip()[:200])
        row["notes"] = f"clang failed: {first_error}"
        return row
    dead = set()
    for line in proc.stderr.splitlines():
        m = UNREACHABLE_DIAGNOSTIC.match(line)
        if m:
            dead.add((m.group("file"), int(m.group("line")), int(m.group("col"))))

    ast = json.loads(proc.stdout)
    annotate_locations(ast)

    functions = {}
    for decl in ast.get("inner", []):
        if decl.get("kind") != "FunctionDecl":
            continue
        body = next((c for c in decl.get("inner", []) if c.get("kind") == "CompoundStmt"), None)
        if body is not None:
            own = (decl.get("_loc") or (None,))[0] == STDIN_NAME
            functions[decl["name"]] = (body, own)
    summaries = {name: summarize_function(body, dead) for name, (body, _) in functions.items()}
    own = {name for name, (_, is_own) in functions.items() if is_own}

    live_edges = {name: {c for c, in_dead, _ in calls if c in functions and not in_dead}
                  for name, (calls, _) in summaries.items()}
    live, todo = set(), ["main"] if "main" in functions else []
    while todo:
        name = todo.pop()
        if name not in live:
            live.add(name)
            todo.extend(live_edges[name])

    notes = []
    if "main" not in functions:
        notes.append("no main")
    indirect = sorted({f"{name}:{line}" for name in live
                       for callee, in_dead, line in summaries[name][0] if callee is None and not in_dead})
    if indirect:
        notes.append("indirect calls at " + ",".join(indirect))

    loops = [f"{name}:{loop}" for name in sorted(live & own) for loop in summaries[name][1]]
    cycles = cyclic_components(live & own, live_edges)

    # Functions that can lead to the error sink, ignoring reachability
    reaching = {ERROR_SINK}
    changed = True
    while changed:
        changed = False
        for name, (calls, _) in summaries.items():
            if name not in reaching and any(c in reaching for c, _, _ in calls):
                reaching.add(name)
                changed = True
    sites = [f"{name}:{line}" for name in sorted(live)
             for callee, in_dead, line in summaries[name][0] if callee == ERROR_SINK and not in_dead]
    if sites:
        assertion = "yes"
    elif any(c in reaching for name in own for c, _, _ in summaries[name][0]):
        assertion = "unreachable"
    else:
        assertion = "none"

    details = []
    if loops:
        details.append("loops=" + ",".join(loops))
    if cycles:
        details.append("recursion=" + ";".join("+".join(c) for c in cycles))
    if sites:
        details.append("error_sites=" + ",".join(sites))
    row.update(loop="yes" if loops else "no", recursion="yes" if cycles else "no",
               reachable_assertion=assertion, details="; ".join(details), notes="; ".join(notes))
    return row


def is_flagged(row: dict) -> bool:
    return (row["loop"] == "no" and row["recursion"] == "no") or row["reachable_assertion"] != "yes" \
        or bool(row["notes"])


def main() -> None:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--filter", default=None,
                    help="only check benchmarks whose relative path contains this substring")
    ap.add_argument("--jobs", type=int, default=16, help="parallel clang invocations (default: 16)")
    ap.add_argument("--test-dir", default=str(TEST_DIR), help="benchmark source tree (default: seahorn-benchmarks/test)")
    ap.add_argument("--output", help="write the TSV report to this file instead of stdout")
    ap.add_argument("--flagged-only", action="store_true",
                    help="only report benchmarks with no loop and no recursion, no reachable assertion, or notes")
    args = ap.parse_args()

    test_dir = Path(args.test_dir).resolve()
    sources = sorted(test_dir.rglob("*.c"))
    if args.filter:
        sources = [s for s in sources if args.filter in str(s.relative_to(test_dir))]

    with ThreadPoolExecutor(max_workers=args.jobs) as pool:
        rows = list(pool.map(lambda s: check(s, test_dir), sources))

    columns = ["benchmark", "loop", "recursion", "reachable_assertion", "details", "notes"]
    out = open(args.output, "w") if args.output else sys.stdout
    try:
        out.write("\t".join(columns) + "\n")
        for row in rows:
            if not args.flagged_only or is_flagged(row):
                out.write("\t".join(row[c] for c in columns) + "\n")
    finally:
        if out is not sys.stdout:
            out.close()

    def listing(title, selected):
        print(f"{title} ({len(selected)}):", file=sys.stderr)
        for row in selected:
            print(f"  {row['benchmark']}", file=sys.stderr)

    print(f"Checked {len(rows)} benchmark(s).", file=sys.stderr)
    listing("No loop and no recursion", [r for r in rows if r["loop"] == "no" and r["recursion"] == "no"])
    listing("No assertion at all", [r for r in rows if r["reachable_assertion"] == "none"])
    listing("Assertion present but unreachable", [r for r in rows if r["reachable_assertion"] == "unreachable"])
    listing("Needs manual review (clang failure, no main, indirect calls)", [r for r in rows if r["notes"]])


if __name__ == "__main__":
    main()
