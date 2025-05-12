// Source:
// data/benchmarks/LinearArbitrary-SeaHorn/VeriMAP/TRACER-testloop2_VeriMAP_true.c
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
void errorFn() {
ERROR:
  goto ERROR;
}
void main() {
  int NONDET = (int)my_unknown();
  int i = (int)my_unknown(), N = (int)my_unknown();
  int a = (int)my_unknown();
  int x = (int)my_unknown();
  if (my_unknown() > 0)
    x = 1;
  else
    x = 2;
  while (i < N) {
    i = i + 1;
  }
  {
    ;
    my_assert((!(x > 2)));
  }
  return;
  ;
}
