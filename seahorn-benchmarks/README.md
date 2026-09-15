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
   | `test/c/pie/ICE/benchmarks/veris.c_sendmail__tTflag_arr_one_loop_safe/` (itself later removed; see item 4 below) | `test/c/pie/ICE/benchmarks/vsend/` |
   | `test/c/pie/ICE/benchmarks/trex03_safe/` | `test/c/pie/ICE/benchmarks/trex03/` |
   | `test/c/recursions/recursive/Fibonacci01_true-unreach-call_true-no-overflow/` | `test/demo/fibo/` |
   | `test/demo/19/` | `test/demo/28/` |

2. **Preprocessed** (`gcc -E -P -I include -include include/verification.h`, then
   hash the output) — more precise than a raw hash since it's insensitive to
   comments/whitespace/leftover line-marker text while still being an exact,
   deterministic comparison (no fuzzy matching). Found 5 further pairs whose raw
   source differed only in such cosmetic content:

   | kept | removed | raw source differed only by |
   |---|---|---|
   | `test/c/pie/ICE/benchmarks/sum04_safe/` | `test/c/pie/ICE/benchmarks/sum04/` | a commented-out `// #define a (2)` line |
   | `test/c/VeriMAP/TRACER-testabs7_VeriMAP_true/` | `test/c/VeriMAP/TRACER-testabs13_VeriMAP_true/` | embedded `# N "....tmp.c"` line-marker comments |
   | `test/c/VeriMAP/TRACER-testabs3_VeriMAP_true/` | `test/c/VeriMAP/TRACER-testwp4_VeriMAP_true/` | embedded `# N "....tmp.c"` line-marker comments |
   | `test/c/VeriMAP/TRACER-testabs1_VeriMAP_true/` | `test/c/VeriMAP/TRACER-testabs6_VeriMAP_true/` | embedded `# N "....tmp.c"` line-marker comments |
   | `test/c/pie/hola/04/` | `test/demo/08/` | an attribution comment (`Taken from Gulwani PLDI'08: Program Analysis as Constraint Solving`) and a trailing newline |

   Note: the `hola/04`/`demo/08` pair was missed by the original pass above and was
   only caught on a later re-run of this same check — the pair existed since the
   corpus's initial commit, so it isn't a duplicate introduced by any later addition
   to the benchmark set. `demo/08` succeeded on all 5 compile variants and the
   `basil` stage, so its removal simply reduces every success count in "Current
   results" below by 1 (the "Current results" numbers already reflect its removal).

   Note: this corpus (particularly `c/VeriMAP` and `c/pie`) also contains many
   benchmarks that are deliberately *near*-identical but not true duplicates (e.g.
   safe/unsafe variants differing by one planted line, with different expected
   verdicts) — a fuzzy/similarity-based duplicate check would flag many of these as
   false positives, which is why only exact (raw or preprocessed) hash matches were
   treated as redundant here.

