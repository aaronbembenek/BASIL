// Source:
// data/benchmarks/accelerating_invariant_generation/invgen/NetBSD_loop_int.c
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
int __BLAST_NONDET;
int MAXPATHLEN;
int main() {
  int buf_off = (int)my_unknown();
  int pattern_off = (int)my_unknown();
  int bound_off = (int)my_unknown();
  int glob3_pathbuf_off = (int)my_unknown();
  int glob3_pathend_off = (int)my_unknown();
  int glob3_pathlim_off = (int)my_unknown();
  int glob3_pattern_off = (int)my_unknown();
  int glob3_dc = (int)my_unknown();
  if (MAXPATHLEN > 0)
    ;
  else
    goto END;
  buf_off = 0;
  pattern_off = 0;
  bound_off = 0 + (MAXPATHLEN + 1) - 1;
  glob3_pathbuf_off = buf_off;
  glob3_pathend_off = buf_off;
  glob3_pathlim_off = bound_off;
  glob3_pattern_off = pattern_off;
  glob3_dc = 0;
  for (;;)
    if (glob3_pathend_off + glob3_dc >= glob3_pathlim_off)
      break;
    else {
      glob3_dc++;
      {
        ;
        my_assert((0 <= glob3_dc));
      }
      {
        ;
        my_assert((glob3_dc < MAXPATHLEN + 1));
      }
      if (my_unknown())
        goto END;
    }
END:
  return 0;
  ;
}
