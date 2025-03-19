// Source: data/benchmarks/sv-benchmarks/loop-acceleration/diamond_2-2.c
#include <stdlib.h>
#define assume(e)                                                              \
  if (!(e))                                                                    \
    exit(-1);
int my_nondet;
int __attribute__((noinline)) my_unknown() { return my_nondet; }
void __attribute__((noinline)) my_assert(int x) {}
unsigned int x;
unsigned int y;
extern unsigned int unknown_uint(void);
int main() {
  x = 0;
  y = my_unknown();
  while (x < 99) {
    if (y % 2 == 0)
      x += 2;
    else
      x++;
    if (y % 2 == 0)
      x += 2;
    else
      x -= 2;
    if (y % 2 == 0)
      x += 2;
    else
      x += 2;
    if (y % 2 == 0)
      x += 2;
    else
      x -= 2;
    if (y % 2 == 0)
      x += 2;
    else
      x += 2;
    if (y % 2 == 0)
      x += 2;
    else
      x -= 4;
    if (y % 2 == 0)
      x += 2;
    else
      x += 4;
    if (y % 2 == 0)
      x += 2;
    else
      x += 2;
    if (y % 2 == 0)
      x += 2;
    else
      x -= 4;
    if (y % 2 == 0)
      x += 2;
    else
      x -= 4;
  }
  {
    ;
    my_assert(((x % 2) == (y % 2)));
  }
}
