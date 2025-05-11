// Source: data/benchmarks/code2inv/90.c
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
  int lock = (int)my_unknown();
  int v1 = (int)my_unknown();
  int v2 = (int)my_unknown();
  int v3 = (int)my_unknown();
  int x = (int)my_unknown();
  int y = (int)my_unknown();
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
