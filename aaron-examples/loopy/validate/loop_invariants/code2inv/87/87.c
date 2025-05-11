// Source: data/benchmarks/code2inv/87.c
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
  int x = (int)my_unknown();
  int y = (int)my_unknown();
  (x = y);
  (lock = 1);
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
