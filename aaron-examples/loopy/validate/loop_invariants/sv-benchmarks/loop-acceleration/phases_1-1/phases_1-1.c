// Source: data/benchmarks/sv-benchmarks/loop-acceleration/phases_1-1.c
#include <stdlib.h>
#define assume(e)                                                              \
  if (!(e))                                                                    \
    exit(-1);
int my_nondet;
int __attribute__((noinline)) my_unknown() { return my_nondet; }
void __attribute__((noinline)) my_assert(int x) {}
unsigned int x;
int main() {
  x = 0;
  while (x < 0x0fffffff) {
    if (x < 0xfff0) {
      x++;
    } else {
      x += 2;
    }
  }
  {
    ;
    my_assert((!(x % 2)));
  }
}
