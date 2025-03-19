// Source: data/benchmarks/code2inv/63.c
#include <stdlib.h>
#define assume(e)                                                              \
  if (!(e))                                                                    \
    exit(-1);
int my_nondet;
int __attribute__((noinline)) my_unknown() { return my_nondet; }
void __attribute__((noinline)) my_assert(int x) {}
int x;
int y;
int main() {
  x = 1;
  ;
  while (x <= 10) {
    y = 10 - x;
    x = x + 1;
  }
  {
    ;
    my_assert((y >= 0));
  }
}
