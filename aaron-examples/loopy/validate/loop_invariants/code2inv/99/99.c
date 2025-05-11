// Source: data/benchmarks/code2inv/99.c
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
  int n = (int)my_unknown();
  int x = (int)my_unknown();
  int y = (int)my_unknown();
  assume((n >= 0));
  (x = n);
  (y = 0);
  while ((x > 0)) {
    {
      (y = (y + 1));
      (x = (x - 1));
    }
  }
  {
    ;
    my_assert(((n == (x + y))));
  }
}
