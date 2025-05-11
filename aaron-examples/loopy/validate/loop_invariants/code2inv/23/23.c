// Source: data/benchmarks/code2inv/23.c
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
  (i = 1);
  (j = 20);
  while ((j >= i)) {
    {
      (i = (i + 2));
      (j = (j - 1));
    }
  }
  {
    ;
    my_assert(((j == 13)));
  }
}
