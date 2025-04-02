// Source:
// data/benchmarks/LinearArbitrary-SeaHorn/loops/loop-lit/gj2007_true-unreach-call_true-termination.c
#include <stdlib.h>
#define assume(e)                                                              \
  if (!(e))                                                                    \
    exit(-1);
int my_nondet;
int __attribute__((noinline)) my_unknown() { return my_nondet; }
void __attribute__((noinline)) my_assert(int x) {}
int main() {
  int x = 0;
  int y = 50;
  while (x < 100) {
    if (x < 50) {
      x = x + 1;
    } else {
      x = x + 1;
      y = y + 1;
    }
  }
  {
    ;
    my_assert((y == 100));
  }
  return 0;
  ;
}
