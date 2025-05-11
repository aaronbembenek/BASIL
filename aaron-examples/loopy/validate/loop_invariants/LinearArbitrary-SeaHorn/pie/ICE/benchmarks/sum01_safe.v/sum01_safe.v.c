// Source:
// data/benchmarks/LinearArbitrary-SeaHorn/pie/ICE/benchmarks/sum01_safe.v.c
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
  int i = (int)my_unknown(), n = my_unknown(), sn = 0, v1 = (int)my_unknown(),
      v2 = (int)my_unknown(), v3 = (int)my_unknown();
  for (i = 1; i <= n; i++) {
    sn = sn + 1;
    v1 = my_unknown();
    v2 = my_unknown();
    v3 = my_unknown();
  }
  {
    ;
    my_assert((sn == n || sn == 0));
  }
}
