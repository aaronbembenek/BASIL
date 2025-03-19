// Source:
// data/benchmarks/accelerating_invariant_generation/crafted/underapprox_safe2.c
#include <stdlib.h>
#define assume(e)                                                              \
  if (!(e))                                                                    \
    exit(-1);
int my_nondet;
int __attribute__((noinline)) my_unknown() { return my_nondet; }
void __attribute__((noinline)) my_assert(int x) {}
unsigned int x;
unsigned int y;
int main() {
  x = 0;
  y = 1;
  while (x < 6) {
    x++;
    y *= 2;
  }
  {
    ;
    my_assert((x == 6));
  }
}
