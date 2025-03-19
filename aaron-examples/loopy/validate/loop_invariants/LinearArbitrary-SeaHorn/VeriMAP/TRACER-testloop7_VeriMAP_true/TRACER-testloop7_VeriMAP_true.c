// Source:
// data/benchmarks/LinearArbitrary-SeaHorn/VeriMAP/TRACER-testloop7_VeriMAP_true.c
#include <stdlib.h>
#define assume(e)                                                              \
  if (!(e))                                                                    \
    exit(-1);
int my_nondet;
int __attribute__((noinline)) my_unknown() { return my_nondet; }
void __attribute__((noinline)) my_assert(int x) {}
int x;
int y;
extern int unknown(void);
int unknown() {
  ;
  return x;
  ;
}
void errorFn() {
ERROR:
  goto ERROR;
}
void main() {
  ;
  y = 0;
  x = 1;
  while (my_unknown() < 10) {
    if (x < 2) {
      x = 2;
    } else {
      x = 1;
    }
    if (y < 1) {
      y = 0;
    }
  }
  {
    ;
    my_assert((!(x > 2)));
  }
  return;
  ;
}
