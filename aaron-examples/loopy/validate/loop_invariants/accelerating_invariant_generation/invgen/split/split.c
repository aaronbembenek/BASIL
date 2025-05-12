// Source: data/benchmarks/accelerating_invariant_generation/invgen/split.c
#include <stdlib.h>
#define assume(e)                                                              \
  if (!(e))                                                                    \
    exit(-1);
#ifdef __BASIL__
int __attribute__((noinline)) my_unknown() { return rand(); }
void __attribute__((noinline)) my_assert(int x) {
  while (!x)
    ;
}
#else
extern void __assert_fail(const char *, const char *, unsigned int,
                          const char *) __attribute__((__nothrow__, __leaf__))
__attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "benchmark", 3, "reach_error"); }

extern int __VERIFIER_nondet_int();
void __VERIFIER_assert(int cond) {
  if (!(cond))
  ERROR: {
    reach_error();
    abort();
  }
    return;
}

#define my_unknown() __VERIFIER_non_det_int()
#define my_assert(x) __VERIFIER_assert(x)
#endif
void main() {
  int k = 100;
  int b = (int)my_unknown();
  int i = (int)my_unknown();
  int j = (int)my_unknown();
  int n = (int)my_unknown();
  i = j;
  for (n = 0; n < 2 * k; n++) {
    if (b) {
      i++;
    } else {
      j++;
    }
    b = !b;
  }
  {
    ;
    my_assert((i == j));
  }
}
