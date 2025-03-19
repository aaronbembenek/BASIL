// Source: data/benchmarks/sv-benchmarks/loop-lit/gr2006.c
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
  ;
  x = 0;
  y = 0;
  while (1) {
    if (x < 50) {
      y++;
    } else {
      y--;
    }
    if (y < 0)
      break;
    x++;
  }
  {
    ;
    my_assert((x == 100));
  }
  return 0;
  ;
}
