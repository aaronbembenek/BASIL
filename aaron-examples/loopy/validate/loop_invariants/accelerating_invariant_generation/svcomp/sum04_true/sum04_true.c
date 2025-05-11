// Source: data/benchmarks/accelerating_invariant_generation/svcomp/sum04_true.c
#include <stdlib.h>
#define assume(e)                                                              \
  if (!(e))                                                                    \
    exit(-1);
int __attribute__((noinline)) my_unknown() { return rand(); }
void __attribute__((noinline)) my_assert(int x) {
  while (!x)
    ;
}
#define a (2)
#define SIZE 8
int main() {
  int i = (int)my_unknown(), sn = 0;
  for (i = 1; i <= SIZE; i++) {
    sn = sn + a;
  }
  {
    ;
    my_assert((sn == SIZE * a || sn == 0));
  }
}
