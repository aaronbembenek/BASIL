// Source: data/benchmarks/sv-benchmarks/loop-zilu/benchmark14_linear.c
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
  if (!(i >= 0 && i <= 200))
    return 0;
  ;
  while (i > 0) {
    i--;
  }
  {
    ;
    my_assert((i >= 0));
  }
  return 0;
  ;
}
