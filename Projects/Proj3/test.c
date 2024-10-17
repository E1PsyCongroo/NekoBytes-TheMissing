/*Create by YJS*/

#include <stdlib.h>
#include "perceptron.h"
#include "unity.h"

NeuralNet* net = NULL;
float* input = NULL;
float** data = NULL;
float** v = NULL;


void setUp() {}
void tearDown() {
    if(net != NULL) {
        delete_NeuralNet(net);
        net = NULL;
    }
    if(input != NULL) {
        free(input);
        input = NULL;
    }
    if(data!=NULL) {
        delete_csv_data(data,3);
        data = NULL;
    }
    if(v != NULL){
        delete_csv_data(v,4);
        v = NULL;
    }
}



void connect_test_win() {
    srand(123);
    net = init_NeuralNet(2,2);

    TEST_ASSERT_EQUAL(net->input->pre,NULL);
    TEST_ASSERT_EQUAL(net->output->weight,NULL);
    TEST_ASSERT_EQUAL(net->output->biases,NULL);
    TEST_ASSERT_EQUAL(net->output->next,NULL);
    float** t = net->input->weight;

    TEST_ASSERT_FLOAT_WITHIN(1e-3,-1.191853,t[0][0]);
    TEST_ASSERT_FLOAT_WITHIN(1e-3,0.199558,t[0][1]);
    TEST_ASSERT_FLOAT_WITHIN(1e-3,0.500222,t[1][0]);
    TEST_ASSERT_FLOAT_WITHIN(1e-3,-0.245158,t[1][1]);
}

void add_hidden_layer_test_win() {
    srand(123);
    net = init_NeuralNet(2,2);
    add_hidden_layer(net,2);

    TEST_ASSERT_EQUAL(net->input->next->next,net->output);
    TEST_ASSERT_EQUAL(net->input->next,net->output->pre);
    float** t = net->input->next->weight;
    TEST_ASSERT_FLOAT_WITHIN(1e-3,-0.495138,t[0][0]);
    TEST_ASSERT_FLOAT_WITHIN(1e-3,0.873173,t[0][1]);
    TEST_ASSERT_FLOAT_WITHIN(1e-3,0.302420,t[1][0]);
    TEST_ASSERT_FLOAT_WITHIN(1e-3,-1.168679,t[1][1]);

    t = net->input->weight;
    TEST_ASSERT_FLOAT_WITHIN(1e-3,1.194544,t[0][0]);
    TEST_ASSERT_FLOAT_WITHIN(1e-3,-0.980671,t[0][1]);
    TEST_ASSERT_FLOAT_WITHIN(1e-3,1.073890,t[1][0]);
    TEST_ASSERT_FLOAT_WITHIN(1e-3,1.218092,t[1][1]);
}

void connect_test() {
    srand(123);
    net = init_NeuralNet(2,2);

    TEST_ASSERT_EQUAL(net->input->pre,NULL);
    TEST_ASSERT_EQUAL(net->output->weight,NULL);
    TEST_ASSERT_EQUAL(net->output->biases,NULL);
    TEST_ASSERT_EQUAL(net->output->next,NULL);
    float** t = net->input->weight;

    TEST_ASSERT_FLOAT_WITHIN(1e-3,-1.077650,t[0][0]);
    TEST_ASSERT_FLOAT_WITHIN(1e-3,0.706233,t[0][1]);
    TEST_ASSERT_FLOAT_WITHIN(1e-3,-0.727331,t[1][0]);
    TEST_ASSERT_FLOAT_WITHIN(1e-3,-0.370943,t[1][1]);
}

void add_hidden_layer_test() {
    srand(123);
    net = init_NeuralNet(2,2);
    add_hidden_layer(net,2);

    TEST_ASSERT_EQUAL(net->input->next->next,net->output);
    TEST_ASSERT_EQUAL(net->input->next,net->output->pre);
    float** t = net->input->next->weight;
    TEST_ASSERT_FLOAT_WITHIN(1e-3,-1.116193,t[0][0]);
    TEST_ASSERT_FLOAT_WITHIN(1e-3,0.929732,t[0][1]);
    TEST_ASSERT_FLOAT_WITHIN(1e-3,0.319329,t[1][0]);
    TEST_ASSERT_FLOAT_WITHIN(1e-3,-0.300932,t[1][1]);

    t = net->input->weight;
    TEST_ASSERT_FLOAT_WITHIN(1e-3,-0.338986,t[0][0]);
    TEST_ASSERT_FLOAT_WITHIN(1e-3,-0.894949,t[0][1]);
    TEST_ASSERT_FLOAT_WITHIN(1e-3,-0.303815,t[1][0]);
    TEST_ASSERT_FLOAT_WITHIN(1e-3,-0.589539,t[1][1]);
}

