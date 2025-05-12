// Source:
// data/benchmarks/sv-benchmarks/loop-invariants/linear-inequality-inv-a.c
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
extern unsigned char unknown_uchar(void);
int main() {
  unsigned char n = my_unknown();
  if (n == 0) {
    return 0;
    ;
  }
  unsigned char v = 0;
  unsigned int s = 0;
  unsigned int i = 0;
  while (i < n) {
    v = my_unknown();
    s += v;
    ++i;
  }
  if (s < v) {
    {
      ;
      my_assert((0));
    };
    return 1;
    ;
  }
  if (s > 65025) {
    {
      ;
      my_assert((0));
    };
    return 1;
    ;
  }
  return 0;
  ;
}
