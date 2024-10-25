#include "matrix_functions.h"

matrix matrix_mutiply_naive(matrix A, matrix B) {
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

unsigned int next_power_of_two(unsigned int n) {
  if (n == 0)
    return 1;
  n--;
  n |= n >> 1;
  n |= n >> 2;
  n |= n >> 4;
  n |= n >> 8;
  n |= n >> 16;
  return n + 1;
}

matrix extend(matrix A, int len) {
  int old_r = A.r, old_c = A.c, i, j;
  A.r = len;
  A.c = len;
  for (i = 0; i < A.r; i++) {
    for (j = old_c + 1; j < A.c; j++) {
      A.mart[i][j] = 0;
    }
  }
  for (i = old_r + 1; i < A.r; i++) {
    for (j = 0; j < A.c; j++) {
      A.mart[i][j] = 0;
    }
  }
  return A;
}

matrix shrink(matrix A, int r, int c) {
  A.r = r;
  A.c = c;
  return A;
}

matrix split(matrix A, int r1, int r2, int c1, int c2) {
  matrix B;
  memset(B.mart, 0, sizeof(B.mart));
  B.r = r2 - r1;
  B.c = c2 - c1;
  for (int i = r1; i < r2; i++) {
    for (int j = c1; j < c2; j++) {
      B.mart[i - r1][j - c1] = A.mart[i][j];
    }
  }
  return B;
}

matrix matrix_add(matrix A, matrix B) {
  int i, j;
  for (i = 0; i < A.c; i++) {
    for (j = 0; j < A.c; j++) {
      A.mart[i][j] += B.mart[i][j];
    }
  }
  return A;
}

matrix matrix_sub(matrix A, matrix B) {
  int i, j;
  for (i = 0; i < A.c; i++) {
    for (j = 0; j < A.c; j++) {
      A.mart[i][j] -= B.mart[i][j];
    }
  }
  return A;
}

matrix merge(matrix C11, matrix C12, matrix C21, matrix C22) {
  int len = C11.r, i, j;
  matrix C;
  C.r = len * 2;
  C.c = len * 2;
  for (i = 0; i < len; i++) {
    for (j = 0; j < len; j++) {
      C.mart[i][j] = C11.mart[i][j];
      C.mart[i][j + len] = C12.mart[i][j];
      C.mart[i + len][j] = C21.mart[i][j];
      C.mart[i + len][j + len] = C22.mart[i][j];
    }
  }
  return C;
}

void matrix_output(matrix A) {
  int i, j;
  for (i = 0; i < A.r; i++) {
    for (j = 0; j < A.c; j++) {
      printf("%d ", A.mart[i][j]);
    }
    printf("\n");
  }
  return;
}
