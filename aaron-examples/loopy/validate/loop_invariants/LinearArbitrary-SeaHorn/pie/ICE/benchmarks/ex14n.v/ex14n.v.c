// Source: data/benchmarks/LinearArbitrary-SeaHorn/pie/ICE/benchmarks/ex14n.v.c
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
  int x = (int)my_unknown(), y = (int)my_unknown(), N = (int)my_unknown(),
      v1 = (int)my_unknown(), v2 = (int)my_unknown(), v3 = (int)my_unknown();
  x = 1;
  N = my_unknown();
  while (x <= N) {
    y = N - x;
    if (y < 0 || y >= N) {
      ;
      my_assert((0 == 1));
    }
    x++;
    v1 = v2;
    v2 = v3;
    v3 = v1;
  }
  return 1;
  ;
}
