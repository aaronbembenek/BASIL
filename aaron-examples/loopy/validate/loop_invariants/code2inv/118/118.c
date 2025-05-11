// Source: data/benchmarks/code2inv/118.c
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
  int size = (int)my_unknown();
  int sn = (int)my_unknown();
  (sn = 0);
  (i = 1);
  while ((i <= size)) {
    {
      (i = (i + 1));
      (sn = (sn + 1));
    }
  }
  if ((sn != size)) {
    ;
    my_assert(((sn == 0)));
  }
}