void linear_feed_forward_test() {
    net = init_NeuralNet(2,2);
    add_hidden_layer(net,2);
    net->input->weight[0][0] = 0;
    net->input->weight[0][1] = 0;
    net->input->weight[1][0] = 2;
    net->input->weight[1][1] = -1;
    layer* next = net->input->next;
    next->weight[0][0] = 5;
    next->weight[0][1] = 3;
    next->weight[1][0] = 0;
    next->weight[1][1] = 2;
    next->biases[0] = 1;

    float* input = (float*)malloc(sizeof(float) * 2);
    input[0] = -1;
    input[1] = -2;
    linear_feed_forward(net,input,sigmoid);
    TEST_ASSERT_FLOAT_WITHIN(1e-3,5,net->prediction[0]);
    TEST_ASSERT_FLOAT_WITHIN(1e-3,1,net->prediction[1]);

    free(input);
}

void read_csv_test() {
     data = read_csv(1,3,1,4,"./data/read_test.csv");
    for(int i = 1;i < 4 ;i++) {
        for(int j = 1;j < 5 ;j++) {
            TEST_ASSERT_FLOAT_WITHIN(1e-3,8*i+j,data[i-1][j-1]);
        }
    }
}

void classification_feed_forward_test() {
    net = init_NeuralNet(2,2);
    add_hidden_layer(net,2);
    net->input->weight[0][0] = 0;
    net->input->weight[0][1] = 0;
    net->input->weight[1][0] = 2;
    net->input->weight[1][1] = -1;
    layer* next = net->input->next;
    next->weight[0][0] = 5;
    next->weight[0][1] = 3;
    next->weight[1][0] = 0;
    next->weight[1][1] = 2;
    next->biases[0] = 1;

    float* input = (float*)malloc(sizeof(float) * 2);
    input[0] = -1;
    input[1] = -2;
    classification_feed_forward(net,input,sigmoid);
    TEST_ASSERT_FLOAT_WITHIN(1e-3,0.9820138,net->prediction[0]);
    TEST_ASSERT_FLOAT_WITHIN(1e-3,0.01798621,net->prediction[1]);

    free(input);
}

void decode_vector_to_category_test(){
    v = (float**)malloc(sizeof(float*) * 4);
    for(int i = 0;i < 4;i++) {
        v[i] = (float*)malloc(sizeof(float) * 4);
    }
    for(int i = 0;i < 4;i++){
        for(int j = 0;j < 4 ;j++){
            if(i == j){
                v[i][j] = 1;
            }
            else{
                v[i][j] = 0;
            }
        }
    }

    decode_vector_to_category(v,4,4);
    for(int i = 0;i < 4;i++){
        TEST_ASSERT_EQUAL(i,v[i][0]);
    }
}

void encode_category_to_vector_test() {
    v = (float**)malloc(sizeof(float*) * 4);
    for(int i = 0;i < 4;i++) {
        v[i] = (float*)malloc(sizeof(float) * 1);
    }
    for(int i = 0;i < 4 ;i++) {
        v[i][0] = i;
    }

    encode_category_to_vector(v,4,4);
    for(int i = 0;i < 4;i++) {
        for(int j = 0;j < 4;j++) {
            if(i == j) {
                TEST_ASSERT_EQUAL(1,v[i][j]);
            }
            else {
                TEST_ASSERT_EQUAL(0,v[i][j]);
            }
        }
    }
}


int main() {
    UNITY_BEGIN();

    RUN_TEST(connect_test);
    RUN_TEST(add_hidden_layer_test);

    RUN_TEST(classification_feed_forward_test);

    RUN_TEST(read_csv_test);
    RUN_TEST(decode_vector_to_category_test);
    RUN_TEST(encode_category_to_vector_test);
    return UNITY_END();
}
