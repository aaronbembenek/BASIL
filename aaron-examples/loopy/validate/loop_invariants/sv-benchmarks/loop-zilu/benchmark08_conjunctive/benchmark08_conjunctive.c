// Source: data/benchmarks/sv-benchmarks/loop-zilu/benchmark08_conjunctive.c
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
#include <assert.h>
int main() {
  n = my_unknown();
  sum = my_unknown();
  i = my_unknown();
  if (!(n >= 0 && sum == 0 && i == 0))
    return 0;
  ;
  while (i < n) {
    sum = sum + i;
    i++;
  }
  {
    ;
    my_assert((sum >= 0));
  }
  return 0;
  ;
}
