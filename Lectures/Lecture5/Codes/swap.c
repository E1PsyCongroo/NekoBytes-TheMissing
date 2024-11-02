#include <stdio.h>

void swap(int a, int b) {
  int tmp = a;
  a = b;
  b = tmp;
  return;
}

int main(void) {
  int x = 114, y = 514;
  printf("Before swap: x=%d, y=%d\n", x, y);
  swap(x, y);
  printf("After swap: x=%d, y=%d\n", x, y);
  return 0;
}
