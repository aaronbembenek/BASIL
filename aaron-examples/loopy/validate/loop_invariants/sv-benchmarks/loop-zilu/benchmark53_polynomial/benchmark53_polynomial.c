// Source: data/benchmarks/sv-benchmarks/loop-zilu/benchmark53_polynomial.c
#include <stdlib.h>
#define assume(e)                                                              \
  if (!(e))                                                                    \
    exit(-1);
int my_nondet;
int __attribute__((noinline)) my_unknown() { return my_nondet; }
void __attribute__((noinline)) my_assert(int x) {}
int x;
int y;
extern int unknown_int(void);
extern _Bool unknown_bool(void);
#include <assert.h>
int main() {
  x = my_unknown();
  y = my_unknown();
  if (!(x * y >= 0))
    return 0;
  ;
  while (my_unknown()) {
    if (x == 0) {
      if (y > 0)
        x++;
      else
        x--;
    }
    if (x > 0)
      y++;
    else
      x--;
  }
  {
    ;
    my_assert((x * y >= 0));
  }
  return 0;
  ;
}
