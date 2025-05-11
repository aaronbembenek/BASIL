// Source: data/benchmarks/LinearArbitrary-SeaHorn/pie/ICE/benchmarks/inc.c
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
  int x = (int)my_unknown(), m = (int)my_unknown();
  x = 0;
  while (x < 100) {
    m = my_unknown();
    x = x + 1;
  }
  {
    ;
    my_assert((x == 100));
  }
}
