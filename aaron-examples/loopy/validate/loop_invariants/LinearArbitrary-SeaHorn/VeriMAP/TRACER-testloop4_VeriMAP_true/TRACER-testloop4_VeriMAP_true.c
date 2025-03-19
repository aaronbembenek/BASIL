// Source:
// data/benchmarks/LinearArbitrary-SeaHorn/VeriMAP/TRACER-testloop4_VeriMAP_true.c
#include <stdlib.h>
#define assume(e)                                                              \
  if (!(e))                                                                    \
    exit(-1);
int my_nondet;
int __attribute__((noinline)) my_unknown() { return my_nondet; }
void __attribute__((noinline)) my_assert(int x) {}
int x;
int N;
int a;
void errorFn() {
ERROR:
  goto ERROR;
}
void main() {
  ;
  ;
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
