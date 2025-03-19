// Source:
// data/benchmarks/LinearArbitrary-SeaHorn/pie/ICE/benchmarks/sum01_safe.c
#include <stdlib.h>
#define assume(e)                                                              \
  if (!(e))                                                                    \
    exit(-1);
int my_nondet;
int __attribute__((noinline)) my_unknown() { return my_nondet; }
void __attribute__((noinline)) my_assert(int x) {}
int i;
int n;
int sn;
extern int unknown_int(void);
int main() {
  n = my_unknown(), sn = 0;
  for (i = 1; i <= n; i++) {
    sn = sn + 1;
  }
  {
    ;
    my_assert((sn == n || sn == 0));
  }
}
