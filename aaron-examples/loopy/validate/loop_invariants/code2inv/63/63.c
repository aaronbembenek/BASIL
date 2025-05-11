// Source: data/benchmarks/code2inv/63.c
#include <stdlib.h>
#define assume(e)                                                              \
  if (!(e))                                                                    \
    exit(-1);
int __attribute__((noinline)) my_unknown() { return rand(); }
void __attribute__((noinline)) my_assert(int x) {
  while (!x)
    ;
}
int main() {
  int x = 1;
  int y = (int)my_unknown();
  while (x <= 10) {
    y = 10 - x;
    x = x + 1;
  }
  {
    ;
    my_assert((y >= 0));
  }
}
