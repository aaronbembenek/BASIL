// Source: data/benchmarks/code2inv/129.c
#include <stdlib.h>
#define assume(e)                                                              \
  if (!(e))                                                                    \
    exit(-1);
int my_nondet;
int __attribute__((noinline)) my_unknown() { return my_nondet; }
void __attribute__((noinline)) my_assert(int x) {}
int x;
int y;
int z1;
int z2;
int z3;
int main() {
  ;
  ;
  ;
  ;
  ;
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
