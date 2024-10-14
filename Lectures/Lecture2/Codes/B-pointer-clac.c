#include <stdio.h>

int main(void) {
  int array[10] = {0};
  printf("array = %p\n", array);
  int *p1 = array, *p2 = array;
  printf("p1 = %p, p2 = %p\n", p1, p2);
  p1 = p1 + 1;
  printf("p1 = %p, p2 = %p\n", p1, p2);
  p2 = p2 + 9;
  printf("p1 = %p, p2 = %p\n", p1, p2);
  printf("p2 - p1 = %u\n", (unsigned int)(p2 - p1));
  return 0;
}
