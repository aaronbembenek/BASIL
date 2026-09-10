# seahorn-benchmarks

SeaHorn-style C benchmarks (`test/`) plus a shared header (`include/verification.h`,
with a compat shim at `include/seahorn/seahorn.h`) providing `unknown()`/`nondet()`/
`__VERIFIER_*`/`sassert()`/etc., and no-op/terminating stubs for `printf`, `puts`,
and `exit`. The header is guarded by `#ifdef __BASIL__` for the pieces that need a
real, compilable/linkable C body only when targeting BASIL's binary pipeline.

## Duplicate benchmarks

Two lightweight duplicate checks were run over every `test/**/*.c` file, grouping by
hash. In both passes, one of each duplicate pair has been removed, keeping the more
descriptive/canonical name:

1. **Byte-for-byte** (`sha256sum` on the raw file) — found 4 pairs with identical
   source under different names/paths:

   | kept | removed |
   |---|---|
   | `test/c/pie/ICE/benchmarks/veris.c_sendmail__tTflag_arr_one_loop_safe/` | `test/c/pie/ICE/benchmarks/vsend/` |
   | `test/c/pie/ICE/benchmarks/trex03_safe/` | `test/c/pie/ICE/benchmarks/trex03/` |
   | `test/c/recursions/recursive/Fibonacci01_true-unreach-call_true-no-overflow/` | `test/demo/fibo/` |
   | `test/demo/19/` | `test/demo/28/` |

2. **Preprocessed** (`gcc -E -P -I include -include include/verification.h`, then
   hash the output) — more precise than a raw hash since it's insensitive to
   comments/whitespace/leftover line-marker text while still being an exact,
   deterministic comparison (no fuzzy matching). Found 4 further pairs whose raw
   source differed only in such cosmetic content:

   | kept | removed | raw source differed only by |
   |---|---|---|
   | `test/c/pie/ICE/benchmarks/sum04_safe/` | `test/c/pie/ICE/benchmarks/sum04/` | a commented-out `// #define a (2)` line |
   | `test/c/VeriMAP/TRACER-testabs7_VeriMAP_true/` | `test/c/VeriMAP/TRACER-testabs13_VeriMAP_true/` | embedded `# N "....tmp.c"` line-marker comments |
   | `test/c/VeriMAP/TRACER-testabs3_VeriMAP_true/` | `test/c/VeriMAP/TRACER-testwp4_VeriMAP_true/` | embedded `# N "....tmp.c"` line-marker comments |
   | `test/c/VeriMAP/TRACER-testabs1_VeriMAP_true/` | `test/c/VeriMAP/TRACER-testabs6_VeriMAP_true/` | embedded `# N "....tmp.c"` line-marker comments |

   Note: this corpus (particularly `c/VeriMAP` and `c/pie`) also contains many
   benchmarks that are deliberately *near*-identical but not true duplicates (e.g.
   safe/unsafe variants differing by one planted line, with different expected
   verdicts) — a fuzzy/similarity-based duplicate check would flag many of these as
   false positives, which is why only exact (raw or preprocessed) hash matches were
   treated as redundant here.

## Compile-stage fixes

Every remaining benchmark now compiles cleanly under all 5 variants (`gcc`/`clang` ×
`-O0`/`-O2`, plus `gcc -O2 -fwrapv`) — 0 compile-stage failures, down from ~54 across
16 files that had genuine bugs in the benchmark source, not the pipeline:

- **Illegal non-constant global initializer** — `c/VeriMAP/TRACER-testloop12_VeriMAP_true/`:
  `int x = unknown();` at file scope (a function call isn't a compile-time constant);
  moved into `main()`.
- **Missing `__VERIFIER_nondet_char` definition** — added to `include/verification.h`
  (called by `sv-benchmarks/misc/pals_*`, but only `_int`/`_long`/`_uint`/`_bool`
  existed).
- **Uninitialized variables from a disabled/missing nondet-init line** — `fig1.c`,
  `fig1.v.c`, `vsend.v.c`, `04.c`: a `unknown()`/`__VERIFIER_nondet_*` initializer was
  commented out or simply absent. Restored using `unknown()`/`__VERIFIER_nondet_*`,
  **not** a hardcoded `0` — a constant would silently narrow the proof obligation to
  "safe only when the value happens to be that constant" instead of preserving the
  full nondeterministic range the variable is meant to represent.
- **Non-`noreturn` local `error()` wrapper** — `sv-benchmarks/systemc/kundu{,1,2}`,
  `mem_slave_tlm.{1-5}`: a local `error(void)` helper called the already-`noreturn`
  `__VERIFIER_error()` but wasn't itself marked `noreturn`, so the compiler couldn't
  prove a following uninitialized-variable use was dead code. Marked `error()`
  `__attribute__((noreturn))` and removed the now-dead trailing `return;`.
- **CIL coroutine "saved state" locals** — `mem_slave_tlm.{1-5}`, `pc_sfifo_3`: locals
  representing saved coroutine state, read on first entry before any real value had
  been assigned. Initialized via `__VERIFIER_nondet_int()` (matching each file's own
  existing convention) for the same soundness reason as above, not `0`.
- **Out-of-bounds fill loop** — `c/pie/ICE/benchmarks/vsend.v/vsend.v.c`: a loop meant
  to nondet-fill `char in[11]` wrote to the constant index `in[11]` (one past the end,
  and never touching `in[0..10]`) instead of `in[i]`.

## Benchmarks removed (no loop or recursion)

`dagger/ex2.c` and `c/VeriMAP/TRACER-test1-unsafe_VeriMAP_false/` were removed: both
are bounded case-split programs with no loop and no recursion (checked with a
lightweight script — `for`/`while`/`do` keywords, backward `goto`, and a call-graph
cycle check across each file's own functions, the last of which is needed to catch
*mutual* recursion like `isOdd`/`isEven`-style pairs, not just direct self-calls).
Loop-free, recursion-free C produces an **acyclic** Horn-clause system: solvable by
inlining every clause into one formula and making a single SMT call, with no
fixed-point/invariant inference required — i.e. these don't exercise the capability
CHC solving exists to test. The same script confirmed no other benchmark in the
corpus lacks both a loop and recursion.

## Compiling a benchmark for BASIL

Pass `-D__BASIL__` and force-include the header. Verified with both compilers, at
both `-O0` and `-O2` — in both cases, `exit()` is confirmed (by inspecting the
disassembly) to be genuinely inlined at its call site, with no separate `bl exit`
in the compiled binary; only the inner `__VERIFIER_assume` call and the trailing
infinite loop remain, matching how UAutomizer models `exit` as a direct
call-site substitution rather than a real function call:

```bash
# gcc — add -Wno-attributes (see below for why)
aarch64-linux-gnu-gcc -D__BASIL__ -include include/verification.h -Wno-attributes -O0 test/demo/34/34.c -o 34_O0
aarch64-linux-gnu-gcc -D__BASIL__ -include include/verification.h -Wno-attributes -O2 test/demo/34/34.c -o 34_O2

# clang (cross-compiles to aarch64 via --target); no extra flag needed — clang
# does not emit the warning gcc does for this pattern (see below)
clang-14 --target=aarch64-linux-gnu -D__BASIL__ -include include/verification.h -O0 test/demo/34/34.c -o 34_O0
clang-14 --target=aarch64-linux-gnu -D__BASIL__ -include include/verification.h -O2 test/demo/34/34.c -o 34_O2
```

NOTE: we should also include these options (these are for gcc; need to check on equivalents for clang): `-march=armv8.1-a -Werror=uninitialized`

**On the `-Wno-attributes` flag**: `exit()` is declared
`__attribute__((noreturn, always_inline))` so that it's reliably inlined at
every call site (verified via disassembly, at both `-O0` and `-O2`, with both
compilers) rather than left as a real function call that BASIL would need to
separately recognize as non-returning. With **gcc**, this triggers
`warning: 'always_inline' function might not be inlinable [-Wattributes]` —
this was investigated and is a generic, harmless GCC diagnostic: it fires for
*any* `always_inline` function that isn't also declared with the `inline`
keyword, completely independent of the function's actual body, `noreturn`,
optimization level, or whether it's a cross- or host-compile (confirmed by
reproducing it with a trivial empty always-inline function). **Do not "fix" it
by adding `inline`** — that was tested and it silences the warning but
reintroduces the bug: with `inline` added, gcc at `-O0` reverts to emitting a
real `bl exit` call instead of inlining it (verified via disassembly), which
is exactly the behavior we're trying to avoid. `-Wno-attributes` suppresses
just this diagnostic class without affecting codegen (verified: identical
disassembly with/without the flag). **clang does not emit this warning at
all** for the same `always_inline`-without-`inline` pattern, so no
corresponding flag is needed there.

Then lift and run through BASIL as usual:

```bash
ddisasm 34_O0 --ir 34_O0.gtirb
gtirb-semantics 34_O0.gtirb 34_O0.gts
aarch64-linux-gnu-readelf -s -r -W 34_O0 > 34_O0.relf
./mill run --input 34_O0.gts --relf 34_O0.relf -o 34_O0.bpl --simplify --dsa=  --dsa-split --dsa-checks --transform-memory --noif
```

**`--simplify` is required**, not optional — the `__VERIFIER_error`/`__VERIFIER_assert`/
`__VERIFIER_assume`/`__VERIFIER_nondet_*` name-based rewrites (turning these calls into
real Boogie `assert`/`assume`/`havoc`) only run as part of BASIL's `--simplify` pass
(`liftSVComp` in `src/main/scala/ir/transforms/LinuxAssertFail.scala`). Without it,
these calls are left as literal, un-rewritten procedure calls to whatever `verification.h`
happened to compile them to, which is not what you want. `--noif` disables BASIL's
information-flow/taint instrumentation, which otherwise generates unrelated `Gamma`-prefixed
assertions that have nothing to do with these benchmarks' actual properties.