3. **Compiled `.text`** (`aarch64-linux-gnu-objcopy -O binary --only-section=.text`
   on the `gcc -O0` build of each benchmark, then hash the extracted bytes) — catches
   duplicates that differ only in ways `-O0` codegen normalizes away (macro vs. literal
   use of the same constant, calling one nondet-alias macro vs. another that expands to
   the same function, declaration order/style, dead/no-op code), which the preprocessed-
   source hash above does not. Every one of the 13 raw hash-matches this pass found was
   manually diffed at the source level before removing anything, since binary identity
   doesn't always imply the pair is redundant for every tool (see the note below). 11
   were confirmed as cosmetic-only duplicates and removed:

   | kept | removed | raw source differed only by |
   |---|---|---|
   | `test/c/invgen/nested5/` | `test/c/pie/hola/24/` | a header/attribution comment; identical `tmpl(...)` logic |
   | `test/c/loops/loop-invgen/sendmail-close-angle_true-unreach-call_true-termination/` | `test/c/invgen/sendmail-close-angle/` | dead commented-out historical code/annotations; live statements identical after macro expansion (`unknown()`/`sassert()` vs. their direct `__VERIFIER_*` expansions) |
   | `test/c/loops/loops/trex03_true-unreach-call.i.annot/` | `test/c/pie/ICE/benchmarks/trex03_safe/` (itself the earlier survivor of the byte-for-byte pass above) | `/*@ predicates{...} @*/` CEGAR-template annotations present only in the kept copy; asserted property unchanged |
   | `test/c/pie/ICE/benchmarks/dtuc/` | `test/c/pie/ICE/benchmarks/dutc/` | calls `unknown()` vs. `__VERIFIER_nondet_int()` directly — same macro, different alias |
   | `test/c/pie/ICE/benchmarks/sum01_safe/` | `test/c/pie/ICE/benchmarks/sum01/` | `#define a (1)` then `n*a` vs. a literal `n*1`/`n` — algebraically identical |
   | `test/c/pie/ICE/benchmarks/sum01_safe.v/` | `test/c/pie/ICE/benchmarks/sum01.v/` | same `a=1` macro-vs-literal pattern as above |
   | `test/c/pie/ICE/benchmarks/trex03_safe.v/` | `test/c/pie/ICE/benchmarks/trex03.v/` | a declaration-order swap with no semantic content |
   | `test/c/pie/hola/37/` | `test/demo/11/` | an attribution comment (`Taken from "Counterexample Driven Refinement for Abstract Interpretation" (TACAS'06) by Gulavani`) and `unknown2()` vs. `unknown1()` — both alias `__VERIFIER_nondet_int()` |
   | `test/demo/23/` | `test/demo/31/` | two declaration statements merged into one comma-declaration |
   | `test/sv-benchmarks/systemc/token_ring.12_.../` | `test/sv-benchmarks/systemc/token_ring.14_.../` | an extra `if (a<=5) { if (a>=5) {} }` with a completely empty body — dead code |
   | `test/sv-benchmarks/systemc/token_ring.13_.../` | `test/sv-benchmarks/systemc/token_ring.15_.../` | the same empty-body dead-code pattern |

   **2 of the 13 raw matches were *not* removed**, despite hashing identically:
   `test/c/loops/loops/for_infinite_loop_1..._true-unreach-call_false-termination.i.annot/`
   vs. `for_infinite_loop_2.../`, and the `while_infinite_loop_1`/`_2` pair. Both pairs'
   source contains a genuinely different assertion (`__VERIFIER_assert(x == 0)` vs.
   `__VERIFIER_assert(x != 0)`) — they only compile to identical `.text` because the
   loop in question is provably infinite (per the benchmarks' own `_false-termination`
   naming), so gcc treats the differing assert as unreachable dead code either way. This
   is a deliberate SV-COMP test pattern (does a tool correctly avoid reporting an error
   it can never reach, regardless of what that error checks), not accidental
   duplication — a source-level tool that doesn't establish non-termination up front, or
   that inspects the assert condition directly, could legitimately treat the two
   differently, so compiled-binary identity alone isn't sufficient grounds for removal.

4. **Manual source review** — found 1 further pair that none of the hash checks above
   could catch, because the removed copy is an *incorrect* version of the kept one
   rather than a cosmetic variant of it:

   | kept | removed | raw source differed only by |
   |---|---|---|
   | `test/c/pie/ICE/benchmarks/vsend.v/` (itself later removed; arrays out of scope — see "Benchmarks removed (arrays out of scope)" below) | `test/c/pie/ICE/benchmarks/veris.c_sendmail__tTflag_arr_one_loop_safe/` | no nondet fill loop for `char in[11]`, so the digit-parsing loop reads uninitialized elements; no unused `v1..v3` `__VERIFIER_nondet_int()` calls; an unused `__VERIFIER_assert1` helper calling `__VERIFIER_error()` instead of looping on `goto ERROR` |

   Note: the originally committed `vsend.v.c` had the same missing-initialization bug; it
   was fixed there (see the "Uninitialized variables" and "Out-of-bounds fill loop" items
   under "Compile-stage fixes" below), but the `veris` copy never got that fix, since
   `-Werror=uninitialized` doesn't flag reads of uninitialized array elements. (`vsend.v`
   itself was subsequently removed as well, since it uses an array; see "Benchmarks
   removed (arrays out of scope)" below.) The
   `veris` benchmark succeeded on all 5 compile variants and the `basil` stage, so its
   removal simply reduces every success count in "Current results" below by 1 (the
   "Current results" numbers already reflect its removal).

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
  `fig1.v.c`, `vsend.v.c` (benchmark since removed; see "Benchmarks removed (arrays out of
  scope)"), `04.c`: a `unknown()`/`__VERIFIER_nondet_*` initializer was
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
- **Out-of-bounds fill loop** — `c/pie/ICE/benchmarks/vsend.v/vsend.v.c` (benchmark since
  removed; see "Benchmarks removed (arrays out of scope)"): a loop meant
  to nondet-fill `char in[11]` wrote to the constant index `in[11]` (one past the end,
  and never touching `in[0..10]`) instead of `in[i]`.

### Disabled allocations that stored through NULL (`product-lines`)

