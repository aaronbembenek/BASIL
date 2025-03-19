// Source: data/benchmarks/code2inv/90.c
#include <stdlib.h>
#define assume(e)                                                              \
  if (!(e))                                                                    \
    exit(-1);
int my_nondet;
int __attribute__((noinline)) my_unknown() { return my_nondet; }
void __attribute__((noinline)) my_assert(int x) {}
int lock;
int v1;
int v2;
int v3;
int x;
int y;
extern int unknown(void);
int main() {
  ;
  ;
  ;
  ;
  ;
  ;
  (y = (x + 1));
  (lock = 0);
  while ((x != y)) {
    {
      if (my_unknown()) {
        {
          (lock = 1);
          (x = y);
        }
      } else {
        {
          (lock = 0);
          (x = y);
          (y = (y + 1));
        }
      }
    }
  }
  {
    ;
    my_assert(((lock == 1)));
  }
}
