// Source: data/benchmarks/accelerating_invariant_generation/cav/gulv.c
#include <stdlib.h>
#define assume(e)                                                              \
  if (!(e))                                                                    \
    exit(-1);
int my_nondet;
int __attribute__((noinline)) my_unknown() { return my_nondet; }
void __attribute__((noinline)) my_assert(int x) {}
int x;
int y;
int w;
int z;
extern int unknown_int(void);
int nondet();
int main() {
  x = 0, y = 0, w = 0, z = 0;
  while (my_unknown()) {
    if (my_unknown()) {
      x = x + 1;
      y = y + 100;
    } else if (my_unknown()) {
      if (x >= 4) {
        x = x + 1;
        y = y + 1;
      }
    } else if (y > 10 * w && z >= 100 * x) {
      y = -y;
    }
    w = w + 1;
    z = z + 10;
    x = x;
  }
  if (x >= 4 && y <= 2)
    goto ERROR;
  return 0;
  ;
  {
  ERROR: {
    ;
    my_assert((0));
  }
  }
}
