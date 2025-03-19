// Source: data/benchmarks/LinearArbitrary-SeaHorn/pie/ICE/benchmarks/form22.c
#include <stdlib.h>
#define assume(e)                                                              \
  if (!(e))                                                                    \
    exit(-1);
int my_nondet;
int __attribute__((noinline)) my_unknown() { return my_nondet; }
void __attribute__((noinline)) my_assert(int x) {}
int x1;
int x2;
int x3;
int x1p;
int x2p;
int x3p;
int input;
extern int unknown_int(void);
int main() {
  ;
  ;
  x1 = x2 = x3 = 0;
  input = my_unknown();
  while (input) {
    x1p = my_unknown();
    x2p = my_unknown();
    x3p = my_unknown();
    if (x1p <= x2p && (x2p >= 0 || x2p - x3p <= 2)) {
      x1 = x1p;
      x2 = x2p;
      x3 = x3p;
    }
    input = my_unknown();
  }
  {
    ;
    my_assert((x1 <= x2 && (x2 >= 0 || x2 - x3 <= 2)));
  }
}
