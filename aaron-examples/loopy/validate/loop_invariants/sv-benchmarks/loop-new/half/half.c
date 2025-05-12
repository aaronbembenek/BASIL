// Source: data/benchmarks/sv-benchmarks/loop-new/half.c
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
  int i = 0;
  int n = 0;
  int k = my_unknown();
  if (!(k <= LARGE_INT && k >= -LARGE_INT))
    return 0;
  ;
  for (i = 0; i < 2 * k; i++) {
    if (i % 2 == 0) {
      n++;
    }
  }
  {
    ;
    my_assert((k < 0 || n == k));
  }
  return 0;
  ;
}
