// Source: data/benchmarks/accelerating_invariant_generation/dagger/bk-nat.c
#include <stdlib.h>
#define assume(e)                                                              \
  if (!(e))                                                                    \
    exit(-1);
int my_nondet;
int __attribute__((noinline)) my_unknown() { return my_nondet; }
void __attribute__((noinline)) my_assert(int x) {}
int invalid;
int unowned;
int nonexclusive;
int exclusive;
extern int unknown_int(void);
int nondet_int();
int main() {
  ;
  ;
  ;
  ;
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
