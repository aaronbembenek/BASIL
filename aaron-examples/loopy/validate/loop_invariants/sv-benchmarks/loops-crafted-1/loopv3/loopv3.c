// Source: data/benchmarks/sv-benchmarks/loops-crafted-1/loopv3.c
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
int SIZE = 50000001;
int main() {
  int i = (int)my_unknown(), j = (int)my_unknown();
  i = 0;
  j = 0;
  while (i < SIZE) {
    if (my_unknown())
      i = i + 8;
    else
      i = i + 4;
  }
  j = i / 4;
  {
    ;
    my_assert(((j * 4) == i));
  }
  return 0;
  ;
}
