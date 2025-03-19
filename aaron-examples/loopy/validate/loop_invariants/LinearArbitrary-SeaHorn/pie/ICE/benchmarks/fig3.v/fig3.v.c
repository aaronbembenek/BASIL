// Source: data/benchmarks/LinearArbitrary-SeaHorn/pie/ICE/benchmarks/fig3.v.c
#include <stdlib.h>
#define assume(e)                                                              \
  if (!(e))                                                                    \
    exit(-1);
int my_nondet;
int __attribute__((noinline)) my_unknown() { return my_nondet; }
void __attribute__((noinline)) my_assert(int x) {}
int y;
int lock;
int v1;
int v2;
int v3;
int x;
int input;
extern int unknown_int(void);
int main() {
  y = my_unknown();
  ;
  lock = 0;
  x = my_unknown();
  ;
  {
    lock = 1;
    x = y;
    input = my_unknown();
    if (input) {
      lock = 0;
      y = y + 1;
    }
    v1 = my_unknown();
    v2 = my_unknown();
    v3 = my_unknown();
  }
  while (x != y) {
    lock = 1;
    x = y;
    input = my_unknown();
    if (input) {
      lock = 0;
      y = y + 1;
    }
    v1 = my_unknown();
    v2 = my_unknown();
    v3 = my_unknown();
  }
  {
    ;
    my_assert((lock == 1));
  }
}
