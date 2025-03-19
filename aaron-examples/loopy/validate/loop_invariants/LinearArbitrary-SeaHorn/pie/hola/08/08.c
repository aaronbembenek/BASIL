// Source: data/benchmarks/LinearArbitrary-SeaHorn/pie/hola/08.c
#include <stdlib.h>
#define assume(e)                                                              \
  if (!(e))                                                                    \
    exit(-1);
int my_nondet;
int __attribute__((noinline)) my_unknown() { return my_nondet; }
void __attribute__((noinline)) my_assert(int x) {}
int x;
int y;
extern int unknown1();
extern int unknown2();
extern int unknown3();
void main() {
  x = 0, y = 0;
  while (my_unknown()) {
    if (my_unknown()) {
      x++;
      y += 100;
    } else if (my_unknown()) {
      if (x >= 4) {
        x++;
        y++;
      }
      if (x < 0) {
        y = -y;
      }
    }
  }
  {
    ;
    my_assert((x < 4 || y > 2));
  }
}
