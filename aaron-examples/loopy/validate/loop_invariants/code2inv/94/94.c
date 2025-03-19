// Source: data/benchmarks/code2inv/94.c
#include <stdlib.h>
#define assume(e)                                                              \
  if (!(e))                                                                    \
    exit(-1);
int my_nondet;
int __attribute__((noinline)) my_unknown() { return my_nondet; }
void __attribute__((noinline)) my_assert(int x) {}
int i;
int j;
int k;
int n;
int main() {
  ;
  ;
  ;
  ;
  assume((k >= 0));
  assume((n >= 0));
  (i = 0);
  (j = 0);
  while ((i <= n)) {
    {
      (i = (i + 1));
      (j = (j + i));
    }
  }
  {
    ;
    my_assert((((i + (j + k)) > (2 * n))));
  }
}
