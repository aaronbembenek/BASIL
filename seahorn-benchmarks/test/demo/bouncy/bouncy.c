#include "seahorn/seahorn.h"

int main() {
  int x = 0;
  int y = 0;
  int z = 0;

  while (unknown()) {
    x++;
    z++;
  }
  while (unknown()) {
    y++;
    z--;
  }

  if (x == y) {
    sassert(z == 0);
  }
}
