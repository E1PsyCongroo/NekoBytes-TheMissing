// Created by YJS
#include <stdio.h>
#include <stdlib.h>
#include "regression.h"

char* file_path = "data.csv";

int main(void) {
    int len = get_file_len(file_path);
    len -= 1; // 去掉标题行
    int train_len = len * 0.8;
    int test_len = len - train_len;

    // 读取数据并拆分为训练和测试数据
    float* train_x = read_csv(1, train_len, 0, file_path);
    float* train_y = read_csv(1, train_len, 1, file_path);
    float* test_x = read_csv(train_len + 1, test_len, 0, file_path);
    float* test_y = read_csv(train_len + 1, test_len, 1, file_path);

    float x_average = average(train_x, train_len);
    float y_average = average(train_y, train_len);

    float slope = calculate_slope(train_x, train_y, train_len, x_average, y_average);
    float intercept = calculate_intercept(slope, x_average, y_average);

    float* pre = prediction(slope, intercept, test_x, test_len);
    printf("Simple Linear Regression LOSS: %.5f\n", calculate_residual_variance(test_y, pre, test_len));


    free(train_x);
    free(train_y);
    free(test_x);
    free(test_y);
    free(pre);

    return 0;
}