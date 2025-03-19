// Source: data/benchmarks/accelerating_invariant_generation/cav/07.c
#include <stdlib.h>
#define assume(e)                                                              \
  if (!(e))                                                                    \
    exit(-1);
int my_nondet;
int __attribute__((noinline)) my_unknown() { return my_nondet; }
void __attribute__((noinline)) my_assert(int x) {}
int x;
int n;
int i;
int j;
int unknown1() {
  ;
  return x;
  ;
}
int unknown2();
int unknown3();
int unknown4();
void main() {
  n = my_unknown();
  i = 0, j = 0;
  if (!(n >= 0))
    return;
  ;
  while (i < n) {
    i++;
    j++;
  }
  if (j >= n + 1) {
    goto ERROR;
    {
    ERROR: {
      ;
      my_assert((0));
    }
    }
  }
}
