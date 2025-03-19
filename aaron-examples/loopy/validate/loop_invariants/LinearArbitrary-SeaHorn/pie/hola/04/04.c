// Source: data/benchmarks/LinearArbitrary-SeaHorn/pie/hola/04.c
#include <stdlib.h>
#define assume(e)                                                              \
  if (!(e))                                                                    \
    exit(-1);
int my_nondet;
int __attribute__((noinline)) my_unknown() { return my_nondet; }
void __attribute__((noinline)) my_assert(int x) {}
int x;
int y;
extern int unknown1();
void main() {
  ;
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
