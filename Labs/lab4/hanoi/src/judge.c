#include "judge.h"
int main() {
  int T;
  for (T = 3; T <= 20; T++) {
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