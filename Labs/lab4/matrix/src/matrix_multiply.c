#include "matrix_functions.h"
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

matrix SMM(matrix A, matrix B) {
  if (A.r == 1) {
    return matrix_mutiply_naive(A, B);
  }
  int mid = A.r / 2;
  matrix A11, A12, A21, A22, B11, B12, B21, B22;
  A11 = split(A, 0, mid, 0, mid);
  A12 = _;
  A21 = _;
  A22 = split(A, mid, A.r, mid, A.c);
  B11 = _;
  B12 = split(B, 0, mid, mid, B.c);
  B21 = split(B, mid, B.r, 0, mid);
  B22 = _;
  matrix M1, M2, M3, M4, M5, M6, M7;
  M1 = SMM(A11, matrix_sub(B12, B22));
  M2 = _;
  M3 = SMM(matrix_add(A21, A22), B11);
  M4 = _;
  M5 = SMM(matrix_add(A11, A22), matrix_add(B11, B22));
  M6 = _;
  M7 = _;
  matrix C11, C12, C21, C22;
  C11 = matrix_add(matrix_sub(matrix_add(M5, M4), M2), M6);
  C12 = matrix_add(M1, M2);
  C21 = _;
  C22 = _;
  matrix C;
  C = _;
  return C;
}

int main() {
  init();
  int len = A.r, fin_r = A.r, fin_c = B.c;
  len = len > A.c ? len : A.c;
  len = len > B.c ? len : B.c;
  len = _;
  A = _;
  B = _;
  matrix_output(_);
  return 0;
}
