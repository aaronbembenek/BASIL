// Source:
// data/benchmarks/accelerating_invariant_generation/crafted/underapprox_safe2.c
#include <stdlib.h>
#define assume(e)                                                              \
  if (!(e))                                                                    \
    exit(-1);
int __attribute__((noinline)) my_unknown() { return rand(); }
void __attribute__((noinline)) my_assert(int x) {
  while (!x)
    ;
}
int main() {
  unsigned int x = 0;
  unsigned int y = 1;
  while (x < 6) {
    x++;
    y *= 2;
  }
  {
    ;
    my_assert((x == 6));
  }
}
