// Source: data/benchmarks/sv-benchmarks/loop-lit/css2003.c
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
  int i = (int)my_unknown(), j = (int)my_unknown(), k = (int)my_unknown();
  i = 1;
  j = 1;
  k = my_unknown();
  if (!(0 <= k && k <= 1))
    return 0;
  ;
  while (i < LARGE_INT) {
    i = i + 1;
    j = j + k;
    k = k - 1;
    {
      ;
      my_assert((1 <= i + k && i + k <= 2 && i >= 1));
    }
  }
  return 0;
  ;
}
