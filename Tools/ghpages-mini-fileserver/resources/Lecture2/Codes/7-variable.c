#include <stdio.h>

int main(void) {
  unsigned int a;
  int b;
  float c;
  printf("a,b,c各元素的值\n");
  printf("%u %d %f\n", a, b, c);
  printf("a,b,c各元素的地址\n");
  printf("%p %p %p\n", &a, &b, &c);

  return 0;
}
