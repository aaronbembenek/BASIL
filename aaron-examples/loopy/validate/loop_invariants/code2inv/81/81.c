// Source: data/benchmarks/code2inv/81.c
#include <stdlib.h>
#define assume(e)                                                              \
  if (!(e))                                                                    \
    exit(-1);
int my_nondet;
int __attribute__((noinline)) my_unknown() { return my_nondet; }
void __attribute__((noinline)) my_assert(int x) {}
int i;
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
  ;
  (i = 0);
  assume((x >= 0));
  assume((y >= 0));
  assume((x >= y));
  while (my_unknown()) {
    if ((i < y)) {
      (i = (i + 1));
    }
  }
  if ((i < y)) {
    ;
    my_assert(((0 <= i)));
  }
}
