#include "zuma.h"

extern int K;

int main() {
  init();
  while (1) {
    K = 0;
    solve();
  }
  return 0;
}