// Source:
// data/benchmarks/LinearArbitrary-SeaHorn/VeriMAP/TRACER-testloop7_VeriMAP_true.c
#include <stdlib.h>
#define assume(e)                                                              \
  if (!(e))                                                                    \
    exit(-1);
int __attribute__((noinline)) my_unknown() { return rand(); }
void __attribute__((noinline)) my_assert(int x) {
  while (!x)
    ;
}
extern int unknown(void);
int unknown() {
  int x = (int)my_unknown();
  return x;
  ;
}
void errorFn() {
ERROR:
  goto ERROR;
}
void main() {
  int x = (int)my_unknown(), y = (int)my_unknown();
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
