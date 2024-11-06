#include <stdio.h>
#include <stdlib.h>
#include "regression.h"

#define START_COL 5
#define NUM_COL 3
#define DEGREE 2

char* file_path = "BostonHousing.csv";

int main(void) {
    int len = get_file_len(file_path);
    len -= 1; // 去掉标题行
    int train_len = len * 0.8;
    int test_len = len - train_len;

    // 读取数据并拆分为训练和测试数据
    Data train_x = read_csv(1, train_len, START_COL,NUM_COL, file_path); // 第6列：房间数量（RM）
    Data train_y = read_csv(1, train_len, 13,1, file_path); // 第14列：房价（MEDV）
    Data test_x = read_csv(train_len + 1, test_len, START_COL,NUM_COL,file_path);
    Data test_y = read_csv(train_len + 1, test_len, 13,1, file_path);

    float x_average = average(train_x);
    float y_average = average(train_y);


    float slope = calculate_slope(train_x, train_y);
    float intercept = calculate_intercept(slope, x_average, y_average);
    Vector v = calculate_multiple_regression_coefficients(train_x, train_y,DEGREE);

    float* pre = prediction(slope, intercept, test_x);
    float f = calculate_residual_variance(test_y, pre);
    printf("Simple Linear Regression LOSS: %.5f\n", f);

    float* multiple_pre = multiple_regression_prediction(test_x,DEGREE, v);
    float* train_pre = multiple_regression_prediction(train_x,DEGREE,v);
    printf("Multiple Test Regression LOSS: %.5f\n", calculate_residual_variance(test_y, multiple_pre));
    printf("Multiple Train Regression LOSS: %.5f\n", calculate_residual_variance(train_y, train_pre));

    free_Data(train_x);
    free_Data(train_y);
    free_Data(test_x);
    free_Data(test_y);
    free(pre);
    free(multiple_pre);
    free(train_pre);
    free_vector(v);
    return 0;
}