// Source: data/benchmarks/code2inv/121.c
#include <stdlib.h>
#define assume(e)                                                              \
  if (!(e))                                                                    \
    exit(-1);
int my_nondet;
int __attribute__((noinline)) my_unknown() { return my_nondet; }
void __attribute__((noinline)) my_assert(int x) {}
int i;
int sn;
int main() {
  ;
  ;
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
