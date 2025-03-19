// Source: data/benchmarks/code2inv/39.c
#include <stdlib.h>
#define assume(e)                                                              \
  if (!(e))                                                                    \
    exit(-1);
int my_nondet;
int __attribute__((noinline)) my_unknown() { return my_nondet; }
void __attribute__((noinline)) my_assert(int x) {}
int n;
int c;
extern int unknown(void);
int main() {
  ;
  c = 0;
  assume(n > 0);
  while (my_unknown()) {
    if (c == n) {
      c = 1;
    } else {
      c = c + 1;
    }
  }
  if (c == n) {
    {
      ;
      my_assert((c <= n));
    }
  }
}
