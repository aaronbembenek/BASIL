// Source: data/benchmarks/sv-benchmarks/loop-zilu/benchmark21_disjunctive.c
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
  if (!(y > 0 || x > 0))
    return 0;
  ;
  while (1) {
    if (x + y > -2) {
      break;
    }
    if (x > 0) {
      x++;
    } else {
      y++;
    }
  }
  {
    ;
    my_assert((x > 0 || y > 0));
  }
  return 0;
  ;
}
