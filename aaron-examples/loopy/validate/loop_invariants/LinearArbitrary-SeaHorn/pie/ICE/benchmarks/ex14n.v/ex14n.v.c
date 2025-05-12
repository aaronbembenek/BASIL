// Source: data/benchmarks/LinearArbitrary-SeaHorn/pie/ICE/benchmarks/ex14n.v.c
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
  int x = (int)my_unknown(), y = (int)my_unknown(), N = (int)my_unknown(),
      v1 = (int)my_unknown(), v2 = (int)my_unknown(), v3 = (int)my_unknown();
  x = 1;
  N = my_unknown();
  while (x <= N) {
    y = N - x;
    if (y < 0 || y >= N) {
      ;
      my_assert((0 == 1));
    }
    x++;
    v1 = v2;
    v2 = v3;
    v3 = v1;
  }
  return 1;
  ;
}