**Known issue** (as of this writing): `exit()` called from a function other than `main`
is not correctly recognized as non-returning by BASIL — the CFG isn't cut after such a
call, only after ones inside `main` (see `replaceJumpsInNonReturningProcs` in
`src/main/scala/ir/transforms/Simp.scala`). This can produce spurious verification
failures for benchmarks calling `exit()` from a helper function.

## Known BASIL bugs affecting verification-stage results

With the compile-stage fixes above, `preprocess` and all 5 compile variants now
succeed 100% of the time; every remaining failure is BASIL itself crashing on a hard
`assert`/`???` during the `basil` (`java -jar ...`) pipeline stage, not a benchmark or
compiler problem. Two distinct bugs account for nearly all of them:

1. **Spurious "uninitialized register" assertion — hits every variant.**
   `assert(ir.invariant.readUninitialised(ctx.program))` in
   `src/main/scala/ir/transforms/SimplifyPipeline.scala:59` fires because register
   **R29** (the AArch64 frame pointer) is flagged as read-before-defined — typically
   in a function prologue's `stp x29, ...` inside `__VERIFIER_assert`/`main`/
   `test_entry` blocks. Likely cause: commit `4efcd277` ("CalleePreservedParam bug
   fix (#632)") newly activates handling for callee-saved registers R19-R29 that was
   previously dead code (due to a bug); the `CalleePreservedParam` transform drops
   the explicit call-site definition for a preserved register in favor of an
   `Assert(input == output)` equality, without inserting a real IR def — if nothing
   downstream re-establishes one, `ReadUninitialised`'s single-pass (non-fixpoint)
   check can see the later read as undefined. **Unconfirmed** — worth testing against
   a BASIL build from just before `4efcd277` to verify. This is the dominant failure
   mode in every variant: **100% of `gcc_O0` (573/573), `gcc_O2` (414/414), and
   `gcc_O2_fwrapv` (417/417)** basil-stage failures, 573/575 (99.7%) of `clang_O0`'s,
   and 683/966 (70.7%) of `clang_O2`'s.
2. **`IntervalDSA.globalIntervals` assertion — `clang_O2`-specific.** An assertion in
   `src/main/scala/analysis/data_structure_analysis/IntervalDSA.scala:1533`
   (`globalIntervals`) accounts for 272/966 (28.2%) of `clang_O2`'s basil-stage
   failures, and does not occur even once across every other variant's failure logs
   — i.e. this isn't a general BASIL bug, it's specific to something in `clang -O2`'s
   codegen (vectorization, addressing-mode selection, and jump tables are the likely
   suspects) interacting badly with BASIL's data-structure analysis
   (`--dsa= --dsa-split --dsa-checks`). This area has had a cluster of recent bug-fix
   commits (`interval-dsa-recursion-fix`, `interval-dsa-bounds-check-fix`,
   `dsa-ssc-fixes`, PRs #428/#612/#613), consistent with `clang_O2` still having
   unresolved edge cases — and is the main reason `clang_O2`'s pass rate (346/1314,
   26%) sits so far below every other variant (56-68%).

## Running a benchmark through UAutomizer directly (source-level, no `-D__BASIL__`)

**Do not feed the raw `.c` file (with `#include "verification.h"`/`-include verification.h`)
directly to `Ultimate.py`.** Ultimate's CDT-based C front end does not support `#ifdef`/`#endif`
at all — it either aborts with `PreprocessorHandler: Not yet implemented: #ifdef __BASIL__`
(reported as `UnsupportedSyntaxResult`, toolchain returns no result) or crashes outright with
a `NullPointerException` in `CDTParser.decorateTranslationUnits`, depending on the surrounding
content. Since `Ultimate.py`'s CLI has no flag for extra preprocessor defines/includes anyway
(`--help` only offers `--file`/`--spec`/`--architecture`/etc.), the fix is to run the benchmark
through a real preprocessor first, **without** `-D__BASIL__`, so the `#ifdef __BASIL__` block
is properly stripped and UAutomizer's own native `__VERIFIER_*` models take over for those calls:

```bash
# -I is needed because many benchmark files themselves have their own
# #include "seahorn/seahorn.h" line
gcc -E -P -I include -include include/verification.h test/demo/34/34.c -o 34.preprocessed.c

cd /path/to/UAutomizer-linux
./Ultimate.py --file /path/to/34.preprocessed.c --spec examples/unreach-call.prp --architecture 64bit
```

This has been verified working (correct `TRUE`/SAFE verdicts) on `test/demo/34/34.c` and a
synthetic `exit`-from-non-`main` test case, using `gcc -E -P` to preprocess. `clang -E -P`
(same flags) has also been verified directly: its output is identical to gcc's modulo
whitespace, and feeding it to `Ultimate.py` produces the same correct `TRUE` verdict.
