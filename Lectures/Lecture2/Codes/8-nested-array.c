#include <stdio.h>

int main(void) {
  int matrix[2][2] = {{1, 2}, {3, 4}};
  printf("%p %p %p %p\n", &matrix[0][0], &matrix[0][1], &matrix[1][0],
         &matrix[1][1]);
  printf("sizeof matrix: %zu\n", sizeof matrix);
  printf("sizeof matrix[0]: %zu\n", sizeof matrix[0]);
  printf("sizeof matrix[1]: %zu\n", sizeof matrix[1]);
  return 0;
}
