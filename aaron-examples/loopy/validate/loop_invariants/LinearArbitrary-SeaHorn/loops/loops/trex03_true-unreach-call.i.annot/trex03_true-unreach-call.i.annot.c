// Source:
// data/benchmarks/LinearArbitrary-SeaHorn/loops/loops/trex03_true-unreach-call.i.annot.c
#include <stdlib.h>
#define assume(e)                                                              \
  if (!(e))                                                                    \
    exit(-1);
int my_nondet;
int __attribute__((noinline)) my_unknown() { return my_nondet; }
void __attribute__((noinline)) my_assert(int x) {}
unsigned int x1;
unsigned int x2;
unsigned int x3;
unsigned int d1;
unsigned int d2;
unsigned int d3;
int c1;
int c2;
extern unsigned int unknown_uint(void);
extern _Bool unknown_bool(void);
int main() {
  x1 = my_unknown(), x2 = my_unknown(), x3 = my_unknown();
  d1 = 1, d2 = 1, d3 = 1;
  c1 = my_unknown(), c2 = my_unknown();
  while (x1 > 0 && x2 > 0 && x3 > 0) {
    if (c1)
      x1 = x1 - d1;
    else if (c2)
      x2 = x2 - d2;
    else
      x3 = x3 - d3;
    c1 = my_unknown();
    c2 = my_unknown();
  }
  {
    ;
    my_assert((x1 == 0 || x2 == 0 || x3 == 0));
  }
  return 0;
  ;
}
