// Source: data/benchmarks/code2inv/39.c
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
  int n = (int)my_unknown();
  int c = 0;
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
