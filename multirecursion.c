#include <stdio.h>

int multiply(int x, int y) {
  if (y == 0) {
    return 0;
  } else {
    return x + multiply(x, y - 1);
  }
}

int main() {
  int x = 5;
  int y = 3;

  int product = multiply(x, y);

  printf("The product of %d and %d is %d\n", x, y, product);

  return 0;
}

