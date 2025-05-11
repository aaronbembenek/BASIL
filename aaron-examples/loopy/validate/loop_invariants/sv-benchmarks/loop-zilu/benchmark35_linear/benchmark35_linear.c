// Source: data/benchmarks/sv-benchmarks/loop-zilu/benchmark35_linear.c
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
  int x = my_unknown();
  if (!(x >= 0))
    return 0;
  ;
  while ((x >= 0) && (x < 10)) {
    x = x + 1;
  }
  {
    ;
    my_assert((x >= 10));
  }
  return 0;
  ;
}
