#include "judge.h"
int main(int argc, char *argv[]) {
  int start_T = 3, end_T = 20;
  int T;
  for (T = 1; T < argc; T++) {
    if (strcmp(argv[T], "-d") == 0) {
      tower_set_debug();
    } else if (strcmp(argv[T], "-n") == 0) {
      if (T + 1 >= argc) {
        printf("ERROR: Missing number behind -n\n");
        exit(0);
      }
      int num = atoi(argv[T + 1]);
      if (num < 3 || num > 20) {
        printf("ERROR: Wrong number for -n\n");
        exit(0);
      }
      start_T = end_T = num;
      T++;
    } else {
      printf("ERROR: Wrong command line arguments\n");
      exit(0);
    }
  }
  for (T = start_T; T <= end_T; T++) {
    tower_init(T);
    hanoi(T, 'A', 'C', 'B');
    tower_check();
    printf("Congratulation,tower with size:[%d] Solved.\n", T);
    printf("You solved this tower with %d steps.\n", move_cnt);
    if (move_cnt == (1 << T) - 1) {
      printf("Cool!You solved this problem in least steps.\n");
    } else {
      printf("You can solve this tower in less steps.Try again!\n");
    }
    printf("\n");
  }
  return 0;
}