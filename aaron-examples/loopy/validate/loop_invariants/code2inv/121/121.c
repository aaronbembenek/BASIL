// Source: data/benchmarks/code2inv/121.c
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
  int sn = (int)my_unknown();
  (sn = 0);
  (i = 1);
  while ((i <= 8)) {
    {
      (i = (i + 1));
      (sn = (sn + 1));
    }
  }
  if ((sn != 0)) {
    ;
    my_assert(((sn == 8)));
  }
}
