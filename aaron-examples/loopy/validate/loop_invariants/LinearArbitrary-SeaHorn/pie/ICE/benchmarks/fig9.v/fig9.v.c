// Source: data/benchmarks/LinearArbitrary-SeaHorn/pie/ICE/benchmarks/fig9.v.c
#include <stdlib.h>
#define assume(e)                                                              \
  if (!(e))                                                                    \
    exit(-1);
int my_nondet;
int __attribute__((noinline)) my_unknown() { return my_nondet; }
void __attribute__((noinline)) my_assert(int x) {}
extern int unknown_int(void);
int main() {
  int x, y, v1, v2, v3;
  x = 0;
  y = 0;
  while (y >= 0) {
    y = y + x;
    v1 = my_unknown();
    v2 = my_unknown();
    v3 = my_unknown();
  }
  {
    ;
    my_assert((0 == 1));
  }
}
