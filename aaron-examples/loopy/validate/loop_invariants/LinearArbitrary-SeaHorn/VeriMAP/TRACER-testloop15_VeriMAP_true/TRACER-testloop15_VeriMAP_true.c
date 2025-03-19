// Source:
// data/benchmarks/LinearArbitrary-SeaHorn/VeriMAP/TRACER-testloop15_VeriMAP_true.c
#include <stdlib.h>
#define assume(e)                                                              \
  if (!(e))                                                                    \
    exit(-1);
int my_nondet;
int __attribute__((noinline)) my_unknown() { return my_nondet; }
void __attribute__((noinline)) my_assert(int x) {}
int i;
int N;
void errorFn() {
ERROR:
  goto ERROR;
}
int main() {
  i = 0;
  N = 100;
  while (i < N) {
    i++;
  }
  {
    ;
    my_assert((!(i > N)));
  }
  return 0;
  ;
}
