// Source: data/benchmarks/accelerating_invariant_generation/cav/substring1.c
#include <stdlib.h>
#define assume(e)                                                              \
  if (!(e))                                                                    \
    exit(-1);
int my_nondet;
int __attribute__((noinline)) my_unknown() { return my_nondet; }
void __attribute__((noinline)) my_assert(int x) {}
int i;
int j;
int from;
int to;
int k;
void main() {
  ;
  ;
  ;
  ;
  if (!(k >= 0))
    return;
  ;
  if (!(k <= 100))
    return;
  ;
  if (!(from >= 0))
    return;
  ;
  if (!(from <= k))
    return;
  ;
  i = from;
  j = 0;
  while (i < k) {
    i++;
    j++;
  }
  if (j >= 101)
    goto ERROR;
  return;
  ;
  {
  ERROR: {
    ;
    my_assert((0));
  }
  }
}
