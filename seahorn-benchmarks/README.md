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
