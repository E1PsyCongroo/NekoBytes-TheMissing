#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int16_t x = 8;
  (void)x; // 将变量转换为void，以避免未使用警告

  int16_t *some_array = malloc(sizeof(int16_t) * 4);
  printf("address of the start of the array: %p\n", some_array);

  int16_t *ptr_to_idx_2 = &some_array[2];
  printf("address of index 2: %p\n", ptr_to_idx_2);

  *ptr_to_idx_2 = 9;

  printf("value at index 2: %d\n", some_array[2]);

  assert(some_array[2] == 9);
  free(some_array);
  return EXIT_SUCCESS;
}
