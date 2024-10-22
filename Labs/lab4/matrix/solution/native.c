#include <stdio.h>
#include <string.h>
struct Matrix {
  int r, c;
  int mart[1024][1024];
};
typedef struct Matrix matrix;

matrix A, B;

void init() {
  scanf("%d %d", &A.r, &A.c);
  int i, j;
  for (i = 0; i < A.r; i++) {
    for (j = 0; j < A.c; j++) {
      scanf("%d", &A.mart[i][j]);
    }
  }
  scanf("%d %d", &B.r, &B.c);
  for (i = 0; i < B.r; i++) {
    for (j = 0; j < B.c; j++) {
      scanf("%d", &B.mart[i][j]);
    }
  }
}

matrix mart_mutiply_native(matrix A, matrix B) {
  matrix C;
  C.r = A.r;
  C.c = B.c;
  memset(C.mart, 0, sizeof(C.mart));
  int i, j, k;
  for (i = 0; i < A.r; i++) {
    for (j = 0; j < B.c; j++) {
      for (k = 0; k < A.c; k++) {
        C.mart[i][j] += A.mart[i][k] * B.mart[k][j];
      }
    }
  }
  return C;
}

void mart_output(matrix A) {
  int i, j;
  for (i = 0; i < A.r; i++) {
    for (j = 0; j < A.c; j++) {
      printf("%d ", A.mart[i][j]);
    }
    printf("\n");
  }
  return;
}

int main() {
  freopen("native.out", "w", stdout);
  init();
  mart_output(mart_mutiply_native(A, B));
  return 0;
}
/*

*/