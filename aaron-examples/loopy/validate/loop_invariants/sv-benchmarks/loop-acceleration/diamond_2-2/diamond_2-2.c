// Source: data/benchmarks/sv-benchmarks/loop-acceleration/diamond_2-2.c
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
extern unsigned int unknown_uint(void);
int main() {
  unsigned int x = 0;
  unsigned int y = my_unknown();
  while (x < 99) {
    if (y % 2 == 0)
      x += 2;
    else
      x++;
    if (y % 2 == 0)
      x += 2;
    else
      x -= 2;
    if (y % 2 == 0)
      x += 2;
    else
      x += 2;
    if (y % 2 == 0)
      x += 2;
    else
      x -= 2;
    if (y % 2 == 0)
      x += 2;
    else
      x += 2;
    if (y % 2 == 0)
      x += 2;
    else
      x -= 4;
    if (y % 2 == 0)
      x += 2;
    else
      x += 4;
    if (y % 2 == 0)
      x += 2;
    else
      x += 2;
    if (y % 2 == 0)
      x += 2;
    else
      x -= 4;
    if (y % 2 == 0)
      x += 2;
    else
      x -= 4;
  }
  {
    ;
    my_assert(((x % 2) == (y % 2)));
  }
}
