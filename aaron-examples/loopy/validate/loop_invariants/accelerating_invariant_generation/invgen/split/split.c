// Source: data/benchmarks/accelerating_invariant_generation/invgen/split.c
#include <stdlib.h>
#define assume(e)                                                              \
  if (!(e))                                                                    \
    exit(-1);
int my_nondet;
int __attribute__((noinline)) my_unknown() { return my_nondet; }
void __attribute__((noinline)) my_assert(int x) {}
void main() {
  int k = 100;
  int b;
  int i;
  int j;
  int n;
  i = j;
  for (n = 0; n < 2 * k; n++) {
    if (b) {
      i++;
    } else {
      j++;
    }
    b = !b;
  }
  {
    ;
    my_assert((i == j));
  }
}
