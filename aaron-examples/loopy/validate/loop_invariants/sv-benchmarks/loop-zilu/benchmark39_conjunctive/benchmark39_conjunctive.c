// Source: data/benchmarks/sv-benchmarks/loop-zilu/benchmark39_conjunctive.c
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
  if (!(x == 4 * y && x >= 0))
    return 0;
  ;
  while (x > 0) {
    x -= 4;
    y--;
  }
  {
    ;
    my_assert((y >= 0));
  }
  return 0;
  ;
}
