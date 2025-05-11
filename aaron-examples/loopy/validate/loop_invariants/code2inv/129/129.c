// Source: data/benchmarks/code2inv/129.c
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
  int x = (int)my_unknown();
  int y = (int)my_unknown();
  int z1 = (int)my_unknown();
  int z2 = (int)my_unknown();
  int z3 = (int)my_unknown();
  (x = 1);
  while ((x < y)) {
    {
      (x = (x + x));
    }
  }
  {
    ;
    my_assert(((x >= 1)));
  }
}
