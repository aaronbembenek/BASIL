// Source: data/benchmarks/code2inv/71.c
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
  int c = (int)my_unknown();
  int y = (int)my_unknown();
  int z = (int)my_unknown();
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
