// Source: data/benchmarks/code2inv/71.c
#include <stdlib.h>
#define assume(e)                                                              \
  if (!(e))                                                                    \
    exit(-1);
int my_nondet;
int __attribute__((noinline)) my_unknown() { return my_nondet; }
void __attribute__((noinline)) my_assert(int x) {}
int c;
int y;
int z;
extern int unknown(void);
int main() {
  ;
  ;
  ;
  (c = 0);
  assume((y >= 0));
  assume((y >= 127));
  (z = (36 * y));
  while (my_unknown()) {
    if ((c < 36)) {
      (z = (z + 1));
      (c = (c + 1));
    }
  }
  if ((c < 36)) {
    ;
    my_assert(((z >= 0)));
  }
}
