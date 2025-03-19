// Source: data/benchmarks/accelerating_invariant_generation/cav/05.c
#include <stdlib.h>
#define assume(e)                                                              \
  if (!(e))                                                                    \
    exit(-1);
int my_nondet;
int __attribute__((noinline)) my_unknown() { return my_nondet; }
void __attribute__((noinline)) my_assert(int x) {}
int x;
int flag;
int y;
int j;
int i;
int unknown1() {
  ;
  return x;
  ;
}
int unknown2();
int unknown3();
int unknown4();
void main() {
  flag = my_unknown();
  x = 0;
  y = 0;
  j = 0;
  i = 0;
  while (my_unknown()) {
    x++;
    y++;
    i += x;
    j += y;
    if (flag)
      j += 1;
    j = j;
  }
  if (j <= i - 1) {
    goto ERROR;
    {
    ERROR: {
      ;
      my_assert((0));
    }
    }
  }
}
