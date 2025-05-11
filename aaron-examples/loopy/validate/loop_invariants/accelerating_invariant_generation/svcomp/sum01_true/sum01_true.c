// Source: data/benchmarks/accelerating_invariant_generation/svcomp/sum01_true.c
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
#define a (2)
int main() {
  int i = (int)my_unknown(), n = my_unknown(), sn = 0;
  for (i = 1; i <= n; i++) {
    sn = sn + a;
  }
  {
    ;
    my_assert((sn == n * a || sn == 0));
  }
}
