// Source: data/benchmarks/LinearArbitrary-SeaHorn/invgen/MADWiFi-encode_ie_ok.c
#include <stdlib.h>
#define assume(e)                                                              \
  if (!(e))                                                                    \
    exit(-1);
int my_nondet;
int __attribute__((noinline)) my_unknown() { return my_nondet; }
void __attribute__((noinline)) my_assert(int x) {}
int p;
int i;
int leader_len;
int bufsize;
int bufsize_0;
int ielen;
extern int unknown(void);
extern int unknown();
int main() {
  ;
  ;
  leader_len = my_unknown();
  bufsize = my_unknown();
  bufsize_0 = my_unknown();
  ielen = my_unknown();
  if (leader_len > 0)
    ;
  else
    goto END;
  if (bufsize > 0)
    ;
  else
    goto END;
  if (ielen > 0)
    ;
  else
    goto END;
  if (bufsize < leader_len)
    goto END;
  p = 0;
  bufsize_0 = bufsize;
  bufsize -= leader_len;
  p += leader_len;
  if (bufsize < 2 * ielen)
    goto END;
  for (i = 0; i < ielen && bufsize > 2; i++) {
    {
      ;
      my_assert((0 <= p));
    }
    {
      ;
      my_assert((p + 1 < bufsize_0));
    }
    p += 2;
  }
END:;
}
