// Created by YJS
#include <stdio.h>
#include "regression.h"

int equal(float t1,float t2);
int test_calculate_slope();
int test_calculate_intercept();
int test_read_csv();

int main() {
    int flag = 1;
    flag = test_calculate_slope();
    flag = flag && test_calculate_intercept();
    flag = flag && test_read_csv();

    if(flag) {
        printf("%s","ALL PASS\n");
    }
}

int equal(float t1,float t2) {
    return t1 > t2 - 1e-4 && t1 < t2 + 1e-4;
}

int test_calculate_slope() {
    float x [] = {2,4,6};
    float y [] = {5,9,13};
    float slope = calculate_slope(x,y,3,4,9);
    if (equal(slope,2)) {
        printf("%s","calculate_slope pass\n");
        return 1;
    }
    printf("%s","calculate_slope faild\n");
    return 0;
}

int test_calculate_intercept() {
    float x [] = {2,4,6};
    float y [] = {5,9,13};
    float intercept = calculate_intercept(2,4,9);
    if (equal(intercept,1)) {
        printf("%s","calculate_intercept pass\n");
        return 1;
    }
    printf("%s","calculate_intercept faild\n");
    return 0;
}

int test_read_csv() {
    float* data = read_csv(1,3,1,"BostonHousing.csv");
    if(equal(data[0],18) && equal(data[1],0) && equal(data[2],0)) {
        printf("%s","read_csv pass\n");
        return 1;
    }
    printf("%s","read_csv faild\n");
    return 0;
}