// Source: data/benchmarks/code2inv/60.c
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
  int c = (int)my_unknown();
  int n = (int)my_unknown();
  int v1 = (int)my_unknown();
  int v2 = (int)my_unknown();
  int v3 = (int)my_unknown();
  (c = 0);
  assume((n > 0));
  while (my_unknown()) {
    {
      if (my_unknown()) {
        if ((c != n)) {
          (c = (c + 1));
        }
      } else {
        if ((c == n)) {
          (c = 1);
        }
      }
    }
  }
  if ((c < 0))
    if ((c > n)) {
      ;
      my_assert(((c == n)));
    }
}
