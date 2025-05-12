// Source: data/benchmarks/accelerating_invariant_generation/dagger/lifnat.c
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
int nondet_int();
int main() {
  int I = (int)my_unknown();
  int Sa = (int)my_unknown();
  int Ea = (int)my_unknown();
  int Ma = (int)my_unknown();
  int Sb = (int)my_unknown();
  int Eb = (int)my_unknown();
  int Mb = (int)my_unknown();
  if (!(I >= 1))
    return 0;
  ;
  Sa = 0;
  Ea = 0;
  Ma = 0;
  Sb = 0;
  Eb = 0;
  Mb = 0;
  while (my_unknown()) {
    if (my_unknown()) {
      if (!(Eb >= 1))
        return 0;
      ;
      Eb = Eb - 1;
      Mb = Mb + 1;
    } else {
      if (my_unknown()) {
        if (!(Ea >= 1))
          return 0;
        ;
        Ea = Ea - 1;
        Ma = Ma + 1;
      } else {
        if (my_unknown()) {
          if (!(Sa >= 1))
            return 0;
          ;
          Sa = Sa - 1;
          I = I + Sb + Eb + Mb;
          Sb = 0;
          Eb = 1;
          Mb = 0;
        } else {
          if (my_unknown()) {
            if (!(Sb >= 1))
              return 0;
            ;
            I = I + Sb + Eb + Mb;
            Sb = 0;
            Eb = 1;
            Mb = 0;
          } else {
            if (my_unknown()) {
              if (!(Sb >= 1))
                return 0;
              ;
              Sb = Sb - 1;
              I = I + Sa + Ea + Ma;
              Sa = 0;
              Ea = 1;
              Ma = 0;
            } else {
              if (my_unknown()) {
                if (!(Sa >= 1))
                  return 0;
                ;
                I = I + Sa + Ea + Ma;
                Sa = 0;
                Ea = 1;
                Ma = 0;
              } else {
                if (my_unknown()) {
                  if (!(Sa >= 1))
                    return 0;
                  ;
                  Sa = Sa - 1;
                  Sb = Sb + Eb + Mb + 1;
                  Eb = 0;
                  Mb = 0;
                } else {
                  if (my_unknown()) {
                    if (!(I >= 1))
                      return 0;
                    ;
                    I = I - 1;
                    Sb = Sb + Eb + Mb + 1;
                    Eb = 0;
                    Mb = 0;
                  } else {
                    if (my_unknown()) {
                      if (!(I >= 1))
                        return 0;
                      ;
                      I = I - 1;
                      Sa = Sa + Ea + Ma + 1;
                      Ea = 0;
                      Ma = 0;
                    } else {
                      if (!(Sb >= 1))
                        return 0;
                      ;
                      Sb = Sb - 1;
                      Sa = Ea + Ma + 1;
                      Ea = 0;
                      Ma = 0;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  {
    ;
    my_assert((Ea + Ma <= 1));
  }
  {
    ;
    my_assert((Eb + Mb <= 1));
  }
  {
    ;
    my_assert((I >= 0));
  }
  {
    ;
    my_assert((Sa >= 0));
  }
  {
    ;
    my_assert((Ma >= 0));
  }
  {
    ;
    my_assert((Ea >= 0));
  }
  {
    ;
    my_assert((Sb >= 0));
  }
  {
    ;
    my_assert((Mb >= 0));
  }
  {
    ;
    my_assert((Eb >= 0));
  }
  {
    ;
    my_assert((I + Sa + Ea + Ma + Sb + Eb + Mb >= 1));
  }
}
