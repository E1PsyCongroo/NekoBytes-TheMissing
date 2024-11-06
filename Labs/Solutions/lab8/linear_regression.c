//
// Created by halas on 24-8-1.
//

#include <stdlib.h>
#include "regression.h"

float average(Data data) {
    float** v = data.data;
    int rows = data.rows;
    int cols = data.cols;
    float sum = 0;
    for(int i = 0;i<rows;i++){
        sum += v[i][0];
    }
    return sum / rows;
}

float calculate_slope(Data x_data,Data y_data) {
    float ** x = x_data.data;
    float ** y = y_data.data;
    float x_average = average(x_data);
    float y_average = average(y_data);
    int n = x_data.rows;
    float numerator = 0, denominator = 0;
    for(int i = 0; i < n; i++) {
        numerator += (x[i][0] - x_average) * (y[i][0] - y_average);
        denominator += (x[i][0] - x_average) * (x[i][0] - x_average);
    }
    return numerator / denominator;
}

float calculate_intercept(float slope, float x_average, float y_average) {
    return y_average - slope * x_average;
}

float calculate_residual_variance(Data actual, float* predicted) {
    float sum_squared_diff = 0;
    int n = actual.rows;
    for(int i = 0; i < n; i++) {
        float diff = actual.data[i][0] - predicted[i];
        sum_squared_diff += diff * diff;
    }
    return sum_squared_diff / n;
}

float* prediction(float slope,float intercept,Data x_data) {
    int len = x_data.rows;
    float* pre = (float*)malloc(sizeof(float)*len);
    for(int i = 0;i < len;i++)
        pre[i] = slope * x_data.data[i][0] + intercept;
    return pre;
}