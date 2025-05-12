// Source: data/benchmarks/sv-benchmarks/loop-invgen/NetBSD_loop.c
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
