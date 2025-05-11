// Source: data/benchmarks/sv-benchmarks/loops-crafted-1/loopv3.c
#include <stdlib.h>
#define assume(e)                                                              \
  if (!(e))                                                                    \
    exit(-1);
int __attribute__((noinline)) my_unknown() { return rand(); }
void __attribute__((noinline)) my_assert(int x) {
  while (!x)
    ;
}
extern int unknown_int(void);
int SIZE = 50000001;
int main() {
  int i = (int)my_unknown(), j = (int)my_unknown();
  i = 0;
  j = 0;
  while (i < SIZE) {
    if (my_unknown())
      i = i + 8;
    else
      i = i + 4;
  }
  j = i / 4;
  {
    ;
    my_assert(((j * 4) == i));
  }
  return 0;
  ;
}
