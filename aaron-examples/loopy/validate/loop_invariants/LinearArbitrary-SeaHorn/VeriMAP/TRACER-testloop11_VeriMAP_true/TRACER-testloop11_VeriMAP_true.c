// Source:
// data/benchmarks/LinearArbitrary-SeaHorn/VeriMAP/TRACER-testloop11_VeriMAP_true.c
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
extern int unknown(void);
int unknown() {
  int x = (int)my_unknown();
  return x;
  ;
}
void errorFn() {
ERROR:
  goto ERROR;
}
void main() {
  int e = (int)my_unknown(), s = (int)my_unknown();
  e = 0;
  s = 2;
  while (my_unknown()) {
    if (s == 2) {
      if (e == 0)
        e = 1;
      s = 3;
    } else if (s == 3) {
      if (e == 1)
        e = 2;
      s = 4;
    } else if (s == 4) {
      {
        ;
        my_assert((!(e == 3)));
      }
      s = 5;
    }
  }
  return;
  ;
}
