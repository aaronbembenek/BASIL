// Source: data/benchmarks/sv-benchmarks/loop-zilu/benchmark04_conjunctive.c
#include <stdlib.h>
#define assume(e)                                                              \
  if (!(e))                                                                    \
    exit(-1);
int my_nondet;
int __attribute__((noinline)) my_unknown() { return my_nondet; }
void __attribute__((noinline)) my_assert(int x) {}
int k;
int j;
int n;
extern int unknown_int(void);
#include <assert.h>
int main() {
  k = my_unknown();
  j = my_unknown();
  n = my_unknown();
  if (!(n >= 1 && k >= n && j == 0))
    return 0;
  ;
  while (j <= n - 1) {
    j++;
    k--;
  }
  {
    ;
    my_assert((k >= 0));
  }
  return 0;
  ;
}
