// Source: data/benchmarks/sv-benchmarks/loop-zilu/benchmark51_polynomial.c
#include <stdlib.h>
#define assume(e)                                                              \
  if (!(e))                                                                    \
    exit(-1);
int my_nondet;
int __attribute__((noinline)) my_unknown() { return my_nondet; }
void __attribute__((noinline)) my_assert(int x) {}
int x;
extern int unknown_int(void);
extern _Bool unknown_bool(void);
#include <assert.h>
int main() {
  x = my_unknown();
  if (!((x >= 0) && (x <= 50)))
    return 0;
  ;
  while (my_unknown()) {
    if (x > 50)
      x++;
    if (x == 0) {
      x++;
    } else
      x--;
  }
  {
    ;
    my_assert(((x >= 0) && (x <= 50)));
  }
  return 0;
  ;
}
