// Source: data/benchmarks/accelerating_invariant_generation/cav/05.c
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
int unknown1() {
  int x = (int)my_unknown();
  return x;
  ;
}
int unknown2();
int unknown3();
int unknown4();
void main() {
  int flag = my_unknown();
  int x = 0;
  int y = 0;
  int j = 0;
  int i = 0;
  while (my_unknown()) {
    x++;
    y++;
    i += x;
    j += y;
    if (flag)
      j += 1;
    j = j;
  }
  if (j <= i - 1) {
    goto ERROR;
    {
    ERROR: {
      ;
      my_assert((0));
    }
    }
  }
}
