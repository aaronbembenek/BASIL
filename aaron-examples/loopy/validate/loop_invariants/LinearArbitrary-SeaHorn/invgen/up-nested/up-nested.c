// Source: data/benchmarks/LinearArbitrary-SeaHorn/invgen/up-nested.c
#include <stdlib.h>
#define assume(e)                                                              \
  if (!(e))                                                                    \
    exit(-1);
int my_nondet;
int __attribute__((noinline)) my_unknown() { return my_nondet; }
void __attribute__((noinline)) my_assert(int x) {}
int n;
int j;
int i;
int k;
extern int unknown(void);
extern int unknown();
void main() {
  ;
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
