// Source: data/benchmarks/code2inv/71.c
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
extern int unknown(void);
int main() {
  int c = (int)my_unknown();
  int y = (int)my_unknown();
  int z = (int)my_unknown();
  (c = 0);
  assume((y >= 0));
  assume((y >= 127));
  (z = (36 * y));
  while (my_unknown()) {
    if ((c < 36)) {
      (z = (z + 1));
      (c = (c + 1));
    }
  }
  if ((c < 36)) {
    ;
    my_assert(((z >= 0)));
  }
}
