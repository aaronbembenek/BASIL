// Source: data/benchmarks/LinearArbitrary-SeaHorn/pie/ICE/benchmarks/incn.v.c
#include <stdlib.h>
#define assume(e)                                                              \
  if (!(e))                                                                    \
    exit(-1);
int __attribute__((noinline)) my_unknown() { return rand(); }
void __attribute__((noinline)) my_assert(int x) {
  while (!x)
    ;
}
extern int unknown_int(void);
int main() {
  int x = (int)my_unknown(), N = (int)my_unknown(), v1 = (int)my_unknown(),
      v2 = (int)my_unknown(), v3 = (int)my_unknown();
  x = 0;
  N = my_unknown();
  while (x < N) {
    x = x + 1;
    v1 = my_unknown();
    v2 = my_unknown();
    v3 = my_unknown();
  }
  {
    ;
    my_assert((N < 0 || x == N));
  }
}
