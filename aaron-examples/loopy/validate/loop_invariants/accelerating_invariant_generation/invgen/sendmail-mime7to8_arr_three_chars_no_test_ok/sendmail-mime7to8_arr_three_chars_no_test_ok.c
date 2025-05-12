// Source:
// data/benchmarks/accelerating_invariant_generation/invgen/sendmail-mime7to8_arr_three_chars_no_test_ok.c
#include <stdlib.h>
#define assume(e)                                                              \
  if (!(e))                                                                    \
    exit(-1);
#ifdef __BASIL__
int __attribute__((noinline)) my_unknown() { return rand(); }
void __attribute__((noinline)) my_assert(int x) {
  while (!x)
    ;
}
#else
extern void __assert_fail(const char *, const char *, unsigned int,
                          const char *) __attribute__((__nothrow__, __leaf__))
__attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "benchmark", 3, "reach_error"); }

extern int __VERIFIER_nondet_int();
void __VERIFIER_assert(int cond) {
  if (!(cond))
  ERROR: {
    reach_error();
    abort();
  }
    return;
}

#define my_unknown() __VERIFIER_non_det_int()
#define my_assert(x) __VERIFIER_assert(x)
#endif
int main() {
  int __BLAST_NONDET = (int)my_unknown();
  int fbuflen = (int)my_unknown();
  int fb = (int)my_unknown();
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
