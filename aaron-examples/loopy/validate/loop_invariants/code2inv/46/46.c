// Source: data/benchmarks/code2inv/46.c
#include <stdlib.h>
#define assume(e)                                                              \
  if (!(e))                                                                    \
    exit(-1);
int my_nondet;
int __attribute__((noinline)) my_unknown() { return my_nondet; }
void __attribute__((noinline)) my_assert(int x) {}
int c;
int n;
extern int unknown(void);
int main() {
  ;
  ;
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
  if ((c != n)) {
    ;
    my_assert(((c <= n)));
  }
}
