// Source: data/benchmarks/sv-benchmarks/loop-zilu/benchmark51_polynomial.c
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
#include <assert.h>
int main() {
  int x = my_unknown();
  if (!((x >= 0) && (x <= 50)))
    return 0;
  ;
  while (my_unknown()) {
    if (x > 50)
      x++;
    if (x == 0) {
      x++;
    } else
      x--;
  }
  {
    ;
    my_assert(((x >= 0) && (x <= 50)));
  }
  return 0;
  ;
}
