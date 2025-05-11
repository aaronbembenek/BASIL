// Source:
// data/benchmarks/LinearArbitrary-SeaHorn/loops/loop-invgen/MADWiFi-encode_ie_ok_true-unreach-call_true-termination.c
#include <stdlib.h>
#define assume(e)                                                              \
  if (!(e))                                                                    \
    exit(-1);
int __attribute__((noinline)) my_unknown() { return rand(); }
void __attribute__((noinline)) my_assert(int x) {
  while (!x)
    ;
}
#define LARGE_INT 1000000
extern int unknown_int(void);
int main() {
  int p = (int)my_unknown();
  int i = (int)my_unknown();
  int leader_len = (int)my_unknown();
  int bufsize = (int)my_unknown();
  int bufsize_0 = (int)my_unknown();
  int ielen = (int)my_unknown();
  leader_len = my_unknown();
  bufsize = my_unknown();
  ielen = my_unknown();
  if (!(leader_len < LARGE_INT))
    return 0;
  ;
  if (!(bufsize < LARGE_INT))
    return 0;
  ;
  if (!(ielen < LARGE_INT))
    return 0;
  ;
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
