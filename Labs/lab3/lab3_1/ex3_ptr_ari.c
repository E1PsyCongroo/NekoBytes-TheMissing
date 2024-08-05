#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  // Creates an integer with value 5
  // Note: int16_t is a numerical datatype that takes up 2 bytes of memory
  int16_t x = 5;

  // TODO: allocate an int16_t array of size 4
  // Hint: C represents arrays as a pointer to the first element
  ______ some_array[______];
  printf("address of the start of the array: %p\n", some_array);

  // TODO: compute the address of the element at index 2 (0-indexed)
  ______ ptr_to_idx_2 = ____________;
  printf("address of index 2: %p\n", ptr_to_idx_2);

  // TODO: store the value 10 at index 2, using ptr_to_idx_2
  __________ = 10;

  // TODO: print the value at index 2
  // Hint: this blank should be the same as the previous blank
  //       please don't hard code 10
  printf("value at index 2: %d\n", __________);

  return 0;
}