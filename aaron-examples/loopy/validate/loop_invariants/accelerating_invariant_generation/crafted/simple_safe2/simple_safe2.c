// Source:
// data/benchmarks/accelerating_invariant_generation/crafted/simple_safe2.c
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
  unsigned int x = (unsigned int)my_unknown();
  while (x < 0x0fffffff) {
    x++;
  }
  {
    ;
    my_assert((x >= 0x0fffffff));
  }
}
