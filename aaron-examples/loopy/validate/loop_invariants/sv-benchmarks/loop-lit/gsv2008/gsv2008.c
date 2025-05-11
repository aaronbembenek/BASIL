// Source: data/benchmarks/sv-benchmarks/loop-lit/gsv2008.c
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
  int x = (int)my_unknown(), y = (int)my_unknown();
  x = -50;
  y = my_unknown();
  if (!(-1000 < y && y < LARGE_INT))
    return 0;
  ;
  while (x < 0) {
    x = x + y;
    y++;
  }
  {
    ;
    my_assert((y > 0));
  }
  return 0;
  ;
}
