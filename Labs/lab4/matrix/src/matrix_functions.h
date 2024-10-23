#include <stdio.h>
#include <string.h>

#define N 128

struct Matrix {
  int r, c;
  int mart[128][128];
};
typedef struct Matrix matrix;
/*对矩阵A和矩阵B进行朴素乘法并返回结果矩阵*/
matrix matrix_mutiply_native(matrix A, matrix B);
/*返回大于等于传入数字n的最小的二的幂次*/
unsigned int next_power_of_two(unsigned int n);
/*将矩阵A扩展为len*len，以0填充空位，返回扩展后的矩阵*/
matrix extend(matrix A, int len);
/*裁切矩阵A到r行c列，返回裁切后矩阵*/
matrix shrink(matrix A, int r, int c);
/*获取矩阵A的子矩阵，以(r1,c1)的元素为左上角(r2,c2)的元素为右下角作为新矩阵的边界，返回新矩阵*/
matrix split(matrix A, int r1, int r2, int c1, int c2);
/*返回A+B*/
matrix matrix_add(matrix A, matrix B);
/*返回A-B*/
matrix matrix_sub(matrix A, matrix B);
/*输出矩阵A*/
void matrix_output(matrix A);
/*将四个子矩阵合并，返回合并后的矩阵*/
matrix merge(matrix C11, matrix C12, matrix C21, matrix C22);