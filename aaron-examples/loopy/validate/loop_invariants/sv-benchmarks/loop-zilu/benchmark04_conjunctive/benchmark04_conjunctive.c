// Source: data/benchmarks/sv-benchmarks/loop-zilu/benchmark04_conjunctive.c
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
#include <assert.h>
int main() {
  int k = my_unknown();
  int j = my_unknown();
  int n = my_unknown();
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
