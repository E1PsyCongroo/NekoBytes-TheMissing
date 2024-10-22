#include "hanoi.h"
void hanoi(int n, char from, char to, char spare) {
  if (n == 1) {
    move(1, from, to);
  } else {
    hanoi(n - 1, from, spare, to);
    move(n, from, to);
    hanoi(n - 1, spare, to, from);
  }
  return;
}