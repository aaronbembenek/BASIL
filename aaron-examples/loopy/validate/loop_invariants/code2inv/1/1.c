// Source: data/benchmarks/code2inv/1.c
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
  ;
  ;
  (x = 1);
  (y = 0);
  while ((y < 100000)) {
    {
      (x = (x + y));
      (y = (y + 1));
    }
  }
  {
    ;
    my_assert(((x >= y)));
  }
}
