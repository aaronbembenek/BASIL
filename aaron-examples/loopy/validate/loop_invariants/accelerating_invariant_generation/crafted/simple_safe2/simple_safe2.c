// Source:
// data/benchmarks/accelerating_invariant_generation/crafted/simple_safe2.c
#include <stdlib.h>
#define assume(e)                                                              \
  if (!(e))                                                                    \
    exit(-1);
int my_nondet;
int __attribute__((noinline)) my_unknown() { return my_nondet; }
void __attribute__((noinline)) my_assert(int x) {}
unsigned int x;
int main() {
  ;
  while (x < 0x0fffffff) {
    x++;
  }
  {
    ;
    my_assert((x >= 0x0fffffff));
  }
}
