// Created by YJS
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "regression.h"



Matrix create_matrix(int rows, int cols) {
    Matrix mat;
    mat.rows = rows;
    mat.cols = cols;
    mat.data = (float**)malloc(rows * sizeof(float*));
    for (int i = 0; i < rows; i++) {
        mat.data[i] = (float*)malloc(cols * sizeof(float));
    }
    return mat;
}

Vector create_vector(int len) {
    Vector vec;
    vec.len = len;
    vec.data = (float*)malloc(len * sizeof(float));
    return vec;
}

void free_matrix(Matrix mat) {
    for (int i = 0; i < mat.rows; i++) {
        free(mat.data[i]);
    }
    free(mat.data);
}

void free_vector(Vector vec) {
    free(vec.data);
}

Matrix transpose_matrix(Matrix mat) {
    Matrix transposed = create_matrix(mat.cols, mat.rows);
    for (int i = 0; i < mat.rows; i++) {
        for (int j = 0; j < mat.cols; j++) {
            transposed.data[j][i] = mat.data[i][j];
        }
    }
    return transposed;
}

Matrix multiply_matrices(Matrix mat1, Matrix mat2) {
    if (mat1.cols != mat2.rows) {
        printf("Matrix dimensions do not match for multiplication.\n");
        exit(1);
    }
    Matrix result = create_matrix(mat1.rows, mat2.cols);
    for (int i = 0; i < mat1.rows; i++) {
        for (int j = 0; j < mat2.cols; j++) {
            result.data[i][j] = 0;
            for (int k = 0; k < mat1.cols; k++) {
                result.data[i][j] += mat1.data[i][k] * mat2.data[k][j];
            }
        }
    }
    return result;
}

Matrix invert_matrix(Matrix mat) {
    int n = mat.rows;
    Matrix inverse = create_matrix(n, n);
    Matrix augmented = create_matrix(n, 2*n);

    // 创建增广矩阵 [A | I]
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            augmented.data[i][j] = mat.data[i][j];
            augmented.data[i][j+n] = (i == j) ? 1 : 0;
        }
    }

    // 高斯消元法
    for (int i = 0; i < n; i++) {
        // 找到主元素
        float maxElem = fabs(augmented.data[i][i]);
        int maxRow = i;
        for (int k = i + 1; k < n; k++) {
            if (fabs(augmented.data[k][i]) > maxElem) {
                maxElem = fabs(augmented.data[k][i]);
                maxRow = k;
            }
        }

        // 交换行
        for (int k = 0; k < 2*n; k++) {
            float tmp = augmented.data[maxRow][k];
            augmented.data[maxRow][k] = augmented.data[i][k];
            augmented.data[i][k] = tmp;
        }

        // 归一化主元素所在行
        for (int k = i + 1; k < 2*n; k++) {
            augmented.data[i][k] /= augmented.data[i][i];
        }
        augmented.data[i][i] = 1;

        // 消去主元素列的其他元素
        for (int k = 0; k < n; k++) {
            if (k != i) {
                float coeff = augmented.data[k][i];
                for (int j = i; j < 2*n; j++) {
                    augmented.data[k][j] -= coeff * augmented.data[i][j];
                }
            }
        }
    }

    // 提取逆矩阵
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            inverse.data[i][j] = augmented.data[i][j+n];
        }
    }

    // 释放增广矩阵内存
    free_matrix(augmented);

    return inverse;
}

Matrix create_matrix_from_vector(Vector vec) {
    Matrix mat = create_matrix(vec.len, 1);
    for (int i = 0; i < vec.len; i++) {
        mat.data[i][0] = vec.data[i];
    }
    return mat;
}

Vector create_vector_from_matrix(Matrix mat) {
    if (mat.cols != 1) {
        printf("Matrix is not a column vector.\n");
        exit(1);
    }
    Vector vec = create_vector(mat.rows);
    for (int i = 0; i < mat.rows; i++) {
        vec.data[i] = mat.data[i][0];
    }
    return vec;
}

Vector calculate_regression_coefficients(Matrix X, Vector y) {
    Matrix X_T = transpose_matrix(X);
    Matrix X_T_X = multiply_matrices(X_T, X);
    Matrix X_T_X_inv = invert_matrix(X_T_X);
    Matrix temp1 = create_matrix_from_vector(y);
    Matrix X_T_y = multiply_matrices(X_T, temp1);
    Matrix temp2 = multiply_matrices(X_T_X_inv, X_T_y);
    Vector beta = create_vector_from_matrix(temp2);
    free_matrix(X_T);
    free_matrix(X_T_X);
    free_matrix(X_T_X_inv);
    free_matrix(X_T_y);
    free_matrix(temp1);
    free_matrix(temp2);
    return beta;
}

Vector calculate_multiple_regression_coefficients(float* x, float* y, int num_data_points, int degree) {
    // 创建设计矩阵 X
    Matrix X = create_matrix(num_data_points, degree + 1);
    for (int i = 0; i < num_data_points; i++) {
        X.data[i][0] = 1.0; // 常数项
        for (int j = 1; j <= degree; j++) {
            X.data[i][j] = pow(x[i], j); // x 的不同次幂
        }
    }

    // 创建目标向量 y_vector
    Vector y_vector = create_vector(num_data_points);
    for (int i = 0; i < num_data_points; i++) {
        y_vector.data[i] = y[i];
    }

    // 计算回归系数
    Vector coefficients = calculate_regression_coefficients(X, y_vector);

    // 释放内存
    free_matrix(X);
    free_vector(y_vector);

    return coefficients;
}

float* multiple_regression_prediction(float* x, int num_data_points, Vector coefficients) {
    float* y_pred = (float*)malloc(num_data_points * sizeof(float));
    int degree = coefficients.len - 1;
    if (y_pred == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    for (int i = 0; i < num_data_points; i++) {
        y_pred[i] = 0.0;
        for (int j = 0; j <= degree; j++) {
            y_pred[i] += coefficients.data[j] * pow(x[i], j);
        }
    }

    return y_pred;
}