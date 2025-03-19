// Source: data/benchmarks/sv-benchmarks/loop-new/gauss_sum.c
#include <stdlib.h>
#define assume(e)                                                              \
  if (!(e))                                                                    \
    exit(-1);
int my_nondet;
int __attribute__((noinline)) my_unknown() { return my_nondet; }
void __attribute__((noinline)) my_assert(int x) {}
int n;
int sum;
int i;
extern int unknown_int(void);
int main() {
  ;
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
