// Source: data/benchmarks/code2inv/123.c
#include <stdlib.h>
#define assume(e)                                                              \
  if (!(e))                                                                    \
    exit(-1);
int my_nondet;
int __attribute__((noinline)) my_unknown() { return my_nondet; }
void __attribute__((noinline)) my_assert(int x) {}
int i;
int size;
int sn;
int v1;
int v2;
int v3;
int main() {
  ;
  ;
  ;
  ;
  ;
  ;
  (sn = 0);
  (i = 1);
  while ((i <= size)) {
    {
      (i = (i + 1));
      (sn = (sn + 1));
    }
  }
  if ((sn != 0)) {
    ;
    my_assert(((sn == size)));
  }
}
