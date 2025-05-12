// Source: data/benchmarks/sv-benchmarks/loop-new/gauss_sum.c
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
extern int unknown_int(void);
int main() {
  int n = (int)my_unknown(), sum = (int)my_unknown(), i = (int)my_unknown();
  n = my_unknown();
  if (!(1 <= n && n <= 1000))
    return 0;
  ;
  sum = 0;
  for (i = 1; i <= n; i++) {
    sum = sum + i;
  }
  {
    ;
    my_assert((2 * sum == n * (n + 1)));
  }
  return 0;
  ;
}
