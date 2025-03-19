// Source: data/benchmarks/code2inv/112.c
#include <stdlib.h>
#define assume(e)                                                              \
  if (!(e))                                                                    \
    exit(-1);
int my_nondet;
int __attribute__((noinline)) my_unknown() { return my_nondet; }
void __attribute__((noinline)) my_assert(int x) {}
int i;
int n;
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
  while ((i <= n)) {
    {
      (i = (i + 1));
      (sn = (sn + 1));
    }
  }
  if ((sn != n)) {
    ;
    my_assert(((sn == 0)));
  }
}
