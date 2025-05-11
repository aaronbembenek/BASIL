// Source:
// data/benchmarks/LinearArbitrary-SeaHorn/VeriMAP/TRACER-testloop15_VeriMAP_true.c
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
int main() {
  int i = 0;
  int N = 100;
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
