// Source: data/benchmarks/code2inv/15.c
#include <stdlib.h>
#define assume(e)                                                              \
  if (!(e))                                                                    \
    exit(-1);
int __attribute__((noinline)) my_unknown() { return rand(); }
void __attribute__((noinline)) my_assert(int x) {
  while (!x)
    ;
}
extern int unknown(void);
int main() {
  int x = 0;
  int m = 0;
  int n = (int)my_unknown();
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
