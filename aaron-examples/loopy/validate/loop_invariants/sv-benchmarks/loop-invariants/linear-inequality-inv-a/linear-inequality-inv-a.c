// Source:
// data/benchmarks/sv-benchmarks/loop-invariants/linear-inequality-inv-a.c
#include <stdlib.h>
#define assume(e)                                                              \
  if (!(e))                                                                    \
    exit(-1);
int my_nondet;
int __attribute__((noinline)) my_unknown() { return my_nondet; }
void __attribute__((noinline)) my_assert(int x) {}
unsigned char n;
unsigned char v;
unsigned int s;
unsigned int i;
extern unsigned char unknown_uchar(void);
int main() {
  n = my_unknown();
  if (n == 0) {
    return 0;
    ;
  }
  v = 0;
  s = 0;
  i = 0;
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
