#include <stdio.h>
#include <stdlib.h>
#include "regression.h"

char* file_path = "BostonHousing.csv";

int main(void) {
    int len = get_file_len(file_path);
    len -= 1; // 去掉标题行
    int train_len = len * 0.8;
    int test_len = len - train_len;

    // 读取数据并拆分为训练和测试数据
    float* train_x = read_csv(1, train_len, 5, file_path); // 第6列：房间数量（RM）
    float* train_y = read_csv(1, train_len, 13, file_path); // 第14列：房价（MEDV）
    float* test_x = read_csv(train_len + 1, test_len, 5, file_path);
    float* test_y = read_csv(train_len + 1, test_len, 13, file_path);

    float x_average = average(train_x, train_len);
    float y_average = average(train_y, train_len);

    float slope = calculate_slope(train_x, train_y, train_len, x_average, y_average);
    float intercept = calculate_intercept(slope, x_average, y_average);
    Vector v = calculate_multiple_regression_coefficients(train_x, train_y, train_len, 6);

    float* pre = prediction(slope, intercept, test_x, test_len);
    printf("Simple Linear Regression LOSS: %.5f\n", calculate_residual_variance(test_y, pre, test_len));

    float* multiple_pre = multiple_regression_prediction(test_x, test_len, v);
    float* train_pre = multiple_regression_prediction(train_x, train_len, v);
    printf("Multiple Regression LOSS: %.5f\n", calculate_residual_variance(test_y, multiple_pre, test_len));
    printf("Multiple Regression LOSS: %.5f\n", calculate_residual_variance(train_y, train_pre, train_len));

    free(train_x);
    free(train_y);
    free(test_x);
    free(test_y);
    free(pre);
    free(multiple_pre);
    free_vector(v);

    return 0;
}