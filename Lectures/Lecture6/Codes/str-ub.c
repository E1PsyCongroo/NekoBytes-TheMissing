#include <stdio.h>

int main(void) {
  char a[] = "world\n";
  char b[5] = "hello";
  printf("&a = %p, &b = %p\n", a, b);
  printf("%s", b);
  return 0;
}
