// Source: data/benchmarks/LinearArbitrary-SeaHorn/pie/ICE/benchmarks/incn.v.c
#include <stdlib.h>
#define assume(e)                                                              \
  if (!(e))                                                                    \
    exit(-1);
int my_nondet;
int __attribute__((noinline)) my_unknown() { return my_nondet; }
void __attribute__((noinline)) my_assert(int x) {}
int x;
int N;
int v1;
int v2;
int v3;
extern int unknown_int(void);
int main() {
  ;
  x = 0;
  N = my_unknown();
  while (x < N) {
    x = x + 1;
    v1 = my_unknown();
    v2 = my_unknown();
    v3 = my_unknown();
  }
  {
    ;
    my_assert((N < 0 || x == N));
  }
}
