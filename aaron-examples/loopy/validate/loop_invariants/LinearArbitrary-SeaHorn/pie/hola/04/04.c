// Source: data/benchmarks/LinearArbitrary-SeaHorn/pie/hola/04.c
#include <stdlib.h>
#define assume(e)                                                              \
  if (!(e))                                                                    \
    exit(-1);
int __attribute__((noinline)) my_unknown() { return rand(); }
void __attribute__((noinline)) my_assert(int x) {
  while (!x)
    ;
}
extern int unknown1();
void main() {
  int x = (int)my_unknown(), y = (int)my_unknown();
  x = -50;
  while (x < 0) {
    x = x + y;
    y++;
  }
  {
    ;
    my_assert((y > 0));
  }
}
