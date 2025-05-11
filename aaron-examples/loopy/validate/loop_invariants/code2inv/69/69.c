// Source: data/benchmarks/code2inv/69.c
#include <stdlib.h>
#define assume(e)                                                              \
  if (!(e))                                                                    \
    exit(-1);
int __attribute__((noinline)) my_unknown() { return rand(); }
void __attribute__((noinline)) my_assert(int x) {
  while (!x)
    ;
}
int main() {
  int n = (int)my_unknown(), v1 = (int)my_unknown(), v2 = (int)my_unknown(),
      v3 = (int)my_unknown();
  int x = 1;
  int y = (int)my_unknown();
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
