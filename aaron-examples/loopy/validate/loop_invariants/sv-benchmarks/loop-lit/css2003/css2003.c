// Source: data/benchmarks/sv-benchmarks/loop-lit/css2003.c
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
  int i = (int)my_unknown(), j = (int)my_unknown(), k = (int)my_unknown();
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
