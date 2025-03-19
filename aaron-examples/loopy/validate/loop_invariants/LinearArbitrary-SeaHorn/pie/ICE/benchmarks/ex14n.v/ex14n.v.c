// Source: data/benchmarks/LinearArbitrary-SeaHorn/pie/ICE/benchmarks/ex14n.v.c
#include <stdlib.h>
#define assume(e)                                                              \
  if (!(e))                                                                    \
    exit(-1);
int my_nondet;
int __attribute__((noinline)) my_unknown() { return my_nondet; }
void __attribute__((noinline)) my_assert(int x) {}
int x;
int y;
int N;
int v1;
int v2;
int v3;
extern int unknown_int(void);
int main() {
  ;
  x = 1;
  N = my_unknown();
  while (x <= N) {
    y = N - x;
    if (y < 0 || y >= N) {
      ;
      my_assert((0 == 1));
    }
    x++;
    v1 = v2;
    v2 = v3;
    v3 = v1;
  }
  return 1;
  ;
}
