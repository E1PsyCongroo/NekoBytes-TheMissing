// Created by YJS
#include <stdio.h>
#include "regression.h"

#include <criterion/criterion.h>

Test(linear,calculate_slope){
    Data x = create_Data(5,1);
    Data y = create_Data(5,1);
    // y = 2x + 1
    for(int i = 0 ; i < 5 ;i ++){
        x.data[i][0] = i;
        y.data[i][0] = i * 2 + 1;
    }
    float result = calculate_slope(x,y);
    cr_assert_eq(result,2.0);
    free_Data(x);
    free_Data(y);
}

Test(multiply,multiple_regression_predictio){
    Data x = create_Data(10,1);
    Data y = create_Data(10,1);
    // y = 3x^2 + 2x + 10
    for(int i = 0 ; i < 10 ;i ++){
        x.data[i][0] = i;
        y.data[i][0] = 3 * i * i + 2 * i + 10;
    }

    Vector coefficients = calculate_multiple_regression_coefficients(x,y,2);
    
    Data z = create_Data(1,1);
    z.data[0][0] = 10;

    float* result = multiple_regression_prediction(z,2,coefficients);
    float ans = 3 *10 * 10 + 2 * 10 + 10;

    free_vector(coefficients);
    free_Data(x);
    free_Data(y);
}

//int main(){
    //如果测试不通过，可以在下面取消注释来进行调试

    //     Data x = create_Data(5,1);
    // Data y = create_Data(5,1);
    // for(int i = 0 ; i < 5 ;i ++){
    //     x.data[i][0] = i;
    //     y.data[i][0] = i * 2 + 1;
    // }
    // float result = calculate_slope(x,y);
    // printf("%d\n",result);
    // free_Data(&x);
    // free_Data(&y);

    //上下不要同时取消注释
    /* -------------------------------------------------------------*/

    // Data x = create_Data(10,1);
    // Data y = create_Data(10,1);
    // // y = 3x^2 + 2x + 10
    // for(int i = 0 ; i < 10 ;i ++){
    //     x.data[i][0] = i;
    //     y.data[i][0] = 3 * i * i + 2 * i + 10;
    // }

    // Vector coefficients = calculate_multiple_regression_coefficients(x,y,2);
    
    // Data z = create_Data(1,1);
    // z.data[0][0] = 10;

    // float* result = multiple_regression_prediction(z,2,coefficients);
    // float ans = 3 *10 * 10 + 2 * 10 + 10;
    // printf("%f , %f \n",ans,result[0]);

    // free_Data(&x);
    // free_Data(&y);
//}

