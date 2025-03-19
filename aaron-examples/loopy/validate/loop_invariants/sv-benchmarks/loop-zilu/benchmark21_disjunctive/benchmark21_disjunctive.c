// Source: data/benchmarks/sv-benchmarks/loop-zilu/benchmark21_disjunctive.c
#include <stdlib.h>
#define assume(e)                                                              \
  if (!(e))                                                                    \
    exit(-1);
int my_nondet;
int __attribute__((noinline)) my_unknown() { return my_nondet; }
void __attribute__((noinline)) my_assert(int x) {}
int x;
int y;
extern int unknown_int(void);
#include <assert.h>
int main() {
  x = my_unknown();
  y = my_unknown();
  if (!(y > 0 || x > 0))
    return 0;
  ;
  while (1) {
    if (x + y > -2) {
      break;
    }
    if (x > 0) {
      x++;
    } else {
      y++;
    }
  }
  {
    ;
    my_assert((x > 0 || y > 0));
  }
  return 0;
  ;
}
