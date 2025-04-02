// Source: data/benchmarks/LinearArbitrary-SeaHorn/pie/ICE/benchmarks/cegar2.v.c
#include <stdlib.h>
#define assume(e)                                                              \
  if (!(e))                                                                    \
    exit(-1);
int my_nondet;
int __attribute__((noinline)) my_unknown() { return my_nondet; }
void __attribute__((noinline)) my_assert(int x) {}
extern int unknown_int(void);
int main() {
  int N = my_unknown();
  int x = 0;
  int m = 0;
  int input, v1, v2, v3;
  while (x < N) {
    input = my_unknown();
    if (input) {
      m = x;
    }
    x = x + 1;
    v1 = my_unknown();
    v2 = my_unknown();
    v3 = my_unknown();
  }
  if (N > 0) {
    {
      ;
      my_assert(((0 <= m) && (m < N)));
    }
  }
}
