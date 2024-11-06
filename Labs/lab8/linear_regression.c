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
    //TODO

    return 0;
}

float calculate_intercept(float slope, float x_average, float y_average) {
    //TODO
    
    return 0;
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