// Source: data/benchmarks/LinearArbitrary-SeaHorn/pie/hola/07.c
#include <stdlib.h>
#define assume(e)                                                              \
  if (!(e))                                                                    \
    exit(-1);
int __attribute__((noinline)) my_unknown() { return rand(); }
void __attribute__((noinline)) my_assert(int x) {
  while (!x)
    ;
}
extern int unknown1();
extern int unknown2();
int main() {
  int i = (int)my_unknown(), n = (int)my_unknown(), a = (int)my_unknown(),
      b = (int)my_unknown();
  n = my_unknown();
  i = 0;
  a = 0;
  b = 0;
  if (n >= 0) {
    while (i < n) {
      if (my_unknown()) {
        a = a + 1;
        b = b + 2;
      } else {
        a = a + 2;
        b = b + 1;
      }
      i = i + 1;
    }
    {
      ;
      my_assert((a + b == 3 * n));
    }
  }
  return 0;
  ;
}
