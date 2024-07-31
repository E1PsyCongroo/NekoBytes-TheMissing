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

    float** data = (float**)malloc(num_rows * sizeof(float*));
    char buffer[1024];

    for (int i = 0; i < start_row; i++) {
        if (fgets(buffer, 1024, file) == NULL) {
            fclose(file);
            free(data);
            return NULL;
        }
    }

    int row_count = 0;
    while (row_count < num_rows && fgets(buffer, 1024, file) != NULL) {
        data[row_count] = (float*)malloc(num_cols * sizeof(float));
        char* token = strtok(buffer, ",");
        int current_col = 0;
        int col_count = 0;

        while (token != NULL && col_count < num_cols) {
            if (current_col >= start_col && current_col < start_col + num_cols) {
                data[row_count][col_count] = atof(token);
                col_count++;
            }
            token = strtok(NULL, ",");
            current_col++;
        }
        row_count++;
    }

    fclose(file);
    return data;
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
    for(int i = 0;i < len;i++) {
        int t = (int)data[i][0];

        data[i] = realloc(data[i], sizeof(float) * num_category);
        for(int j = 0 ;j < num_category;j++) {
            if(j == t) {
                data[i][j] = 1;
            }
            else {
                data[i][j] = 0;
            }
        }
    }
}

void decode_vector_to_category(float** data, int num_category,int len) {
    for(int i = 0;i < len;i++) {
        int maxindex = get_max_index(data[i],num_category);
        data[i] = realloc(data[i], sizeof(float));
        data[i][0] = maxindex;
    }
}