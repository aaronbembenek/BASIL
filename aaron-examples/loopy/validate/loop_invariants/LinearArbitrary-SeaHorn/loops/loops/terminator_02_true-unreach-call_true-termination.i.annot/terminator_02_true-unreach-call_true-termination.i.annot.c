// Source:
// data/benchmarks/LinearArbitrary-SeaHorn/loops/loops/terminator_02_true-unreach-call_true-termination.i.annot.c
#include <stdlib.h>
#define assume(e)                                                              \
  if (!(e))                                                                    \
    exit(-1);
int my_nondet;
int __attribute__((noinline)) my_unknown() { return my_nondet; }
void __attribute__((noinline)) my_assert(int x) {}
int x;
int y;
int z;
int tmp;
extern int unknown_int(void);
extern _Bool unknown_bool(void);
int main() {
  x = my_unknown();
  y = my_unknown();
  z = my_unknown();
  assume(x < 100);
  assume(x > -100);
  assume(z < 100);
  assume(z > -100);
  while (x < 100 && 100 < z) {
    tmp = my_unknown();
    if (tmp) {
      x++;
    } else {
      x--;
      z--;
    }
  }
  {
    ;
    my_assert((x >= 100 || z <= 100));
  }
  return 0;
  ;
}
