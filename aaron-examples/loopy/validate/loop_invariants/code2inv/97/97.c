// Source: data/benchmarks/code2inv/97.c
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
  int i = (int)my_unknown();
  int j = (int)my_unknown();
  int x = (int)my_unknown();
  int y = (int)my_unknown();
  (j = 0);
  (i = 0);
  (y = 2);
  while ((i <= x)) {
    {
      (i = (i + 1));
      (j = (j + y));
    }
  }
  if ((y == 1)) {
    ;
    my_assert(((i == j)));
  }
}
