#include <stdio.h>
#include <stdlib.h>

int *int_on_stack() {
  int x = 12;
  return &x;
}

int *int_on_heap() {
  int *ptr_to_12 = malloc(sizeof(int));
  *ptr_to_12 = 12;
  return ptr_to_12;
}

int main() {
  int *ptr_to_stack = int_on_stack();
  int *ptr_to_heap = int_on_heap();

  printf("ptr_to_stack is the address %p\n", ptr_to_stack);
  printf("ptr_to_heap is the address %p\n", ptr_to_heap);

  free(ptr_to_heap);
  return EXIT_SUCCESS;
}
