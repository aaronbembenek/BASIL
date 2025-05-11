// Source: data/benchmarks/sv-benchmarks/loop-lit/gr2006.c
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
