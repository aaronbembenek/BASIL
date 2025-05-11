// Source: data/benchmarks/LinearArbitrary-SeaHorn/pie/hola/08.c
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
extern int unknown3();
void main() {
  int x = 0, y = 0;
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
