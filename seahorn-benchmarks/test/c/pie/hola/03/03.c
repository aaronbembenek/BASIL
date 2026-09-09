#include "seahorn/seahorn.h"

/*
 * "nested4.c" from InvGen benchmark suite
 */

extern int unknown1();

void main() {
  int i, k, n;

  int l = unknown1();
  n = unknown();
  if (l > 0) {

    for (k = 1; k < n; k++) {
      for (i = l; i < n; i++) {
      }
      for (i = l; i < n; i++) {
        sassert(1 <= i);
      }
    }
  }
}
