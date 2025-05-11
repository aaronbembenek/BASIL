// Source: data/benchmarks/code2inv/1.c
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
  int x = (int)my_unknown();
  int y = (int)my_unknown();
  (x = 1);
  (y = 0);
  while ((y < 100000)) {
    {
      (x = (x + y));
      (y = (y + 1));
    }
  }
  {
    ;
    my_assert(((x >= y)));
  }
}
