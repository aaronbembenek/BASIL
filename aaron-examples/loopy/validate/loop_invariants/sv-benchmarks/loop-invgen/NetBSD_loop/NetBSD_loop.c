// Source: data/benchmarks/sv-benchmarks/loop-invgen/NetBSD_loop.c
#include <stdlib.h>
#define assume(e)                                                              \
  if (!(e))                                                                    \
    exit(-1);
int my_nondet;
int __attribute__((noinline)) my_unknown() { return my_nondet; }
void __attribute__((noinline)) my_assert(int x) {}
int MAXPATHLEN;
int pathbuf_off;
int bound_off;
int glob2_p_off;
int glob2_pathbuf_off;
int glob2_pathlim_off;
extern int unknown_int(void);
int main() {
  ;
  ;
  ;
  ;
  ;
  ;
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
