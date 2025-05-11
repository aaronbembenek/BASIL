// Source:
// data/benchmarks/LinearArbitrary-SeaHorn/VeriMAP/TRACER-testloop14_VeriMAP_true.c
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
void errorFn() {
ERROR:
  goto ERROR;
}
int main() {
  int i = (int)my_unknown(), x = (int)my_unknown(), y = (int)my_unknown();
  x = my_unknown();
  y = my_unknown();
  if (y <= 2) {
    if (x < 0) {
      x = 0;
    }
    i = 0;
    while (i < 10) {
      {
        ;
        my_assert((!(y > 2)));
      }
      i++;
    }
    {
      ;
      my_assert((!(x <= -1)));
    }
  }
  return 0;
  ;
}
