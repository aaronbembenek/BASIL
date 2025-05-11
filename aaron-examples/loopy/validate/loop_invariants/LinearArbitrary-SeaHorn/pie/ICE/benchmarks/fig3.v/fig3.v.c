// Source: data/benchmarks/LinearArbitrary-SeaHorn/pie/ICE/benchmarks/fig3.v.c
#include <stdlib.h>
#define assume(e)                                                              \
  if (!(e))                                                                    \
    exit(-1);
int __attribute__((noinline)) my_unknown() { return rand(); }
void __attribute__((noinline)) my_assert(int x) {
  while (!x)
    ;
}
extern int unknown_int(void);
int main() {
  int y = my_unknown();
  int lock = (int)my_unknown(), v1 = (int)my_unknown(), v2 = (int)my_unknown(),
      v3 = (int)my_unknown();
  lock = 0;
  int x = my_unknown();
  int input = (int)my_unknown();
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
