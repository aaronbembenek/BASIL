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
# 1 "MAP/SAFE-exbench/TRACER-testloop27.tmp.c"
# 1 "<command-line>"
# 1 "MAP/SAFE-exbench/TRACER-testloop27.tmp.c"
# 22 "MAP/SAFE-exbench/TRACER-testloop27.tmp.c"
int main() {
  int i, n, x, NONDET;
  NONDET = unknown();

  i = 0;
  x = 0;
  while (i < 1) {
    x++;
    if (NONDET > 0) {
      x--;
    }
    i++;
  }

  __VERIFIER_assert(!(x != 0));
}
