// Source:
// data/benchmarks/sv-benchmarks/loop-invariants/linear-inequality-inv-a.c
#include <stdlib.h>
#define assume(e)                                                              \
  if (!(e))                                                                    \
    exit(-1);
int __attribute__((noinline)) my_unknown() { return rand(); }
void __attribute__((noinline)) my_assert(int x) {
  while (!x)
    ;
}
extern unsigned char unknown_uchar(void);
int main() {
  unsigned char n = my_unknown();
  if (n == 0) {
    return 0;
    ;
  }
  unsigned char v = 0;
  unsigned int s = 0;
  unsigned int i = 0;
  while (i < n) {
    v = my_unknown();
    s += v;
    ++i;
  }
  if (s < v) {
    {
      ;
      my_assert((0));
    };
    return 1;
    ;
  }
  if (s > 65025) {
    {
      ;
      my_assert((0));
    };
    return 1;
    ;
  }
  return 0;
  ;
}
