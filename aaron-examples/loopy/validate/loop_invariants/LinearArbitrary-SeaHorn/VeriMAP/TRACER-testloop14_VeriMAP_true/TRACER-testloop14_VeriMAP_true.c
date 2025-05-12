// Source:
// data/benchmarks/LinearArbitrary-SeaHorn/VeriMAP/TRACER-testloop14_VeriMAP_true.c
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
extern unsigned int unknown_uint(void);
void errorFn() {
ERROR:
  goto ERROR;
}
int main() {
  int i = (int)my_unknown(), x = (int)my_unknown(), y = (int)my_unknown();
  x = my_unknown();
  y = my_unknown();
  if (y <= 2) {
    if (x < 0) {
      x = 0;
    }
    i = 0;
    while (i < 10) {
      {
        ;
        my_assert((!(y > 2)));
      }
      i++;
    }
    {
      ;
      my_assert((!(x <= -1)));
    }
  }
  return 0;
  ;
}
