// Source:
// data/benchmarks/LinearArbitrary-SeaHorn/VeriMAP/TRACER-testloop2_VeriMAP_true.c
#include <stdlib.h>
#define assume(e)                                                              \
  if (!(e))                                                                    \
    exit(-1);
int my_nondet;
int __attribute__((noinline)) my_unknown() { return my_nondet; }
void __attribute__((noinline)) my_assert(int x) {}
int NONDET;
int i;
int N;
int a;
int x;
void errorFn() {
ERROR:
  goto ERROR;
}
void main() {
  ;
  ;
  ;
  ;
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
