// Source: data/benchmarks/LinearArbitrary-SeaHorn/pie/ICE/benchmarks/cegar2.v.c
#include <stdlib.h>
#define assume(e)                                                              \
  if (!(e))                                                                    \
    exit(-1);
int my_nondet;
int __attribute__((noinline)) my_unknown() { return my_nondet; }
void __attribute__((noinline)) my_assert(int x) {}
int N;
int x;
int m;
int input;
int v1;
int v2;
int v3;
extern int unknown_int(void);
int main() {
  N = my_unknown();
  x = 0;
  m = 0;
  ;
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
