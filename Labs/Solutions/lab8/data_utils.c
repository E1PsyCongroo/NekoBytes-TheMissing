/*Create by YJS */


#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "regression.h"

Data create_Data(int rows, int cols){
    Data data;
    data.rows = rows;
    data.cols = cols;
    data.data = (float**)malloc(rows * sizeof(float*));
    for (int i = 0; i < rows; i++) {
        data.data[i] = (float*)malloc(cols * sizeof(float));
    }
    return data;
}

void free_Data(Data data){
    for (int i = 0; i < data.rows; i++) {
        free(data.data[i]);
    }
    free(data.data);
}

Data read_csv(int start_row, int num_rows, int start_col, int num_cols, char* file_path) {
    FILE *file = fopen(file_path, "r");
    if (file == NULL) {
        printf("File could not be opened.\n");
        return (Data){0, 0, NULL};
    }

    Data data = create_Data(num_rows, num_cols);
    char buffer[1024];

    for (int i = 0; i < start_row; i++) {
        if (fgets(buffer, 1024, file) == NULL) {
            fclose(file);
            free_Data(data);
            return (Data){0, 0, NULL};
        }
    }

    int row_count = 0;
    while (row_count < num_rows && fgets(buffer, 1024, file) != NULL) {
        char* token = strtok(buffer, ",");
        int current_col = 0;
        int col_count = 0;

        while (token != NULL && col_count < num_cols) {
            if (current_col >= start_col && current_col < start_col + num_cols) {
                data.data[row_count][col_count] = atof(token);
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

void delete_csv_data(float** data, int len) {
    if (data == NULL) {
        return;
    }
    for (int i = 0; i < len; i++) {
        free(data[i]);
    }
    free(data);
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