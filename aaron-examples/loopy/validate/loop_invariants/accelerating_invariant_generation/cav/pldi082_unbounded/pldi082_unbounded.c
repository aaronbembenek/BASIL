// Source:
// data/benchmarks/accelerating_invariant_generation/cav/pldi082_unbounded.c
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
int main() {
  int x = 0;
  int y = 0;
  int N = (int)my_unknown();
  if (N < 0)
    return 1;
  ;
  while (1) {
    if (x <= N)
      y++;
    else if (x >= N + 1)
      y--;
    else
      return 1;
    ;
    if (y < 0)
      break;
    x++;
  }
  if (N >= 0)
    if (y == -1)
      if (x >= 2 * N + 3)
        goto ERROR;
  return 1;
  ;
  {
  ERROR: {
    ;
    my_assert((0));
  }
  }
}
