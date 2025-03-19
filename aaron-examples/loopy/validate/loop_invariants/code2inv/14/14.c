// Source: data/benchmarks/code2inv/14.c
#include <stdlib.h>
#define assume(e)                                                              \
  if (!(e))                                                                    \
    exit(-1);
int my_nondet;
int __attribute__((noinline)) my_unknown() { return my_nondet; }
void __attribute__((noinline)) my_assert(int x) {}
int x;
int y;
int z1;
int z2;
int z3;
extern int unknown(void);
int main() {
  ;
  ;
  ;
  ;
  ;
  assume((x >= 0));
  assume((x <= 2));
  assume((y <= 2));
  assume((y >= 0));
  while (my_unknown()) {
    {
      (x = (x + 2));
      (y = (y + 2));
    }
  }
  if ((y == 0)) {
    ;
    my_assert(((x != 4)));
  }
}
