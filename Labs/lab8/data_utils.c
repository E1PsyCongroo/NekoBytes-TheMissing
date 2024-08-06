/*Create by YJS */


#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float* read_csv(int start_row, int num_rows, int start_col, char* file_path) {
    //待完成
    //开始时请删除return NULL
    return NULL;
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