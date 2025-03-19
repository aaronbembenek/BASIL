// Source: data/benchmarks/LinearArbitrary-SeaHorn/pie/ICE/benchmarks/inc.c
#include <stdlib.h>
#define assume(e)                                                              \
  if (!(e))                                                                    \
    exit(-1);
int my_nondet;
int __attribute__((noinline)) my_unknown() { return my_nondet; }
void __attribute__((noinline)) my_assert(int x) {}
int x;
int m;
extern int unknown_int(void);
int main() {
  ;
  x = 0;
  while (x < 100) {
    m = my_unknown();
    x = x + 1;
  }
  {
    ;
    my_assert((x == 100));
  }
}
