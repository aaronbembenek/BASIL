// Source: data/benchmarks/LinearArbitrary-SeaHorn/invgen/gulwani_cegar1.c
#include <stdlib.h>
#define assume(e)                                                              \
  if (!(e))                                                                    \
    exit(-1);
int my_nondet;
int __attribute__((noinline)) my_unknown() { return my_nondet; }
void __attribute__((noinline)) my_assert(int x) {}
int x;
int y;
extern int unknown(void);
extern int unknown();
void main() {
  x = my_unknown();
  y = my_unknown();
  assume(0 <= x);
  assume(x <= 2);
  assume(0 <= y);
  assume(y <= 2);
  if (x >= 0 && x <= 2 && y >= 0 && y <= 2) {
    while (my_unknown()) {
      x += 2;
      y += 2;
    }
    if (y >= 0)
      if (y <= 0)
        if (4 <= x) {
          ;
          my_assert((x < 4));
        }
  }
}
