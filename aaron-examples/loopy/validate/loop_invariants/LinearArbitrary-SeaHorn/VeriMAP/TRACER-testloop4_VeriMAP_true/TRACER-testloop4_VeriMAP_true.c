// Source:
// data/benchmarks/LinearArbitrary-SeaHorn/VeriMAP/TRACER-testloop4_VeriMAP_true.c
#include <stdlib.h>
#define assume(e)                                                              \
  if (!(e))                                                                    \
    exit(-1);
int __attribute__((noinline)) my_unknown() { return rand(); }
void __attribute__((noinline)) my_assert(int x) {
  while (!x)
    ;
}
void errorFn() {
ERROR:
  goto ERROR;
}
void main() {
  int x = (int)my_unknown(), N = (int)my_unknown();
  int a = (int)my_unknown();
  a = 0;
  N = 10;
  x = 0;
  do {
    x = x + 1;
  } while (x != N);
  {
    ;
    my_assert((!(a > 1)));
  }
}
