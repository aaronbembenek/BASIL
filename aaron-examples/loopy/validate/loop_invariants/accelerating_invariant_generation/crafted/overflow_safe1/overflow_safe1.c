// Source:
// data/benchmarks/accelerating_invariant_generation/crafted/overflow_safe1.c
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
  unsigned int x = 10;
  while (x >= 10) {
    x += 2;
  }
  {
    ;
    my_assert((!(x % 2)));
  }
}
