// Source:
// data/benchmarks/LinearArbitrary-SeaHorn/pie/ICE/benchmarks/trex03_safe.v.c
#include <stdlib.h>
#define assume(e)                                                              \
  if (!(e))                                                                    \
    exit(-1);
int my_nondet;
int __attribute__((noinline)) my_unknown() { return my_nondet; }
void __attribute__((noinline)) my_assert(int x) {}
extern int unknown_int(void);
extern unsigned int unknown_uint(void);
extern _Bool unknown_bool(void);
int main() {
  unsigned int x1 = my_unknown(), x2 = my_unknown(), x3 = my_unknown();
  unsigned int d1 = 1, d2 = 1, d3 = 1;
  _Bool c1 = my_unknown(), c2 = my_unknown();
  int v1, v2, v3;
  while (x1 > 0 && x2 > 0 && x3 > 0) {
    if (c1)
      x1 = x1 - d1;
    else if (c2)
      x2 = x2 - d2;
    else
      x3 = x3 - d3;
    c1 = my_unknown();
    c2 = my_unknown();
    v1 = my_unknown();
    v2 = my_unknown();
    v3 = my_unknown();
  }
  {
    ;
    my_assert((x1 == 0 || x2 == 0 || x3 == 0));
  }
  return 0;
  ;
}
