// Source:
// data/benchmarks/LinearArbitrary-SeaHorn/loops/loop-invgen/sendmail-close-angle_true-unreach-call_true-termination.c
#include <stdlib.h>
#define assume(e)                                                              \
  if (!(e))                                                                    \
    exit(-1);
int my_nondet;
int __attribute__((noinline)) my_unknown() { return my_nondet; }
void __attribute__((noinline)) my_assert(int x) {}
int in;
int inlen;
int bufferlen;
int buf;
int buflim;
extern int unknown_int(void);
int main() {
  ;
  inlen = my_unknown();
  bufferlen = my_unknown();
  ;
  ;
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
