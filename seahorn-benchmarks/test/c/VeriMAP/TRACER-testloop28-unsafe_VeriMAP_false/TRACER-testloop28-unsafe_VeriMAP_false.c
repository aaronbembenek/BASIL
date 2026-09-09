void assert(int cond) {
  if (!cond)
    __VERIFIER_error();
}
int unknown_XXX() {
  int x = unknown();
  return x;
}

int main() {
  int i, n, x, NONDET;
  n = unknown();

  x = 0;
  i = 0;
  while (i < n) {
    if (unknown() > 0) {
      assert(!(x > 0));
    } else {
      x = 1;
    }
    i++;
  }
}
