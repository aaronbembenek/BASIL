// Source: data/benchmarks/code2inv/15.c
#include <stdlib.h>
#define assume(e)                                                              \
  if (!(e))                                                                    \
    exit(-1);
int my_nondet;
int __attribute__((noinline)) my_unknown() { return my_nondet; }
void __attribute__((noinline)) my_assert(int x) {}
int x;
int m;
int n;
extern int unknown(void);
int main() {
  x = 0;
  m = 0;
  ;
  while (x < n) {
    if (my_unknown()) {
      m = x;
    }
    x = x + 1;
  }
  if (n > 0) {
    {
      ;
      my_assert((m < n));
    }
  }
}
