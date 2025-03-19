// Source:
// data/benchmarks/accelerating_invariant_generation/crafted/overflow_safe1.c
#include <stdlib.h>
#define assume(e)                                                              \
  if (!(e))                                                                    \
    exit(-1);
int my_nondet;
int __attribute__((noinline)) my_unknown() { return my_nondet; }
void __attribute__((noinline)) my_assert(int x) {}
unsigned int x;
int main() {
  x = 10;
  while (x >= 10) {
    x += 2;
  }
  {
    ;
    my_assert((!(x % 2)));
  }
}
