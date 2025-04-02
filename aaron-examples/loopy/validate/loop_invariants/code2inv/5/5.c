// Source: data/benchmarks/code2inv/5.c
#include <stdlib.h>
#define assume(e)                                                              \
  if (!(e))                                                                    \
    exit(-1);
int my_nondet;
int __attribute__((noinline)) my_unknown() { return my_nondet; }
void __attribute__((noinline)) my_assert(int x) {}
int main() {
  int x = 0;
  int size;
  int y, z;
  while (x < size) {
    x += 1;
    if (z <= y) {
      y = z;
    }
  }
  if (size > 0) {
    {
      ;
      my_assert((z >= y));
    }
  }
}
