// Created by YJS

#ifndef LINEAR_REGRESSION_H
#define LINEAR_REGRESSION_H

#define bool int
#define true 1
#define false 0

typedef struct {
 int rows;
 int cols;
 float** data;
} Matrix;

typedef struct {
 int len;
 float* data;
} Vector;

typedef struct {
 int rows;
 int cols;
 float** data;
} Data;

/**
 * 创建一个数据。
 * @param rows  数据的行数。
 * @param cols  数据的列数。
 * @return      创建的数据结构。
 */
Data create_Data(int rows, int cols);

/**
 * 删除数据。
 * @param data  指向要删除的数据结构的指针。
 */
void free_Data(Data data);

/**
 * 读取 CSV 文件的指定列数据。
 *
 * @param start_row     要读取的起始行，从 0 开始。
 * @param num_rows      要读取的行数。
 * @param start_col     要读取的列索引，从 0 开始。
 * @param num_cols      读取的列数。
 * @param file_path     CSV 文件的路径。
 * @return              读取的数据结构。
 */
Data read_csv(int start_row, int num_rows, int start_col, int num_cols, char* file_path);

/**
 * 获取文件中的行数。
 *
 * @param file_path     文件路径。
 * @return              文件的行数。
 */
int get_file_len(char* file_path);

/**
 * 计算数据集的平均值。
 *
 * @param data  包含数据的结构体。
 * @return      数据的平均值。
 */
float average(Data data);

/**
 * 计算线性回归的回归系数（斜率）。
 *
 * @param x_data  自变量数据的结构体。
 * @param y_data  因变量数据的结构体。
 * @return        回归系数（斜率）。
 */
float calculate_slope(Data x_data, Data y_data);

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
 * @param actual    实际值数据结构。
 * @param predicted 预测值数组。
 * @return          残差方差。
 */
float calculate_residual_variance(Data actual, float* predicted);

/**
 * 根据给定的斜率和截距计算预测值。
 *
 * @param slope      回归系数（斜率）。
 * @param intercept  截距。
 * @param x_data     自变量数据的结构体。
 * @return           预测值数组。
 */
float* prediction(float slope, float intercept, Data x_data);

/**
 * 创建一个矩阵。
 *
 * @param rows  矩阵的行数。
 * @param cols  矩阵的列数。
 * @return      创建的矩阵结构。
 */
Matrix create_matrix(int rows, int cols);

/**
 * 创建一个向量。
 *
 * @param len   向量的长度。
 * @return      创建的向量结构。
 */
Vector create_vector(int len);

/**
 * 释放由矩阵分配的内存。
 *
 * @param mat   矩阵结构。
 */
void free_matrix(Matrix mat);

/**
 * 释放由向量分配的内存。
 *
 * @param vec   向量结构。
 */
void free_vector(Vector vec);

/**
 * 转置矩阵。
 *
 * @param mat   要转置的矩阵结构。
 * @return      转置后的矩阵结构。
 */
Matrix transpose_matrix(Matrix mat);

/**
 * 矩阵相乘。
 *
 * @param mat1  第一个矩阵。
 * @param mat2  第二个矩阵。
 * @return      乘积矩阵结构。
 */
Matrix multiply_matrices(Matrix mat1, Matrix mat2);

/**
 * 计算线性回归系数。
 *
 * @param X  自变量矩阵。
 * @param y  因变量向量。
 * @return   包含回归系数的向量。
 */
Vector calculate_regression_coefficients(Matrix X, Vector y);

/**
 * 计算矩阵的逆。
 *
 * @param mat   要逆的矩阵。
 * @return      逆矩阵结构。
 */
Matrix invert_matrix(Matrix mat);

/**
 * 从向量创建矩阵。
 *
 * @param vec   要转换的向量。
 * @return      创建的矩阵结构。
 */
Matrix create_matrix_from_vector(Vector vec);

/**
 * 从矩阵创建向量。
 *
 * @param mat   要转换的矩阵。
 * @return      创建的向量结构。
 */
Vector create_vector_from_matrix(Matrix mat);

/**
 * 计算多元线性回归系数。
 *
 * @param x_data          自变量数据的结构体。
 * @param y_data          因变量数据的结构体。
 * @param degree          回归的阶数。
 * @return                包含回归系数的向量。
 */
Vector calculate_multiple_regression_coefficients(Data x_data, Data y_data, int degree);

/**
 * 根据自变量计算多元线性回归的预测值。
 *
 * @param x_data      自变量数据的结构体。
 * @param degree      回归的阶数。
 * @param coefficients    包含回归系数的向量。
 * @return            预测值数组。
 */
float* multiple_regression_prediction(Data x_data, int degree, Vector coefficients);

/**
 * 生成给定数据的组合。
 
 * @param data   要生成组合的向量。
 * @param degree 组合的阶数。
 * @return      包含组合的向量。
 */
Vector generate_combinations(Vector data, int degree);

/**
 * 如果需要调试，可以调用他打印矩阵
 */
void print_Matrix(Matrix mat);
#endif //LINEAR_REGRESSION_H
