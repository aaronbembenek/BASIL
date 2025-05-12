// Source:
// data/benchmarks/LinearArbitrary-SeaHorn/pie/ICE/benchmarks/trex03_safe.v.c
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
extern unsigned int unknown_uint(void);
extern _Bool unknown_bool(void);
int main() {
  unsigned int x1 = my_unknown(), x2 = my_unknown(), x3 = my_unknown();
  unsigned int d1 = 1, d2 = 1, d3 = 1;
  _Bool c1 = my_unknown(), c2 = my_unknown();
  int v1 = (int)my_unknown(), v2 = (int)my_unknown(), v3 = (int)my_unknown();
  while (x1 > 0 && x2 > 0 && x3 > 0) {
    if (c1)
      x1 = x1 - d1;
    else if (c2)
      x2 = x2 - d2;
    else
      x3 = x3 - d3;
    c1 = my_unknown();
    c2 = my_unknown();
    v1 = my_unknown();
    v2 = my_unknown();
    v3 = my_unknown();
  }
  {
    ;
    my_assert((x1 == 0 || x2 == 0 || x3 == 0));
  }
  return 0;
  ;
}
