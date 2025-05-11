// Source: data/benchmarks/code2inv/132.c
#include <stdlib.h>
#define assume(e)                                                              \
  if (!(e))                                                                    \
    exit(-1);
int __attribute__((noinline)) my_unknown() { return rand(); }
void __attribute__((noinline)) my_assert(int x) {
  while (!x)
    ;
}
extern int unknown(void);
int main() {
  int i = 0;
  int j = (int)my_unknown(), c = (int)my_unknown(), t = (int)my_unknown();
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
