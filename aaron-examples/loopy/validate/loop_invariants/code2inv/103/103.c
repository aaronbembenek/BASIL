// Source: data/benchmarks/code2inv/103.c
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
  (x = 0);
  while ((x < 100)) {
    {
      (x = (x + 1));
    }
  }
  {
    ;
    my_assert(((x == 100)));
  }
}
