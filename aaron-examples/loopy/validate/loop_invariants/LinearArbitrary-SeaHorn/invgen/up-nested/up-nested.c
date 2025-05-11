// Source: data/benchmarks/LinearArbitrary-SeaHorn/invgen/up-nested.c
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
  int n = (int)my_unknown(), j = (int)my_unknown(), i = (int)my_unknown(),
      k = (int)my_unknown();
  i = 0;
  k = 0;
  j = my_unknown();
  n = my_unknown();
  if (j <= n) {
    while (j <= n) {
      j++;
    }
    {
      ;
      my_assert((i >= 0));
    }
  }
}
