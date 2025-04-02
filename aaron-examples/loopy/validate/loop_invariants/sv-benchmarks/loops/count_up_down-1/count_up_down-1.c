// Source: data/benchmarks/sv-benchmarks/loops/count_up_down-1.c
#include <stdlib.h>
#define assume(e)                                                              \
  if (!(e))                                                                    \
    exit(-1);
int my_nondet;
int __attribute__((noinline)) my_unknown() { return my_nondet; }
void __attribute__((noinline)) my_assert(int x) {}
extern unsigned int unknown_uint(void);
int main() {
  unsigned int n = my_unknown();
  unsigned int x = n, y = 0;
  while (x > 0) {
    x--;
    y++;
  }
  {
    ;
    my_assert((y == n));
  }
}
