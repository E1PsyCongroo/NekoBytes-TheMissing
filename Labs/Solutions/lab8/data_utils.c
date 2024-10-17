/*Create by YJS */


#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float* read_csv(int start_row, int num_rows, int start_col, char* file_path) {
    FILE *file = fopen(file_path, "r");
    if (file == NULL) {
        printf("File could not be opened.\n");
        return NULL;
    }

    float* data = (float*)malloc(num_rows * sizeof(float));
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

        char* token = strtok(buffer, ",");
        int current_col = 0;

        while (token != NULL) {
            if (current_col == start_col) {
                data[row_count] = atof(token);
                break;
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