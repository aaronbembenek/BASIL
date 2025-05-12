// Source:
// data/benchmarks/LinearArbitrary-SeaHorn/loops/loop-invgen/sendmail-close-angle_true-unreach-call_true-termination.c
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
extern int unknown_int(void);
int main() {
  int in = (int)my_unknown();
  int inlen = my_unknown();
  int bufferlen = my_unknown();
  int buf = (int)my_unknown();
  int buflim = (int)my_unknown();
  if (bufferlen > 1)
    ;
  else
    goto END;
  if (inlen > 0)
    ;
  else
    goto END;
  if (bufferlen < inlen)
    ;
  else
    goto END;
  buf = 0;
  in = 0;
  buflim = bufferlen - 2;
  while (my_unknown()) {
    if (buf == buflim)
      break;
    {
      ;
      my_assert((0 <= buf));
    }
    {
      ;
      my_assert((buf < bufferlen));
    }
    buf++;
  out:
    in++;
    {
      ;
      my_assert((0 <= in));
    }
    {
      ;
      my_assert((in < inlen));
    }
  }
  {
    ;
    my_assert((0 <= buf));
  }
  {
    ;
    my_assert((buf < bufferlen));
  }
  buf++;
  {
    ;
    my_assert((0 <= buf));
  }
  {
    ;
    my_assert((buf < bufferlen));
  }
  buf++;
END:
  return 0;
  ;
}
