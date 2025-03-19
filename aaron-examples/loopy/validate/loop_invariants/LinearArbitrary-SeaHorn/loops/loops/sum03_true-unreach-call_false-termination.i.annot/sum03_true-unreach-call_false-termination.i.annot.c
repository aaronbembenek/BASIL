// Source:
// data/benchmarks/LinearArbitrary-SeaHorn/loops/loops/sum03_true-unreach-call_false-termination.i.annot.c
#include <stdlib.h>
#define assume(e)                                                              \
  if (!(e))                                                                    \
    exit(-1);
int my_nondet;
int __attribute__((noinline)) my_unknown() { return my_nondet; }
void __attribute__((noinline)) my_assert(int x) {}
int sn;
unsigned int loop1;
unsigned int n1;
unsigned int x;
extern unsigned int unknown_uint(void);
int main() {
  sn = 0;
  loop1 = my_unknown(), n1 = my_unknown();
  x = 0;
  while (x < 1000000) {
    sn = sn + (2);
    x++;
    {
      ;
      my_assert((sn == x * (2) || sn == 0));
    }
  }
}
