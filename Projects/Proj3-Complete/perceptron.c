/*Create by YJS*/

#include "perceptron.h"
#include <stdio.h>
#include <stdlib.h>

void (*print_loss)(NeuralNet *,float**,float**,int,Activation,int) = linear_test_loss;
void (*feed_forward)(NeuralNet *,float*,Activation) = linear_feed_forward;

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

void delete_layer(layer* n) {
    if (n == NULL) {
        return;
    }
    if (n->output != NULL) {
        free(n->output);
    }
    if (n->weight != NULL) {
        for (int i = 0; i < n->dim.w; i++) {
            free(n->weight[i]);
        }
        free(n->weight);
    }
    if (n->biases != NULL) {
        free(n->biases);
    }
    free(n);
}


NeuralNet* init_NeuralNet(int input,int output) {
    NeuralNet* new = (NeuralNet*)malloc(sizeof(NeuralNet));
    new->input = init_layer(input);
    new->output = init_layer(output);
    connect(new->input,new->output);
    new->prediction = new->input->output;
    return new;
}

void delete_NeuralNet(NeuralNet* n) {
    if (n == NULL)
        return;
    layer* p = n->input;
    while (p != NULL) {
        layer* next = p->next;
        delete_layer(p);
        p = next;
    }
    free(n);
}

void connect(layer* pre,layer* next){
    //如果前一层已经跟其他层连接了，那么先释放内存
    if(pre->weight != NULL){
        for(int i = 0;i < pre->dim.w;i++) {
            free(pre->weight[i]);
        }
        free(pre->weight);
    }
    if(pre->biases != NULL){
        free(pre->biases);
    }
    if(pre->output!=NULL){
        free(pre->output);
    }

    pre->dim.w = next->dim.h;
    pre->next = next;
    pre->weight = (float**)malloc(sizeof(float*) * pre->dim.w);
    pre->biases = (float*)malloc(sizeof(float) * pre->dim.w);
    pre->output = (float*)malloc(sizeof(float) * pre->dim.w);

    next->pre = pre;
    next->input = pre->output;

    for(int i = 0;i<pre->dim.w;i++) {
        pre->biases[i] = 0.0f;
        pre->weight[i] = (float*) malloc(sizeof(float) * pre->dim.h);
        for(int j = 0;j<pre->dim.h;j++) {
            pre->weight[i][j] = random_weight(pre->dim.h,next->dim.h);
        }
    }
}

void add_hidden_layer(NeuralNet* neuralnet,int h) {
    int flag = 0;
    layer* new = init_layer(h);
    if(neuralnet->input->next == neuralnet->output)
        flag = 1;
    layer* temp = neuralnet->input->next;

    connect(neuralnet->input, new);
    connect(new, temp);
    if(flag)
        neuralnet->prediction = new -> output;
}

void linear_feed_forward(NeuralNet *ann, float *X,Activation f) {
    ann->input->input = X;

    layer* i = ann->input;
    for(;i->next != ann->output;i = i->next) {
        for(int j = 0;j < i->dim.w ;j++) {
            i->output[j] = f(dot_product(i->input,i->weight[j],i->dim.h)) + i->biases[j];
        }
    }
    for(int j = 0;j < i->dim.w; j++) {
       i->output[j] =  dot_product(i->input,i->weight[j],i->dim.h) + i->biases[j];
    }
}

void classification_feed_forward(NeuralNet *ann, float *X, Activation f) {
    ann->input->input = X;

    layer* i = ann->input;
    for(;i->next != ann->output;i = i->next) {
        for(int j = 0;j < i->dim.w ;j++) {
            i->output[j] = f(dot_product(i->input,i->weight[j],i->dim.h)) + i->biases[j];
        }
    }
    for(int j = 0;j < i->dim.w; j++) {
        i->output[j] =  dot_product(i->input,i->weight[j],i->dim.h) + i->biases[j];
    }

    softmax(ann->output->input,ann->output->dim.h);
}

void train(NeuralNet *ann, float **X, float **y, int n_samples,int n_epoch,float learning_rate,Activation f,ActivationDerivative fd){
    //遍历n_epoch次，每次遍历n_samples个样本
    for (int epoch = 0; epoch < n_epoch; epoch++) {
        for (int i = 0; i < n_samples; i++) {
            feed_forward(ann, X[i],f);
            backpropagation(ann, X[i],y[i], learning_rate, fd);
        }
        if(epoch % 100 == 0) {
            printf("Epoch: %d / %d   ",epoch,n_epoch);
            print_loss(ann,X,y,n_samples,f,0);
        }
    }
    printf("Epoch: %d / %d   ",n_epoch,n_epoch);
    print_loss(ann,X,y,n_samples,f,0);
}
