// Source: data/benchmarks/LinearArbitrary-SeaHorn/pie/hola/08.c
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
extern int unknown1();
extern int unknown2();
extern int unknown3();
void main() {
  int x = 0, y = 0;
  while (my_unknown()) {
    if (my_unknown()) {
      x++;
      y += 100;
    } else if (my_unknown()) {
      if (x >= 4) {
        x++;
        y++;
      }
      if (x < 0) {
        y = -y;
      }
    }
  }
  {
    ;
    my_assert((x < 4 || y > 2));
  }
}
