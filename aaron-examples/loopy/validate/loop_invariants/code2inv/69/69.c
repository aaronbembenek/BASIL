// Source: data/benchmarks/code2inv/69.c
#include <stdlib.h>
#define assume(e)                                                              \
  if (!(e))                                                                    \
    exit(-1);
int my_nondet;
int __attribute__((noinline)) my_unknown() { return my_nondet; }
void __attribute__((noinline)) my_assert(int x) {}
int main() {
  int n, v1, v2, v3;
  int x = 1;
  int y;
  while (x <= n) {
    y = n - x;
    x = x + 1;
  }
  if (n > 0) {
    {
      ;
      my_assert((y >= 0));
    }
  }
}
