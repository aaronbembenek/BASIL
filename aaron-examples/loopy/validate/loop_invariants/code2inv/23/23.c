// Source: data/benchmarks/code2inv/23.c
#include <stdlib.h>
#define assume(e)                                                              \
  if (!(e))                                                                    \
    exit(-1);
int my_nondet;
int __attribute__((noinline)) my_unknown() { return my_nondet; }
void __attribute__((noinline)) my_assert(int x) {}
int i;
int j;
int main() {
  ;
  ;
  (i = 1);
  (j = 20);
  while ((j >= i)) {
    {
      (i = (i + 2));
      (j = (j - 1));
    }
  }
  {
    ;
    my_assert(((j == 13)));
  }
}
