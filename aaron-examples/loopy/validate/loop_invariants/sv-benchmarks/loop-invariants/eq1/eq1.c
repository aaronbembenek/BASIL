// Source: data/benchmarks/sv-benchmarks/loop-invariants/eq1.c
#include <stdlib.h>
#define assume(e)                                                              \
  if (!(e))                                                                    \
    exit(-1);
int my_nondet;
int __attribute__((noinline)) my_unknown() { return my_nondet; }
void __attribute__((noinline)) my_assert(int x) {}
unsigned int w;
unsigned int x;
unsigned int y;
unsigned int z;
extern unsigned int unknown_uint(void);
int main() {
  w = my_unknown();
  x = w;
  y = my_unknown();
  z = y;
  while (my_unknown()) {
    if (my_unknown()) {
      ++w;
      ++x;
    } else {
      --y;
      --z;
    }
  }
  {
    ;
    my_assert((w == x && y == z));
  }
  return 0;
  ;
}
