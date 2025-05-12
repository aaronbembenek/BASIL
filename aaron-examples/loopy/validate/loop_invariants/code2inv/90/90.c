// Source: data/benchmarks/code2inv/90.c
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
  int lock = (int)my_unknown();
  int v1 = (int)my_unknown();
  int v2 = (int)my_unknown();
  int v3 = (int)my_unknown();
  int x = (int)my_unknown();
  int y = (int)my_unknown();
  (y = (x + 1));
  (lock = 0);
  while ((x != y)) {
    {
      if (my_unknown()) {
        {
          (lock = 1);
          (x = y);
        }
      } else {
        {
          (lock = 0);
          (x = y);
          (y = (y + 1));
        }
      }
    }
  }
  {
    ;
    my_assert(((lock == 1)));
  }
}
