// Source: data/benchmarks/sv-benchmarks/loop-zilu/benchmark21_disjunctive.c
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
#include <assert.h>
int main() {
  int x = my_unknown();
  int y = my_unknown();
  if (!(y > 0 || x > 0))
    return 0;
  ;
  while (1) {
    if (x + y > -2) {
      break;
    }
    if (x > 0) {
      x++;
    } else {
      y++;
    }
  }
  {
    ;
    my_assert((x > 0 || y > 0));
  }
  return 0;
  ;
}
