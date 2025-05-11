// Source: data/benchmarks/sv-benchmarks/loop-zilu/benchmark23_conjunctive.c
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
  int i = my_unknown();
  int j = my_unknown();
  if (!(i == 0 && j == 0))
    return 0;
  ;
  while (i < 100) {
    j += 2;
    i++;
  }
  {
    ;
    my_assert((j == 200));
  }
  return 0;
  ;
}
