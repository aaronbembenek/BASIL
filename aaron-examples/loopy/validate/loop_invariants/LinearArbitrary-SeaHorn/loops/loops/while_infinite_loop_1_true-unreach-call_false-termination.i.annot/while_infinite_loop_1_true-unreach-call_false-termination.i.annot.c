// Source:
// data/benchmarks/LinearArbitrary-SeaHorn/loops/loops/while_infinite_loop_1_true-unreach-call_false-termination.i.annot.c
#include <stdlib.h>
#define assume(e)                                                              \
  if (!(e))                                                                    \
    exit(-1);
int __attribute__((noinline)) my_unknown() { return rand(); }
void __attribute__((noinline)) my_assert(int x) {
  while (!x)
    ;
}
int main() {
  int x = 0;
  while (1) {
    {
      ;
      my_assert((x == 0));
    }
  }
  {
    ;
    my_assert((x != 0));
  }
}
