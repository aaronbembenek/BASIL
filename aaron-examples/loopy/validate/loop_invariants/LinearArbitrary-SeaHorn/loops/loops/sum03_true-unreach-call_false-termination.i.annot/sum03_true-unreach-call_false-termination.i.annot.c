// Source:
// data/benchmarks/LinearArbitrary-SeaHorn/loops/loops/sum03_true-unreach-call_false-termination.i.annot.c
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
int main() {
  int sn = 0;
  unsigned int loop1 = my_unknown(), n1 = my_unknown();
  unsigned int x = 0;
  while (x < 1000000) {
    sn = sn + (2);
    x++;
    {
      ;
      my_assert((sn == x * (2) || sn == 0));
    }
  }
}
