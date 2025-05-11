// Source:
// data/benchmarks/LinearArbitrary-SeaHorn/pie/ICE/benchmarks/sum01_safe.c
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
  int i = (int)my_unknown(), n = my_unknown(), sn = 0;
  for (i = 1; i <= n; i++) {
    sn = sn + 1;
  }
  {
    ;
    my_assert((sn == n || sn == 0));
  }
}
