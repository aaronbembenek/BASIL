// Source: data/benchmarks/sv-benchmarks/loop-invariants/const.c
#include <stdlib.h>
#define assume(e)                                                              \
  if (!(e))                                                                    \
    exit(-1);
int my_nondet;
int __attribute__((noinline)) my_unknown() { return my_nondet; }
void __attribute__((noinline)) my_assert(int x) {}
unsigned int s;
extern unsigned int unknown_uint(void);
int main() {
  s = 0;
  while (my_unknown()) {
    if (s != 0) {
      ++s;
    }
    if (my_unknown()) {
      {
        ;
        my_assert((s == 0));
      }
    }
  }
  return 0;
  ;
}
