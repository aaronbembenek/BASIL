// Source: data/benchmarks/code2inv/104.c
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
  int v1 = (int)my_unknown();
  int v2 = (int)my_unknown();
  int v3 = (int)my_unknown();
  int x = (int)my_unknown();
  (x = 0);
  while ((x < n)) {
    {
      (x = (x + 1));
    }
  }
  if ((x != n)) {
    ;
    my_assert(((n < 0)));
  }
}
