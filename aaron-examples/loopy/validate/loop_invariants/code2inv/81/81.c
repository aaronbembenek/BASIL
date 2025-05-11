// Source: data/benchmarks/code2inv/81.c
#include <stdlib.h>
#define assume(e)                                                              \
  if (!(e))                                                                    \
    exit(-1);
int __attribute__((noinline)) my_unknown() { return rand(); }
void __attribute__((noinline)) my_assert(int x) {
  while (!x)
    ;
}
extern int unknown(void);
int main() {
  int i = (int)my_unknown();
  int x = (int)my_unknown();
  int y = (int)my_unknown();
  int z1 = (int)my_unknown();
  int z2 = (int)my_unknown();
  int z3 = (int)my_unknown();
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
