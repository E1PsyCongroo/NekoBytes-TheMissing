// Created by YJS

#include <stdlib.h>

float average(float* v,int len) {
    float sum = 0;
    for(int i = 0;i<len;i++)
        sum += v[i];
    return sum / len;
}

float calculate_slope(float* x, float* y, int n, float x_average, float y_average) {
    //待完成
}

float calculate_intercept(float slope, float x_average, float y_average) {
    //待完成
}

float calculate_residual_variance(float* actual, float* predicted, int n) {
    float sum_squared_diff = 0;
    for(int i = 0; i < n; i++) {
        float diff = actual[i] - predicted[i];
        sum_squared_diff += diff * diff;
    }
    return sum_squared_diff / n;
}

float* prediction(float slope,float intercept,float* x,int len) {
    float* pre = (float*)malloc(sizeof(float)*len);
    for(int i = 0;i < len;i++)
        pre[i] = slope * x[i] + intercept;
    return pre;
}