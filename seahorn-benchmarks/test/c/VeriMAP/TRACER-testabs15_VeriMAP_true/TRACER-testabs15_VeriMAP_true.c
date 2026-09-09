extern void __VERIFIER_error() __attribute__((noreturn));
void __VERIFIER_assert1(int cond) {
  if (!cond)
    __VERIFIER_error();
}
unsigned int __VERIFIER_nondet_uint();
void errorFn() {
ERROR:
  goto ERROR;
}
# 1 "MAP/SAFE-exbench/TRACER-testabs15.tmp.c"
# 1 "<command-line>"
# 1 "MAP/SAFE-exbench/TRACER-testabs15.tmp.c"
# 28 "MAP/SAFE-exbench/TRACER-testabs15.tmp.c"
int main() {
  int i, a, b;
  int n = unknown();
  int TRACER_NONDET = unknown();

  if (n >= 0) {

    i = 0;
    a = 0;
    b = 0;

    while (i < n) {
      if (TRACER_NONDET) {
        a = a + 1;
        b = b + 2;
      } else {
        a = a + 2;
        b = b + 1;
      }
      i++;
    }
    __VERIFIER_assert(!(a + b != 3 * n));
  }
}
