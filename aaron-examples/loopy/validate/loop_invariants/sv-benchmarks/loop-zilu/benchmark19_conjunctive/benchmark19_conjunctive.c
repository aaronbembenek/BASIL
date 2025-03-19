// Source: data/benchmarks/sv-benchmarks/loop-zilu/benchmark19_conjunctive.c
#include <stdlib.h>
#define assume(e)                                                              \
  if (!(e))                                                                    \
    exit(-1);
int my_nondet;
int __attribute__((noinline)) my_unknown() { return my_nondet; }
void __attribute__((noinline)) my_assert(int x) {}
int j;
int k;
int n;
extern int unknown_int(void);
#include <assert.h>
int main() {
  j = my_unknown();
  k = my_unknown();
  n = my_unknown();
  if (!((j == n) && (k == n) && (n > 0)))
    return 0;
  ;
  while (j > 0 && n > 0) {
    j--;
    k--;
  }
  {
    ;
    my_assert(((k == 0)));
  }
  return 0;
  ;
}
