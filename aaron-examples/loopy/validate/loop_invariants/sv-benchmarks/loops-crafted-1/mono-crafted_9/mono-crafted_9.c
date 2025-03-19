// Source: data/benchmarks/sv-benchmarks/loops-crafted-1/mono-crafted_9.c
#include <stdlib.h>
#define assume(e)                                                              \
  if (!(e))                                                                    \
    exit(-1);
int my_nondet;
int __attribute__((noinline)) my_unknown() { return my_nondet; }
void __attribute__((noinline)) my_assert(int x) {}
int x;
int y;
int main() {
  x = 0;
  y = 500000;
  while (x < 1000000) {
    if (x < 500000) {
      x = x + 1;
    } else {
      x = x + 1;
      y = y + 1;
    }
  }
  {
    ;
    my_assert((y == x));
  }
  return 0;
  ;
}
