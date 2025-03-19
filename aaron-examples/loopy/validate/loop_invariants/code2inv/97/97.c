// Source: data/benchmarks/code2inv/97.c
#include <stdlib.h>
#define assume(e)                                                              \
  if (!(e))                                                                    \
    exit(-1);
int my_nondet;
int __attribute__((noinline)) my_unknown() { return my_nondet; }
void __attribute__((noinline)) my_assert(int x) {}
int i;
int j;
int x;
int y;
int main() {
  ;
  ;
  ;
  ;
  (j = 0);
  (i = 0);
  (y = 2);
  while ((i <= x)) {
    {
      (i = (i + 1));
      (j = (j + y));
    }
  }
  if ((y == 1)) {
    ;
    my_assert(((i == j)));
  }
}
