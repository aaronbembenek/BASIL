// Source: data/benchmarks/sv-benchmarks/loop-lit/cggmp2005_variant.c
#include <stdlib.h>
#define assume(e)                                                              \
  if (!(e))                                                                    \
    exit(-1);
int my_nondet;
int __attribute__((noinline)) my_unknown() { return my_nondet; }
void __attribute__((noinline)) my_assert(int x) {}
int lo;
int mid;
int hi;
#define LARGE_INT 1000000
extern int unknown_int(void);
int main() {
  ;
  lo = 0;
  mid = my_unknown();
  if (!(mid > 0 && mid <= LARGE_INT))
    return 0;
  ;
  hi = 2 * mid;
  while (mid > 0) {
    lo = lo + 1;
    hi = hi - 1;
    mid = mid - 1;
  }
  {
    ;
    my_assert((lo == hi));
  }
  return 0;
  ;
}
