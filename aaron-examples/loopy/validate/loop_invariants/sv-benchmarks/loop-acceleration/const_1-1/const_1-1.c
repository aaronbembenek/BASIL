// Source: data/benchmarks/sv-benchmarks/loop-acceleration/const_1-1.c
#include <stdlib.h>
#define assume(e)                                                              \
  if (!(e))                                                                    \
    exit(-1);
int my_nondet;
int __attribute__((noinline)) my_unknown() { return my_nondet; }
void __attribute__((noinline)) my_assert(int x) {}
unsigned int x;
unsigned int y;
int main() {
  x = 1;
  y = 0;
  while (y < 1024) {
    x = 0;
    y++;
  }
  {
    ;
    my_assert((x == 0));
  }
}
