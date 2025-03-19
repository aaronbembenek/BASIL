// Source: data/benchmarks/code2inv/104.c
#include <stdlib.h>
#define assume(e)                                                              \
  if (!(e))                                                                    \
    exit(-1);
int my_nondet;
int __attribute__((noinline)) my_unknown() { return my_nondet; }
void __attribute__((noinline)) my_assert(int x) {}
int n;
int v1;
int v2;
int v3;
int x;
int main() {
  ;
  ;
  ;
  ;
  ;
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
