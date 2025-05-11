// Source: data/benchmarks/sv-benchmarks/loop-zilu/benchmark39_conjunctive.c
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
  int y = my_unknown();
  if (!(x == 4 * y && x >= 0))
    return 0;
  ;
  while (x > 0) {
    x -= 4;
    y--;
  }
  {
    ;
    my_assert((y >= 0));
  }
  return 0;
  ;
}
