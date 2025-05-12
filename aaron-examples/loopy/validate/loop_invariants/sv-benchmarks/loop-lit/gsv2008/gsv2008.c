// Source: data/benchmarks/sv-benchmarks/loop-lit/gsv2008.c
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
#define LARGE_INT 1000000
extern int unknown_int(void);
int main() {
  int x = (int)my_unknown(), y = (int)my_unknown();
  x = -50;
  y = my_unknown();
  if (!(-1000 < y && y < LARGE_INT))
    return 0;
  ;
  while (x < 0) {
    x = x + y;
    y++;
  }
  {
    ;
    my_assert((y > 0));
  }
  return 0;
  ;
}
