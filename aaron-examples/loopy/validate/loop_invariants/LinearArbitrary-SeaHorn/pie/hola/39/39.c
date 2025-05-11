// Source: data/benchmarks/LinearArbitrary-SeaHorn/pie/hola/39.c
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
int MAXPATHLEN;
extern int unknown();
int main() {
  MAXPATHLEN = my_unknown();
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
