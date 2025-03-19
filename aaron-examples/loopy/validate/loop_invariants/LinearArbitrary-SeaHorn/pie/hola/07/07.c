// Source: data/benchmarks/LinearArbitrary-SeaHorn/pie/hola/07.c
#include <stdlib.h>
#define assume(e)                                                              \
  if (!(e))                                                                    \
    exit(-1);
int my_nondet;
int __attribute__((noinline)) my_unknown() { return my_nondet; }
void __attribute__((noinline)) my_assert(int x) {}
int i;
int n;
int a;
int b;
extern int unknown1();
extern int unknown2();
int main() {
  ;
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