All 597 `sv-benchmarks/product-lines` benchmarks have two CIL-generated functions whose
`malloc` was disabled — `__utac__exception__cf_handler_set` (`malloc(24UL)`) and
`__utac__error_stack_mgt` (`malloc(16UL)`). Both were left as `tmp = 0;` and then store
through `tmp`, which is a guaranteed NULL store.

This compiled fine but broke the binary pipeline. `clang -O2` proves the store in
`__utac__exception__cf_handler_set` is unconditionally undefined, folds the entire body
to `unreachable`, and emits a **zero-size** `FUNC` symbol whose `st_value` lands on the
start of the next live function. That tripped BASIL in two places at once: `ddisasm`
never registered a function for the bodyless symbol, so `getFunctionEntries` threw
`NoSuchElementException`; and once that was worked around, the zero-width interval
collided with its neighbour in `IntervalDSA.globalIntervals`. `gcc -O2` doesn't exploit
the UB, which is why the failure was `clang_O2`-only.

Both functions are **dead** — zero call sites anywhere in the corpus, and their addresses
are never taken — so the undefined behaviour was unreachable and only ever mattered to
codegen. Each file now declares `static unsigned long __basil_dead_alloc[4];` (32B,
8-byte aligned; covers the 24B and 16B uses) and points both sites at it. Since the
functions are unreachable, BASIL strips them before analysis and the buffer never
reaches the memory-region analysis — verified: it appears nowhere in the generated
`.bpl`, and the resulting CHCs contain no array-sorted variables, `select`s or `store`s.

## Benchmarks removed (no loop or recursion)

Loop-free, recursion-free C produces an **acyclic** Horn-clause system: solvable by
inlining every clause into one formula and making a single SMT call, with no
fixed-point/invariant inference required — i.e. these don't exercise the capability
CHC solving exists to test. Benchmarks with neither a loop nor recursion were
therefore removed:

- `dagger/ex2.c` and `c/VeriMAP/TRACER-test1-unsafe_VeriMAP_false/`: bounded case-split
  programs.
- 29 more VeriMAP `TRACER` programs, all small branch-only programs:
  `c/VeriMAP/TRACER-<name>_VeriMAP_true/` for `test1`, `test3`, `testabs1`, `testabs2`,
  `testabs3`, `testabs9`, `testfunc1`, `testfunc3`, `testfunc11`, `testwp2`, `testwp3`,
  `testwp5`, `testwp6`, `testwp7`, `testwp8`, `testwp9`, `testwp10`, `testwp11`,
  `testwp12`, `testwp14`, `testwp15`, `testwp16` and `testwp17`, and
  `c/VeriMAP/TRACER-<name>-unsafe_VeriMAP_false/` for `test3`, `testfunc1`, `testfunc9`,
  `testfunc12`, `testwp1` and `testwp13`.

The first two were found with an earlier, lightweight check (`for`/`while`/`do`
keywords, backward `goto`, and call-graph cycles). It missed the 29 `TRACER` programs
because every one of them defines an unused `errorFn() { ERROR: goto ERROR; }` (and
`testwp14` an unused `__VERIFIER_assume1` with a `goto LOOP`), whose backward `goto`
counted as a loop even though it is dead code.

The check is now `scripts/check_benchmarks.py`, which only considers code reachable from
`main`. It parses each benchmark with clang (with the same preprocessor setup as the
build), builds the call graph from `main` over live code, and reports, per benchmark,
whether live code has a loop (`while`/`do`/`for` or a backward `goto`), whether live
functions are recursive (including mutual recursion, e.g. `isEven`/`isOdd`), and whether
a call to `__VERIFIER_error` is reachable (see below). Dead code is what clang's
`-Wunreachable-code` reports, plus code after a `return`/`goto`/`break`/`continue` or in
a constant-false `if` branch that no live `goto` can jump into; see the script's
docstring for the details and limitations. Run over the whole corpus after the removals
here, it reports no benchmark without a loop or recursion, and none without an assertion.

## Benchmarks removed (no reachable assertion)

A benchmark whose error call can never be reached has no property to verify, so any
verdict for it is vacuous:

- `c/invgen/puzzle1/` contains no assertion at all (its `assert.h` include is commented
  out). It does contain signed integer overflow, but that is a different property
  (no-overflow) from the error reachability this suite checks.
- `sv-benchmarks/psyco/psyco_math_1_true-unreach-call/` only calls `__VERIFIER_error()`
  at an `ERROR:` label after `return 0;`, and all 19 `goto ERROR;` statements are inside
  CIL's `if (0) { ... }` non-conformance blocks.

