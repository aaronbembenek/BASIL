// Source: data/benchmarks/sv-benchmarks/loop-invgen/NetBSD_loop.c
#include <stdlib.h>
#define assume(e)                                                              \
  if (!(e))                                                                    \
    exit(-1);
int __attribute__((noinline)) my_unknown() { return rand(); }
void __attribute__((noinline)) my_assert(int x) {
  while (!x)
    ;
}
extern int unknown_int(void);
int main() {
  int MAXPATHLEN = (int)my_unknown();
  int pathbuf_off = (int)my_unknown();
  int bound_off = (int)my_unknown();
  int glob2_p_off = (int)my_unknown();
  int glob2_pathbuf_off = (int)my_unknown();
  int glob2_pathlim_off = (int)my_unknown();
  MAXPATHLEN = my_unknown();
  if (MAXPATHLEN > 0 && MAXPATHLEN < 2147483647)
    ;
  else
    goto END;
  pathbuf_off = 0;
  bound_off = pathbuf_off + (MAXPATHLEN + 1) - 1;
  glob2_pathbuf_off = pathbuf_off;
  glob2_pathlim_off = bound_off;
  for (glob2_p_off = glob2_pathbuf_off; glob2_p_off <= glob2_pathlim_off;
       glob2_p_off++) {
    {
      ;
      my_assert((0 <= glob2_p_off));
    }
    {
      ;
      my_assert((glob2_p_off < MAXPATHLEN + 1));
    }
  }
END:
  return 0;
  ;
}
