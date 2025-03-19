// Source: data/benchmarks/code2inv/109.c
#include <stdlib.h>
#define assume(e)                                                              \
  if (!(e))                                                                    \
    exit(-1);
int my_nondet;
int __attribute__((noinline)) my_unknown() { return my_nondet; }
void __attribute__((noinline)) my_assert(int x) {}
int a;
int c;
int m;
int j;
int k;
int main() {
  ;
  j = 0;
  k = 0;
  while (k < c) {
    if (m < a) {
      m = a;
    }
    k = k + 1;
  }
  if (c > 0) {
    {
      ;
      my_assert((a <= m));
    }
  }
}
