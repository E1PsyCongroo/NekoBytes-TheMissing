// Created by YJS

#ifndef LINEAR_REGRESSION_H
#define LINEAR_REGRESSION_H

/**
 * 读取 CSV 文件的指定列数据。
 *
 * @param start_row  要读取的起始行，从 0 开始。
 * @param num_rows   要读取的行数。
 * @param col        要读取的列索引，从 0 开始。
 * @param file_path  CSV 文件的路径。
 * @return           指向读取到的数据数组的指针。
 */
float* read_csv(int start_row, int num_rows, int col, char* file_path);

/**
 * 释放由 read_csv 分配的内存。
 *
 * @param data  指向数据数组的指针。
 * @param len   数据数组的长度。
 */
void delete_csv_data(float** data, int len);

/**
 * 获取文件中的行数。
 *
 * @param file_path  文件路径。
 * @return           文件的行数。
 */
int get_file_len(char* file_path);

/**
 * 计算数组的平均值。
 *
 * @param v    指向数据数组的指针。
 * @param len  数据数组的长度。
 * @return     数组的平均值。
 */
float average(float* v, int len);

/**
 * 计算线性回归的回归系数（斜率）。
 *
 * @param x            指向自变量数据数组的指针。
 * @param y            指向因变量数据数组的指针。
 * @param n            数据点的数量。
 * @param x_average    自变量的平均值。
 * @param y_average    因变量的平均值。
 * @return             回归系数（斜率）。
 */
float calculate_slope(float* x, float* y, int n, float x_average, float y_average);

/**
 * 计算线性回归的截距。
 *
 * @param slope        回归系数（斜率）。
 * @param x_average    自变量的平均值。
 * @param y_average    因变量的平均值。
 * @return             截距。
 */
float calculate_intercept(float slope, float x_average, float y_average);

/**
 * 计算预测值和实际值之间的残差方差。
 *
 * @param actual       实际值数据数组。
 * @param predicted    预测值数据数组。
 * @param n            数据点的数量。
 * @return             残差方差。
 */
float calculate_residual_variance(float* actual, float* predicted, int n);

/**
 * 根据给定的斜率和截距计算预测值。
 *
 * @param slope      回归系数（斜率）。
 * @param intercept  截距。
 * @param x          自变量数据数组。
 * @param len        数据点的数量。
 * @return           预测值数据数组。
 */
float* prediction(float slope, float intercept, float* x, int len);


/**
 *下面函数的定义属于实现多次回归，你无需实现他们
 */

typedef struct {
 int rows;
 int cols;
 float** data;
} Matrix;

typedef struct {
 int len;
 float* data;
} Vector;

Matrix create_matrix(int rows, int cols);
Vector create_vector(int len);
void free_matrix(Matrix mat);
void free_vector(Vector vec);
Matrix transpose_matrix(Matrix mat);
Matrix multiply_matrices(Matrix mat1, Matrix mat2);
Vector calculate_regression_coefficients(Matrix X, Vector y);


Matrix invert_matrix(Matrix mat);
Matrix create_matrix_from_vector(Vector vec);
Vector create_vector_from_matrix(Matrix mat);
Vector calculate_multiple_regression_coefficients(float* x, float* y, int num_data_points, int degree);
float* multiple_regression_prediction(float* x, int num_data_points, Vector coefficients);

#endif //LINEAR_REGRESSION_H
