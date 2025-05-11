// Source:
// data/benchmarks/LinearArbitrary-SeaHorn/VeriMAP/TRACER-testloop2_VeriMAP_true.c
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
  int NONDET = (int)my_unknown();
  int i = (int)my_unknown(), N = (int)my_unknown();
  int a = (int)my_unknown();
  int x = (int)my_unknown();
  if (my_unknown() > 0)
    x = 1;
  else
    x = 2;
  while (i < N) {
    i = i + 1;
  }
  {
    ;
    my_assert((!(x > 2)));
  }
  return;
  ;
}
