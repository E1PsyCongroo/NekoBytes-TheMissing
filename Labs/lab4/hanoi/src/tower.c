#include "tower.h"
int tower[3][20] = {};
int top[3] = {};
int tower_size = 0, move_cnt = 0;
void tower_init(int siz) {
  memset(tower, 0, sizeof(tower));
  memset(top, 0, sizeof(top));
  tower_size = siz;
  move_cnt = 0;
  int i;
  for (i = 0; i < tower_size; i++) {
    tower[0][top[0]++] = tower_size - i;
  }
  return;
}
void move(int plate, char from, char to) {
  int id_from = from - 'A', id_to = to - 'A';
  if (top[id_from] == 0) {
    printf("ERROE: No plate exist in %c tower\n", from);
    exit(0);
  }
  if (tower[id_from][top[id_from] - 1] != plate) {
    printf("ERROR: The top of %c tower is not plate %d\n", from, plate);
    exit(0);
  }
  move_cnt++;
  tower[id_from][--top[id_from]] = 0;
  tower[id_to][top[id_to]++] = plate;
  return;
}
void tower_print_all() {
  int i, T;
  for (T = 0; T < 3; T++) {
    printf("Tower %c:", (char)('A' + T));
    for (i = 0; i < top[T]; i++) {
      printf("%d ", tower[T][i]);
    }
    printf("\n");
  }
  return;
}
void tower_check() {
  int i;
  for (i = 0; i < tower_size; i++) {
    if (tower[2][i] != tower_size - i) {
      printf("ERROR: You failed on solving this tower.\nThe situation is as "
             "below\n");
      tower_print_all();
      exit(0);
    }
  }
}