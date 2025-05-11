// Source: data/benchmarks/sv-benchmarks/loop-new/gauss_sum.c
#include <stdlib.h>
#define assume(e)                                                              \
  if (!(e))                                                                    \
    exit(-1);
int __attribute__((noinline)) my_unknown() { return rand(); }
void __attribute__((noinline)) my_assert(int x) {
  while (!x)
    ;
}
extern int unknown_int(void);
int main() {
  int n = (int)my_unknown(), sum = (int)my_unknown(), i = (int)my_unknown();
  n = my_unknown();
  if (!(1 <= n && n <= 1000))
    return 0;
  ;
  sum = 0;
  for (i = 1; i <= n; i++) {
    sum = sum + i;
  }
  {
    ;
    my_assert((2 * sum == n * (n + 1)));
  }
  return 0;
  ;
}
