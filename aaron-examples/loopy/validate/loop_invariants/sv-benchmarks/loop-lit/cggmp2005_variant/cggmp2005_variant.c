// Source: data/benchmarks/sv-benchmarks/loop-lit/cggmp2005_variant.c
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
#define LARGE_INT 1000000
extern int unknown_int(void);
int main() {
  int lo = (int)my_unknown(), mid = (int)my_unknown(), hi = (int)my_unknown();
  lo = 0;
  mid = my_unknown();
  if (!(mid > 0 && mid <= LARGE_INT))
    return 0;
  ;
  hi = 2 * mid;
  while (mid > 0) {
    lo = lo + 1;
    hi = hi - 1;
    mid = mid - 1;
  }
  {
    ;
    my_assert((lo == hi));
  }
  return 0;
  ;
}
