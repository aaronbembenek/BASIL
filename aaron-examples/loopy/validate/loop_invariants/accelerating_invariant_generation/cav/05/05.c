// Source: data/benchmarks/accelerating_invariant_generation/cav/05.c
#include <stdlib.h>
#define assume(e)                                                              \
  if (!(e))                                                                    \
    exit(-1);
int __attribute__((noinline)) my_unknown() { return rand(); }
void __attribute__((noinline)) my_assert(int x) {
  while (!x)
    ;
}
int unknown1() {
  int x = (int)my_unknown();
  return x;
  ;
}
int unknown2();
int unknown3();
int unknown4();
void main() {
  int flag = my_unknown();
  int x = 0;
  int y = 0;
  int j = 0;
  int i = 0;
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
