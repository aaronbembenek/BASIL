#include "seahorn/seahorn.h"

int main() {
  int x = 0;
  int y = 0;
  int z = 0;

  while (unknown()) {
    if (unknown()) {
      x++;
      z++;
    } else {
      y++;
      z--;
    }
  }

  if (x == y) {
    sassert(z == 0);
  }
}
