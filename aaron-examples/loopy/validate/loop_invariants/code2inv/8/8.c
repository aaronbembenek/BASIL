// Source: data/benchmarks/code2inv/8.c
#include <stdlib.h>
#define assume(e)                                                              \
  if (!(e))                                                                    \
    exit(-1);
int my_nondet;
int __attribute__((noinline)) my_unknown() { return my_nondet; }
void __attribute__((noinline)) my_assert(int x) {}
int x;
int y;
extern int unknown(void);
int main() {
  ;
  ;
  assume((x >= 0));
  assume((x <= 10));
  assume((y <= 10));
  assume((y >= 0));
  while (my_unknown()) {
    {
      (x = (x + 10));
      (y = (y + 10));
    }
  }
  if ((y == 0)) {
    ;
    my_assert(((x != 20)));
  }
}
