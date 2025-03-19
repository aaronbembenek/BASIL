// Source: data/benchmarks/LinearArbitrary-SeaHorn/pie/ICE/benchmarks/form27.c
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
int x4;
int x5;
int x1p;
int x2p;
int x3p;
int x4p;
int x5p;
int input;
extern int unknown_int(void);
int main() {
  ;
  ;
  x1 = x2 = x3 = x4 = x5 = 0;
  input = my_unknown();
  while (input) {
    x1p = my_unknown();
    x2p = my_unknown();
    x3p = my_unknown();
    x4p = my_unknown();
    x5p = my_unknown();
    if (0 <= x1p && x1p <= x4p + 1 && x2p == x3p &&
        (x2p <= -1 || x4p <= x2p + 2) && x5p == 0) {
      x1 = x1p;
      x2 = x2p;
      x3 = x3p;
      x4 = x4p;
      x5 = x5p;
    }
    input = my_unknown();
  }
  {
    ;
    my_assert((0 <= x1 && x1 <= x4 + 1 && x2 == x3 &&
               (x2 <= -1 || x4 <= x2 + 2) && x5 == 0));
  }
}
