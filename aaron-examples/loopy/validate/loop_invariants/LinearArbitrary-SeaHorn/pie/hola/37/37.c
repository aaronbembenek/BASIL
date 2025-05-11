// Source: data/benchmarks/LinearArbitrary-SeaHorn/pie/hola/37.c
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
void main() {
  int x = 0;
  int m = 0;
  int n = my_unknown();
  while (x < n) {
    if (my_unknown()) {
      m = x;
    }
    x = x + 1;
  }
  if (n > 0) {
    ;
    my_assert((0 <= m && m < n));
  }
}
