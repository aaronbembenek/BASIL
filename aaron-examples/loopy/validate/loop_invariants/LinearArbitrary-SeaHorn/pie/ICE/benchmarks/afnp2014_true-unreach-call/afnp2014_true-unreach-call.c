// Source:
// data/benchmarks/LinearArbitrary-SeaHorn/pie/ICE/benchmarks/afnp2014_true-unreach-call.c
#include <stdlib.h>
#define assume(e)                                                              \
  if (!(e))                                                                    \
    exit(-1);
int my_nondet;
int __attribute__((noinline)) my_unknown() { return my_nondet; }
void __attribute__((noinline)) my_assert(int x) {}
int x;
int y;
extern int unknown_int(void);
void main() {
  x = 1;
  y = 0;
  while (y < 1000 && my_unknown()) {
    x = x + y;
    y = y + 1;
  }
  {
    ;
    my_assert((x >= y));
  }
}
