#include <stdio.h>
#include <string.h>

#define N 128

struct Matrix {
  int r, c;
  int mart[128][128];
};
typedef struct Matrix matrix;
matrix matrix_mutiply_native(matrix A, matrix B);
unsigned int next_power_of_two(unsigned int n);
matrix extend(matrix A, int len);
matrix shrink(matrix A, int r, int c);
matrix split(matrix A, int r1, int r2, int c1, int c2);
matrix matrix_add(matrix A, matrix B);
matrix matrix_sub(matrix A, matrix B);
void matrix_output(matrix A);
matrix merge(matrix C11, matrix C12, matrix C21, matrix C22);