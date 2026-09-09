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
# 1 "MAP/UNSAFE-exbench/TRACER-testfunc12-unsafe.tmp.c"
# 1 "<command-line>"
# 1 "MAP/UNSAFE-exbench/TRACER-testfunc12-unsafe.tmp.c"
# 20 "MAP/UNSAFE-exbench/TRACER-testfunc12-unsafe.tmp.c"
int foo() {
  int tmp = 1;
  return tmp;
}

int main() {
  int x, y, p, q;
  p = unknown();
  q = unknown();

  if (q > 0)
    y = 2;
  else
    y = 3;

  if (p > 0)
    x = 1;
  else
    x = 2;

  foo();

  __VERIFIER_assert(!(x == 2));
}
