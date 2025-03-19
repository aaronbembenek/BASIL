// Source: data/benchmarks/code2inv/132.c
#include <stdlib.h>
#define assume(e)                                                              \
  if (!(e))                                                                    \
    exit(-1);
int my_nondet;
int __attribute__((noinline)) my_unknown() { return my_nondet; }
void __attribute__((noinline)) my_assert(int x) {}
int i;
int j;
int c;
int t;
extern int unknown(void);
int main() {
  i = 0;
  ;
  while (my_unknown()) {
    if (c > 48) {
      if (c < 57) {
        j = i + i;
        t = c - 48;
        i = j + t;
      }
    }
  }
  {
    ;
    my_assert((i >= 0));
  }
}
