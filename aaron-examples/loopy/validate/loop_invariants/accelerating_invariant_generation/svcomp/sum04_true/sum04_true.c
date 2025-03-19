// Source: data/benchmarks/accelerating_invariant_generation/svcomp/sum04_true.c
#include <stdlib.h>
#define assume(e)                                                              \
  if (!(e))                                                                    \
    exit(-1);
int my_nondet;
int __attribute__((noinline)) my_unknown() { return my_nondet; }
void __attribute__((noinline)) my_assert(int x) {}
int i;
int sn;
#define a (2)
#define SIZE 8
int main() {
  sn = 0;
  for (i = 1; i <= SIZE; i++) {
    sn = sn + a;
  }
  {
    ;
    my_assert((sn == SIZE * a || sn == 0));
  }
}
