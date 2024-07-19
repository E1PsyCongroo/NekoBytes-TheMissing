/*Create by YJS*/

#include <stdio.h>
#include <stdlib.h>
#include "perceptron.h"

unsigned int seed = 20; //种子
static char file_name[] = "./data/data.csv"; //文件名
static float learnint_rate = 0.001; //学习率
static int n_epoch = 1000; // 训练次数


int main() {
    srand(seed);
    //读取数据并拆分训练集和测试集
    int file_len = get_file_len(file_name) -1;
    int train_len = (int)(0.8*file_len);
    int test_len = file_len - train_len;
    float** train_data = read_csv(1,train_len,0,20,file_name);
    float** train_ans = read_csv(1,train_len,20,1,file_name);
    float** test_date = read_csv(train_len+1,file_len - train_len,0,20,file_name) ;
    float** test_ans = read_csv(train_len+1,file_len - train_len,20,1,file_name);

    encode_category_to_vector(train_ans,4,train_len); //处理分类标签，如果是做线性回归预测则不需要这两行
    encode_category_to_vector(test_ans,4,test_len);

    NeuralNet* n = init_NeuralNet(20,4);
    add_hidden_layer(n,20);

    train(n,train_data,train_ans,train_len,n_epoch,learnint_rate,ReLU,ReLU_derivative);
    printf("TEST LOSS :");
    test_loss(n,test_date,test_ans,test_len,ReLU,1);

    //释放内存
    delete_NeuralNet(&n);
    delete_csv_data(&train_data,train_len);
    delete_csv_data(&train_ans,train_len);
    delete_csv_data(&test_date,test_len);
    delete_csv_data(&test_ans,test_len);
    return 0;
}
