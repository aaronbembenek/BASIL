// Source: data/benchmarks/code2inv/100.c
#include <stdlib.h>
#define assume(e)                                                              \
  if (!(e))                                                                    \
    exit(-1);
int my_nondet;
int __attribute__((noinline)) my_unknown() { return my_nondet; }
void __attribute__((noinline)) my_assert(int x) {}
int n;
int x;
int y;
int main() {
  ;
  ;
  ;
  assume((n >= 0));
  (x = n);
  (y = 0);
  while ((x > 0)) {
    {
      (y = (y + 1));
      (x = (x - 1));
    }
  }
  {
    ;
    my_assert(((y == n)));
  }
}
