// Source: data/benchmarks/sv-benchmarks/loop-acceleration/simple_3-2.c
#include <stdlib.h>
#define assume(e)                                                              \
  if (!(e))                                                                    \
    exit(-1);
int my_nondet;
int __attribute__((noinline)) my_unknown() { return my_nondet; }
void __attribute__((noinline)) my_assert(int x) {}
unsigned int x;
unsigned short N;
extern unsigned short unknown_ushort(void);
int main() {
  x = 0;
  N = my_unknown();
  while (x < N) {
    x += 2;
  }
  {
    ;
    my_assert((!(x % 2)));
  }
}
