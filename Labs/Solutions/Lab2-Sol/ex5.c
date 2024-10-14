#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void add_one(int input) { input += 1; }

void add_one_pointer(int *input) { *input += 1; }

int main(void) {
  int x = 5;

  add_one(x);

  printf("add_one: %d\n", x);

  add_one_pointer(&x);

  assert(x == 6);
  printf("add_one_pointer: %d\n", x);

  return EXIT_SUCCESS;
}
