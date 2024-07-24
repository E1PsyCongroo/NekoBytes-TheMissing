/*Create by YJS*/

#include "perceptron.h"
#include <stdio.h>
#include <stdlib.h>

layer* init_layer(int h){
    layer* new = (layer*)malloc(sizeof(layer));
    new->dim.h = h;
    //初始化一些未知的参数
    new->dim.w = 0;
    new->biases = NULL;
    new->weight = NULL;
    new->output = NULL;
    new->pre = NULL;
    new->next = NULL;
    return new;
}

void delete_layer(layer** n) {
    if (n == NULL || *n == NULL)
        return;
    if ((*n)->output != NULL) {
        free((*n)->output);
    }
    if ((*n)->weight != NULL) {
        for (int i = 0; i < (*n)->dim.w; i++) {
            free((*n)->weight[i]);
        }
        free((*n)->weight);
    }
    if ((*n)->biases != NULL) {
        free((*n)->biases);
    }
    free(*n);
    *n = NULL;
}


NeuralNet* init_NeuralNet(int input,int output) {
    NeuralNet* new = (NeuralNet*)malloc(sizeof(NeuralNet));
    new->input = init_layer(input);
    new->output = init_layer(output);
    connect(new->input,new->output);
    new->prediction = new->input->output;
    return new;
}

void delete_NeuralNet(NeuralNet** n) {
    if (n == NULL || *n == NULL)
        return;
    layer* p = (*n)->input;
    while (p != NULL) {
        layer* next = p->next;
        delete_layer(&p);
        p = next;
    }
    free(*n);
    *n = NULL;
}

void connect(layer* pre,layer* next){
    //待完成
    //如果前一层已经跟其他层连接了，那么先释放内存

}

void add_hidden_layer(NeuralNet* neuralnet,int h) {
    //待完成

}

void classification_feed_forward(NeuralNet *ann, float *X, Activation f) {
    //待完成

}

void linear_regression_feed_forward(NeuralNet *ann, float *X,Activation f) {
    //选做

}

void train(NeuralNet *ann, float **X, float **y, int n_samples,int n_epoch,float learning_rate,Activation f,ActivationDerivative fd){
    //遍历n_epoch次，每次遍历n_samples个样本
    for (int epoch = 0; epoch < n_epoch; epoch++) {
        //待完成


        if(epoch % 100 == 0) { //每100轮检查一下结果
            printf("Epoch: %d / %d   ",epoch,n_epoch);
            test_loss(ann,X,y,n_samples,f,0);
        }
    }
    printf("Epoch: %d / %d   ",n_epoch,n_epoch);
    test_loss(ann,X,y,n_samples,f,0);
}
