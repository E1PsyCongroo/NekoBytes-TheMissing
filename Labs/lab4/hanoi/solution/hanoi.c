#include "hanoi.h"
void hanoi(int n, char from, char to, char spare) {
  if (n == 1) {
    tower_move(1, from, to);
  } else {
    hanoi(n - 1, from, spare, to);
    tower_move(n, from, to);
    hanoi(n - 1, spare, to, from);
  }
  return;
}