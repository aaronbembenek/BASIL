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
# 1 "MAP/SAFE-exbench/TRACER-testwp8.tmp.c"
# 1 "<command-line>"
# 1 "MAP/SAFE-exbench/TRACER-testwp8.tmp.c"
# 20 "MAP/SAFE-exbench/TRACER-testwp8.tmp.c"
int main() {
  int x, y, z;
  int TRACER_NONDET = unknown();
  y = unknown();

  x = 0;

  if (y > 0)
    y = 2;
  else
    y = 5;

  if (TRACER_NONDET > 0)
    x = x + 1;
  else
    x = x + 4;

  __VERIFIER_assert(!(x + y > 50));
}
