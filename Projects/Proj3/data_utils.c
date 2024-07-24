/*Create by YJS */

#include "perceptron.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float** read_csv(int start_row, int num_rows, int start_col, int num_cols, char* file_path) {
    FILE *file = fopen(file_path, "r");
    if (file == NULL) {
        printf("File could not be opened.\n");
        return NULL;
    }
    //待完成，开始前先删除return NULL
    return NULL;
}

int get_max_index(float* v,int num_category) {
    //这个函数用于找到向量中最大元素的索引
    int maxindex = 0;
    for(int j = 1;j < num_category;j++) {
        if(v[j] > v[maxindex])
            maxindex= j;
    }
    return maxindex;
}

void encode_category_to_vector(float** data,int num_category,int len) {
    //待完成

}

void decode_vector_to_category(float** data, int num_category,int len) {
    //待完成

}

void delete_csv_data(float*** data, int len) {
    if (data == NULL || *data == NULL) {
        return;
    }
    for (int i = 0; i < len; i++) {
        free((*data)[i]);
    }
    free(*data);
    *data = NULL;
}

int get_file_len(char* file_path) {
    //获取文件的长度
    FILE *file = fopen(file_path, "r");
    int count = 0;
    char buffer[1024];
    while (fgets(buffer, 1024, file) != NULL) {
        count++;
    }
    fclose(file);
    return count;
}

void save_predictions_to_file(float** predictions,float** actual, int n_samples, int n_outputs, char* file_path) {
    FILE *file = fopen(file_path, "w");
    if (file == NULL) {
        printf("File could not be opened.\n");
        return;
    }

    for (int i = 0; i < n_samples; i++) {
        fprintf(file,"predictions: ");
        for (int j = 0; j < n_outputs; j++) {
            fprintf(file, "%.5f ", predictions[i][j]);
        }
        fprintf(file," actual: ");
        for (int j = 0; j < n_outputs; j++) {
            fprintf(file, "%.5f ", actual[i][j]);
        }
        fprintf(file, "\n");
    }
    fclose(file);
}