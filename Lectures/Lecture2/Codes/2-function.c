#include <stdio.h>
#include <stdlib.h>

//  函数声明
int fact(int);

int main(void) {
  printf("%d", fact(5));
  return EXIT_SUCCESS;
}

//  函数定义
int fact(int n) {
  if (n <= 1) {
    return 1;
  }
  int sum = 1, i;
  for (i = 1; i <= n; i++) {
    sum *= i;
  }
  return sum;
}
