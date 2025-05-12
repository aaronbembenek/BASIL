// Source: data/benchmarks/LinearArbitrary-SeaHorn/pie/ICE/benchmarks/form22.c
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
  int x1 = (int)my_unknown(), x2 = (int)my_unknown(), x3 = (int)my_unknown();
  int x1p = (int)my_unknown(), x2p = (int)my_unknown(), x3p = (int)my_unknown(),
      input = (int)my_unknown();
  x1 = x2 = x3 = 0;
  input = my_unknown();
  while (input) {
    x1p = my_unknown();
    x2p = my_unknown();
    x3p = my_unknown();
    if (x1p <= x2p && (x2p >= 0 || x2p - x3p <= 2)) {
      x1 = x1p;
      x2 = x2p;
      x3 = x3p;
    }
    input = my_unknown();
  }
  {
    ;
    my_assert((x1 <= x2 && (x2 >= 0 || x2 - x3 <= 2)));
  }
}
