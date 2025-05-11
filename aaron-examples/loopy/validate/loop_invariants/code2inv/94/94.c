// Source: data/benchmarks/code2inv/94.c
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
  int k = (int)my_unknown();
  int n = (int)my_unknown();
  assume((k >= 0));
  assume((n >= 0));
  (i = 0);
  (j = 0);
  while ((i <= n)) {
    {
      (i = (i + 1));
      (j = (j + i));
    }
  }
  {
    ;
    my_assert((((i + (j + k)) > (2 * n))));
  }
}
