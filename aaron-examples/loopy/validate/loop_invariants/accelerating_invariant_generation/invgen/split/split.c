// Source: data/benchmarks/accelerating_invariant_generation/invgen/split.c
#include <stdlib.h>
#define assume(e)                                                              \
  if (!(e))                                                                    \
    exit(-1);
int __attribute__((noinline)) my_unknown() { return rand(); }
void __attribute__((noinline)) my_assert(int x) {
  while (!x)
    ;
}
void main() {
  int k = 100;
  int b = (int)my_unknown();
  int i = (int)my_unknown();
  int j = (int)my_unknown();
  int n = (int)my_unknown();
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
