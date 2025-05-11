// Source:
// data/benchmarks/LinearArbitrary-SeaHorn/VeriMAP/TRACER-testloop11_VeriMAP_true.c
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
  int e = (int)my_unknown(), s = (int)my_unknown();
  e = 0;
  s = 2;
  while (my_unknown()) {
    if (s == 2) {
      if (e == 0)
        e = 1;
      s = 3;
    } else if (s == 3) {
      if (e == 1)
        e = 2;
      s = 4;
    } else if (s == 4) {
      {
        ;
        my_assert((!(e == 3)));
      }
      s = 5;
    }
  }
  return;
  ;
}