Two benchmarks with a similar shape are kept. `sv-benchmarks/psyco/psyco_io_1_true-unreach-call/`
also has its `ERROR:` label after `return 0;`, but 6 of its 18 `goto ERROR;` statements
are guarded by real state conditions, so the property is genuine (it is safe only because
those paths are infeasible). `c/llreve/loop4_merged_safe/` asserts only after a
`while (1)` loop with no `break`, which `scripts/check_benchmarks.py` reports as an
unreachable assertion; it is kept for the same reason as the `for_infinite_loop` and
`while_infinite_loop` pairs under "Duplicate benchmarks" above (a deliberate SV-COMP test
that a tool doesn't report an error it can never reach).

## Benchmarks removed (incorrect expected verdict)

`c/VeriMAP/TRACER-testloop5-unsafe_VeriMAP_false/` is labelled unsafe, but as written it
is safe: in `while (foo(i) < 10) {}`, `i` is never updated (`foo(0)` always returns 1),
so the loop never terminates and the assertion after it is unreachable.

## Benchmarks removed (arrays out of scope)

`c/pie/ICE/benchmarks/vsend.v/` was removed because it uses an array (`char in[11]`,
filled with nondeterministic values and then read), and arrays are out of scope for
this suite.

This came up through gcc's stack protector. Ubuntu's `aarch64-linux-gnu-gcc` enables
`-fstack-protector-strong` by default (clang-14 does not), which instruments any
function with a local array with a stack-canary check that calls glibc's
`__stack_chk_fail` on a mismatch. That function has no code in the binary, so BASIL
lifts it as a body-less `procedure p$__stack_chk_fail();`, which BASIL-infer's CHC
translation does not support. In the other benchmarks where this happened, the array
played no role in the verified property, so the array was commented out instead of
removing the benchmark:

- `c/pie/ICE/benchmarks/n_c11/`, `n_c11n/`, `n_c11n.v/`: `int a[5];` was declared but
  never used.
- `c/pie/ICE/benchmarks/ex14/`: `int a[10];` was only ever written (`a[y] = -1;`, now
  also commented out) and never read; the bounds check on `y` that guarded the write is
  kept.

After the change, all 5 variants of each of these 4 benchmarks were rebuilt and still
succeed; none of the new builds reference `__stack_chk_fail` or contain a body-less
procedure. `vsend.v` succeeded on all 5 compile variants and the `basil` stage, so its
removal simply reduces every success count in "Current results" below by 1 (the
"Current results" numbers already reflect its removal).

Separately, `c/pie/ICE/benchmarks/ex23/` and `ex23.v/` declare a global `int x[4608];`
that is only ever written (`x[z] = 0;`) and never read — the property only checks that
`z` stays in bounds. Being a global, it doesn't trigger the stack protector, but the
write made the CHCs of their `-O0` builds use arrays (which BASIL-infer's CHC translation
rejects), so the declaration and the write were commented out in both; the bounds check
on `z` is kept. As a side effect, their 6 `-O2` builds, which previously failed at the
`basil` stage in `IntervalDSA.checkMemoryAccesses` on that write, now succeed too (the
"Current results" numbers below already reflect this).

## Benchmarks omitted (not in verification-friendly form)

This suite was extended with **124 benchmarks recovered from the upstream
[LinearArbitrary-SeaHorn](https://github.com/GaloisInc/LinearArbitrary-SeaHorn) repository**
that were absent here (after excluding files already present under a `.i`→`.c` rename, the
duplicates documented above, and the loop-free programs documented above).

A further **20 candidates were omitted because they do not compile.** In every case the blocker
is in the benchmark source itself — a missing dependency that upstream never shipped — not in
BASIL or in this pipeline:

| Cause | Files | Detail |
|---|---|---|
| Unimplemented kernel APIs | 14 | All of `sv-benchmarks/ntdrivers` plus 4 driver benchmarks in `sv-benchmarks/misc`. They call Windows WDM entry points (`MmProbeAndLockPages`, `KfAcquireSpinLock`, `InterlockedExchange`, `IoAcquireCancelSpinLock`, …) or Linux kernel ones (`__kmalloc`, `dev_get_drvdata`, `platform_driver_register`, …) that are declared but defined nowhere. Written to be fed to a static analyzer that treats them as opaque externals; they were never meant to link. |
| busybox-derived utilities | 5 | `chmod`, `cp-incomplete`, `mkdir`, `uudecode`, `yes`. Each has `#include <stdarg.h>` commented out while still calling `va_start`/`va_end`, so those become undefined symbols; `chmod` additionally uses `__type_of__`, which is not standard C. Each also builds `argv` dynamically via `malloc((argc+1)*sizeof(char*))`. |
| Incomplete upstream source | 1 | `fragtest.c` calls `rand_shuffle`, which is defined nowhere in the upstream repository — it appears to have been extracted from a larger multi-file test without its companion source. |

**What this does and does not tell us.** Because these programs fail before they produce a
binary, they never reach BASIL at all — so this says *nothing* about whether BASIL could verify
them. It is not evidence that they would have worked, and it is not evidence that they would
have failed. Several would plausibly be hard: the busybox utilities construct `argv` with a
nondeterministically-sized allocation and then index it at a nondeterministic offset, which is
the kind of code the interval DSA already struggles with elsewhere in this corpus. But that is
an untested conjecture — we simply cannot run the experiment on these inputs.

Getting them to compile would mean fabricating source upstream never provided (a `rand_shuffle`
implementation) or writing substantial fake kernel-model stub libraries for two different
kernels, either of which would change what the benchmark actually verifies. We judged that a
worse outcome than omitting them, having made a good-faith effort to recreate the original
suite. Per-benchmark evidence, including the investigation of each failure, is recorded in
[`BACKFILL_FAILURES.md`](BACKFILL_FAILURES.md).

One backfilled benchmark is deliberately **kept** despite failing: `mochi/McCarthy9103` compiles
under all 5 variants and fails only at the `basil` stage on the two `-O0` variants, via the
already-known `IntervalGraph.localCorrectness` DSA assertion. That is a BASIL limitation, not a
benchmark defect, so it belongs in the suite alongside the other benchmarks that surface real
bugs.

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

## Current results and remaining BASIL bugs

These numbers are measured against this branch, whose `src/` is byte-identical to BASIL
commit `de7f516d`. `preprocess` and all 5 compile variants succeed 100% of the time;
every remaining failure is BASIL itself crashing during the `basil` (`java -jar ...`)
stage, not a benchmark or compiler problem.

Measured over all **1392** benchmarks (1268 original + 124 recovered from upstream, per
"Benchmarks omitted" above).

| Variant | Succeeds |
|---|---|
| `gcc_O0` | 1351/1392 (97%) |
| `clang_O0` | 1353/1392 (97%) |
| `gcc_O2` | 1275/1392 (92%) |
| `gcc_O2_fwrapv` | 1273/1392 (91%) |
| `clang_O2` | 1309/1392 (94%) |
| **total** | **6561/6960 (94%)** |

### The remaining 399 failures are almost entirely one subsystem

**372 of 399 (93%) are in the interval data-structure analysis** (`--dsa= --dsa-split
--dsa-checks`), concentrated in a few assertions:

| Site | Count |
|---|---|
| `IntervalDSA.checkMemoryAccesses` | 288 |
| `IntervalGraph.localCorrectness` | 67 |
| `SymValues.exprToSymValSet` (`NotImplementedError`) | 11 |
| `IntervalNode.clone`, `resolveGlobalOverlapping` | 5 |

The remaining 27 are scattered: `ir.CallGraph.pred` (9), `ReplaceReturn`'s
`establishProcedureDiamondForm` (8), 11 `StackOverflowError`s from deep recursion, and 4
timeouts. By category the failures sit mostly in `sv-benchmarks/product-lines` (231),
`c/recursions/recursive-simple` (61) and `sv-benchmarks/systemc` (54) — i.e. recursion-
and struct-heavy code, which is consistent with a DSA-side limitation rather than many
unrelated bugs.

The backfill contributed only 2 of the 399 failures — both `mochi/McCarthy9103`
(`IntervalGraph.localCorrectness`, `-O0` variants only), which is why that row moved from 65 to
67. Every other recovered benchmark passes all 6 jobs.

### Note on BASIL version

An earlier revision of this document described two dominant failure modes — a spurious
`readUninitialised` R29 assertion in `SimplifyPipeline`, and an
`IntervalDSA.globalIntervals` overlap assertion. **Neither can occur on this branch.**
The `readUninitialised` check is introduced by upstream commit `9545402e` ("Translation
validator"), and the R29 behaviour that trips it by `4efcd277` ("CalleePreservedParam bug
fix"); both post-date `de7f516d` and are not present here. The `globalIntervals`
collision was real but was caused by the benchmark-side NULL-store UB documented above,
and is fixed at the source rather than in BASIL.

If you move this branch forward onto a newer BASIL, expect those failure modes to
reappear — the R29 one alone accounted for over a thousand failures, and
`--assert-callee-saved never` does **not** suppress it (verified: identical failure with
and without the flag).

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
