// Source:
// data/benchmarks/LinearArbitrary-SeaHorn/loops/loops/terminator_02_true-unreach-call_true-termination.i.annot.c
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
extern _Bool unknown_bool(void);
int main() {
  int x = my_unknown();
  int y = my_unknown();
  int z = my_unknown();
  assume(x < 100);
  assume(x > -100);
  assume(z < 100);
  assume(z > -100);
  while (x < 100 && 100 < z) {
    int tmp = my_unknown();
    if (tmp) {
      x++;
    } else {
      x--;
      z--;
    }
  }
  {
    ;
    my_assert((x >= 100 || z <= 100));
  }
  return 0;
  ;
}
