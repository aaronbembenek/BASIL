// Source: data/benchmarks/LinearArbitrary-SeaHorn/pie/ICE/benchmarks/fig3.v.c
#include <stdlib.h>
#define assume(e)                                                              \
  if (!(e))                                                                    \
    exit(-1);
int my_nondet;
int __attribute__((noinline)) my_unknown() { return my_nondet; }
void __attribute__((noinline)) my_assert(int x) {}
extern int unknown_int(void);
int main() {
  int y = my_unknown();
  int lock, v1, v2, v3;
  lock = 0;
  int x = my_unknown();
  int input;
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
