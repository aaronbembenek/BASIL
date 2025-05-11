// Source: data/benchmarks/code2inv/8.c
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
  int x = (int)my_unknown();
  int y = (int)my_unknown();
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
