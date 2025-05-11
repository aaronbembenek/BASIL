// Source:
// data/benchmarks/LinearArbitrary-SeaHorn/loops/loops/sum03_true-unreach-call_false-termination.i.annot.c
#include <stdlib.h>
#define assume(e)                                                              \
  if (!(e))                                                                    \
    exit(-1);
int __attribute__((noinline)) my_unknown() { return rand(); }
void __attribute__((noinline)) my_assert(int x) {
  while (!x)
    ;
}
extern unsigned int unknown_uint(void);
int main() {
  int sn = 0;
  unsigned int loop1 = my_unknown(), n1 = my_unknown();
  unsigned int x = 0;
  while (x < 1000000) {
    sn = sn + (2);
    x++;
    {
      ;
      my_assert((sn == x * (2) || sn == 0));
    }
  }
}
