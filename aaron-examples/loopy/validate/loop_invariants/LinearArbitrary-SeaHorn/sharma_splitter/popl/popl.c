// Source: data/benchmarks/LinearArbitrary-SeaHorn/sharma_splitter/popl.c
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
  int x = (int)my_unknown(), y = (int)my_unknown();
  x = 0;
  y = 50;
  while (x < 100) {
    x = x + 1;
    if (x > 50) {
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
