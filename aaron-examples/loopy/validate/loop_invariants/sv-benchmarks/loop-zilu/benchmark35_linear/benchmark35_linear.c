// Source: data/benchmarks/sv-benchmarks/loop-zilu/benchmark35_linear.c
#include <stdlib.h>
#define assume(e)                                                              \
  if (!(e))                                                                    \
    exit(-1);
int my_nondet;
int __attribute__((noinline)) my_unknown() { return my_nondet; }
void __attribute__((noinline)) my_assert(int x) {}
int x;
extern int unknown_int(void);
#include <assert.h>
int main() {
  x = my_unknown();
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
