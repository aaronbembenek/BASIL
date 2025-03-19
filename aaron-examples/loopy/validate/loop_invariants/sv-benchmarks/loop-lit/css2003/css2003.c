// Source: data/benchmarks/sv-benchmarks/loop-lit/css2003.c
#include <stdlib.h>
#define assume(e)                                                              \
  if (!(e))                                                                    \
    exit(-1);
int my_nondet;
int __attribute__((noinline)) my_unknown() { return my_nondet; }
void __attribute__((noinline)) my_assert(int x) {}
int i;
int j;
int k;
#define LARGE_INT 1000000
extern int unknown_int(void);
int main() {
  ;
  i = 1;
  j = 1;
  k = my_unknown();
  if (!(0 <= k && k <= 1))
    return 0;
  ;
  while (i < LARGE_INT) {
    i = i + 1;
    j = j + k;
    k = k - 1;
    {
      ;
      my_assert((1 <= i + k && i + k <= 2 && i >= 1));
    }
  }
  return 0;
  ;
}
