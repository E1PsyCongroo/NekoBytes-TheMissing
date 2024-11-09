#include <limits.h>
#include <stdio.h>

int foo(int x) {
  return x + 1 > x; // 真或为有符号溢出导致的 UB
}

int main(void) {
  printf("IMT_MAX + 1 = %d\n", INT_MAX + 1);
  printf("INT_MAX = %d\n", INT_MAX);
  printf("INT_MAX + 1 > INT_MAX = %d\n", INT_MAX + 1 > INT_MAX);
  printf("foo(INT_MAX) = %d\n", foo(INT_MAX));
  return 0;
}
