// Source: data/benchmarks/sv-benchmarks/loops-crafted-1/sumt4.c
#include <stdlib.h>
#define assume(e)                                                              \
  if (!(e))                                                                    \
    exit(-1);
int my_nondet;
int __attribute__((noinline)) my_unknown() { return my_nondet; }
void __attribute__((noinline)) my_assert(int x) {}
unsigned int n;
unsigned int i;
unsigned int k;
unsigned int j;
unsigned int l;
unsigned int v4;
extern unsigned int unknown_uint(void);
int SIZE = 20000001;
int main() {
  n = 0, i = 0, k = 0, j = 0, l = 0;
  v4 = 0;
  n = my_unknown();
  if (!(n <= SIZE))
    return 0;
  ;
  while (l < n) {
    if (!(l % 4))
      v4 = v4 + 1;
    else if (!(l % 3))
      i = i + 1;
    else if (!(l % 2))
      j = j + 1;
    else
      k = k + 1;
    l = l + 1;
  }
  {
    ;
    my_assert(((i + j + k + v4) == l));
  }
  return 0;
  ;
}
