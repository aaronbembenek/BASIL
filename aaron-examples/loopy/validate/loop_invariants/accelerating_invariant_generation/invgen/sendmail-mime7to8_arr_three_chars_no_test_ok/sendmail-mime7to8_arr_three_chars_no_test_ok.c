// Source:
// data/benchmarks/accelerating_invariant_generation/invgen/sendmail-mime7to8_arr_three_chars_no_test_ok.c
#include <stdlib.h>
#define assume(e)                                                              \
  if (!(e))                                                                    \
    exit(-1);
int my_nondet;
int __attribute__((noinline)) my_unknown() { return my_nondet; }
void __attribute__((noinline)) my_assert(int x) {}
int __BLAST_NONDET;
int fbuflen;
int fb;
int main() {
  ;
  ;
  ;
  if (fbuflen > 0)
    ;
  else
    goto END;
  fb = 0;
  while (my_unknown()) {
    if (my_unknown())
      break;
    if (my_unknown())
      break;
    {
      ;
      my_assert((0 <= fb));
    }
    {
      ;
      my_assert((fb < fbuflen));
    }
    fb++;
    if (fb >= fbuflen - 1)
      fb = 0;
    {
      ;
      my_assert((0 <= fb));
    }
    {
      ;
      my_assert((fb < fbuflen));
    }
    fb++;
    if (fb >= fbuflen - 1)
      fb = 0;
    {
      ;
      my_assert((0 <= fb));
    }
    {
      ;
      my_assert((fb < fbuflen));
    }
    fb++;
    if (fb >= fbuflen - 1)
      fb = 0;
  }
  if (fb > 0) {
    {
      ;
      my_assert((0 <= fb));
    }
    {
      ;
      my_assert((fb < fbuflen));
    }
  }
END:
  return 0;
  ;
}
