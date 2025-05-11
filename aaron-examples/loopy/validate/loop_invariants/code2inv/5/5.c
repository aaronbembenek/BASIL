// Source: data/benchmarks/code2inv/5.c
#include <stdlib.h>
#define assume(e)                                                              \
  if (!(e))                                                                    \
    exit(-1);
int __attribute__((noinline)) my_unknown() { return rand(); }
void __attribute__((noinline)) my_assert(int x) {
  while (!x)
    ;
}
int main() {
  int x = 0;
  int size = (int)my_unknown();
  int y = (int)my_unknown(), z = (int)my_unknown();
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
