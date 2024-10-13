#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int i = 0;

  // let's make our own array of strings
  const char *states[] = {"California", "Oregon", "Washington", "Texas"};

  // go through each string in argv
  // why am I skipping argv[0]?
  printf("for:\n");
  for (i = 1; i < argc; i++) {
    printf("arg %d: %s\n", i, argv[i]);
  }
  printf("\n");

  /* num_states 获取 states 的数组个数
   * STFM: sizeof
   */
  int num_states = sizeof(states) / sizeof(states[0]);

  for (i = 0; i < num_states; i++) {
    printf("state %d: %s\n", i, states[i]);
  }
  printf("\n");

  printf("while:\n");
  i = 0;
  while (i < argc) {
    printf("arg %d: %s\n", i, argv[i]);
    i++;
  }
  printf("\n");

  num_states = 4;
  i = 0; // watch for this
  while (i < num_states) {
    printf("state %d: %s\n", i, states[i]);
    i++;
  }

  return EXIT_SUCCESS;
}
