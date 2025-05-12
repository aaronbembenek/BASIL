// Source: data/benchmarks/accelerating_invariant_generation/dagger/bk-nat.c
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
int nondet_int();
int main() {
  int invalid = (int)my_unknown();
  int unowned = (int)my_unknown();
  int nonexclusive = (int)my_unknown();
  int exclusive = (int)my_unknown();
  if (!(exclusive == 0))
    return 0;
  ;
  if (!(nonexclusive == 0))
    return 0;
  ;
  if (!(unowned == 0))
    return 0;
  ;
  if (!(invalid >= 1))
    return 0;
  ;
  while (my_unknown()) {
    if (my_unknown()) {
      if (!(invalid >= 1))
        return 0;
      ;
      nonexclusive = nonexclusive + exclusive;
      exclusive = 0;
      invalid = invalid - 1;
      unowned = unowned + 1;
    } else {
      if (my_unknown()) {
        if (!(nonexclusive + unowned >= 1))
          return 0;
        ;
        invalid = invalid + unowned + nonexclusive - 1;
        exclusive = exclusive + 1;
        unowned = 0;
        nonexclusive = 0;
      } else {
        if (!(invalid >= 1))
          return 0;
        ;
        unowned = 0;
        nonexclusive = 0;
        exclusive = 1;
        invalid = invalid + unowned + exclusive + nonexclusive - 1;
      }
    }
  }
  {
    ;
    my_assert((exclusive >= 0));
  }
  {
    ;
    my_assert((nonexclusive >= 0));
  }
  {
    ;
    my_assert((unowned >= 0));
  }
  {
    ;
    my_assert((invalid >= 0));
  }
  {
    ;
    my_assert((invalid + unowned + exclusive >= 1));
  }
}
