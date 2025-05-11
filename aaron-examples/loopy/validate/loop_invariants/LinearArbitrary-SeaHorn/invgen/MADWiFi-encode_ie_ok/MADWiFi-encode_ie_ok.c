// Source: data/benchmarks/LinearArbitrary-SeaHorn/invgen/MADWiFi-encode_ie_ok.c
#include <stdlib.h>
#define assume(e)                                                              \
  if (!(e))                                                                    \
    exit(-1);
int __attribute__((noinline)) my_unknown() { return rand(); }
void __attribute__((noinline)) my_assert(int x) {
  while (!x)
    ;
}
extern int unknown(void);
extern int unknown();
int main() {
  int p = (int)my_unknown();
  int i = (int)my_unknown();
  int leader_len = my_unknown();
  int bufsize = my_unknown();
  int bufsize_0 = my_unknown();
  int ielen = my_unknown();
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
