// Source: data/benchmarks/sv-benchmarks/loop-acceleration/simple_3-2.c
#include <stdlib.h>
#define assume(e)                                                              \
  if (!(e))                                                                    \
    exit(-1);
int __attribute__((noinline)) my_unknown() { return rand(); }
void __attribute__((noinline)) my_assert(int x) {
  while (!x)
    ;
}
extern unsigned short unknown_ushort(void);
int main() {
  unsigned int x = 0;
  unsigned short N = my_unknown();
  while (x < N) {
    x += 2;
  }
  {
    ;
    my_assert((!(x % 2)));
  }
}
