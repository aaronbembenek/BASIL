// Source: data/benchmarks/sv-benchmarks/loop-lit/cggmp2005_variant.c
#include <stdlib.h>
#define assume(e)                                                              \
  if (!(e))                                                                    \
    exit(-1);
int __attribute__((noinline)) my_unknown() { return rand(); }
void __attribute__((noinline)) my_assert(int x) {
  while (!x)
    ;
}
#define LARGE_INT 1000000
extern int unknown_int(void);
int main() {
  int lo = (int)my_unknown(), mid = (int)my_unknown(), hi = (int)my_unknown();
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
