// Source: data/benchmarks/code2inv/107.c
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
  int a = (int)my_unknown(), m = (int)my_unknown(), j = (int)my_unknown(),
      k = (int)my_unknown();
  j = 0;
  k = 0;
  while (k < 1) {
    if (m < a) {
      m = a;
    }
    k = k + 1;
  }
  {
    ;
    my_assert((a <= m));
  }
}
