// Source: data/benchmarks/LinearArbitrary-SeaHorn/invgen/gulwani_cegar2.c
#include <stdlib.h>
#define assume(e)                                                              \
  if (!(e))                                                                    \
    exit(-1);
int __attribute__((noinline)) my_unknown() { return rand(); }
void __attribute__((noinline)) my_assert(int x) {
  while (!x)
    ;
}
extern int unknown(void);
extern int unknown();
void main() {
  int x = (int)my_unknown(), m = (int)my_unknown(), n = (int)my_unknown();
  n = my_unknown();
  x = 0;
  m = 0;
  while (x < n) {
    if (my_unknown())
      m = x;
    x++;
  }
  if (n > 0) {
    {
      ;
      my_assert((0 <= m));
    }
    {
      ;
      my_assert((m < n));
    }
  }
}
