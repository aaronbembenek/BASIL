// Source:
// data/benchmarks/accelerating_invariant_generation/cav/pldi082_unbounded.c
#include <stdlib.h>
#define assume(e)                                                              \
  if (!(e))                                                                    \
    exit(-1);
int my_nondet;
int __attribute__((noinline)) my_unknown() { return my_nondet; }
void __attribute__((noinline)) my_assert(int x) {}
int x;
int y;
int N;
int main() {
  x = 0;
  y = 0;
  ;
  if (N < 0)
    return 1;
  ;
  while (1) {
    if (x <= N)
      y++;
    else if (x >= N + 1)
      y--;
    else
      return 1;
    ;
    if (y < 0)
      break;
    x++;
  }
  if (N >= 0)
    if (y == -1)
      if (x >= 2 * N + 3)
        goto ERROR;
  return 1;
  ;
  {
  ERROR: {
    ;
    my_assert((0));
  }
  }
}
