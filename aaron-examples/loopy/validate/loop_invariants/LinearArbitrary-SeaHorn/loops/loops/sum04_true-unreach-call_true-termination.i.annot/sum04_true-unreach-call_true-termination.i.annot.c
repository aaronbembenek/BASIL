// Source:
// data/benchmarks/LinearArbitrary-SeaHorn/loops/loops/sum04_true-unreach-call_true-termination.i.annot.c
#include <stdlib.h>
#define assume(e)                                                              \
  if (!(e))                                                                    \
    exit(-1);
int __attribute__((noinline)) my_unknown() { return rand(); }
void __attribute__((noinline)) my_assert(int x) {
  while (!x)
    ;
}
int main() {
  int i = (int)my_unknown(), sn = 0;
  for (i = 1; i <= 8; i++) {
    sn = sn + (2);
  }
  {
    ;
    my_assert((sn == 8 * (2) || sn == 0));
  }
}
