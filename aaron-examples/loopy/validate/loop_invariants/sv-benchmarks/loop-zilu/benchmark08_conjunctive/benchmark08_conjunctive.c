// Source: data/benchmarks/sv-benchmarks/loop-zilu/benchmark08_conjunctive.c
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
  int n = my_unknown();
  int sum = my_unknown();
  int i = my_unknown();
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
