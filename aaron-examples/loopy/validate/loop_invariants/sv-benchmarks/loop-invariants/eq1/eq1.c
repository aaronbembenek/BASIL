// Source: data/benchmarks/sv-benchmarks/loop-invariants/eq1.c
#include <stdlib.h>
#define assume(e)                                                              \
  if (!(e))                                                                    \
    exit(-1);
int my_nondet;
int __attribute__((noinline)) my_unknown() { return my_nondet; }
void __attribute__((noinline)) my_assert(int x) {}
extern unsigned int unknown_uint(void);
int main() {
  unsigned int w = my_unknown();
  unsigned int x = w;
  unsigned int y = my_unknown();
  unsigned int z = y;
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
