/*Create by YJS */

#include<math.h>
#include <stdio.h>
#include <stdlib.h>
#include "perceptron.h"

float dot_product(float *v, float *u, int n) {
    float result = 0.0f;
    for (int i = 0; i < n; ++i)
        result += v[i] * u[i];
    return result;
}

float sigmoid(float x) {
    return 1.0f / (1.0f + exp(-x));
}

float sigmoid_derivative(float x) {
    return x * (1.0 - x);
}

float ReLU(float x) {
    return x>0?x:0.0f;
}

float ReLU_derivative(float x) {
    return x>0?1.0f:0.0f;
}

float tanh_(float x) {
    return tanh(x);
}

float tanh_derivative(float x) {
    float output = tanh(x);
    return 1.0f - output * output;
}

float leakyReLU(float x) {
    return x > 0 ? x : 0.01f * x;
}

float leakyReLU_derivative(float x) {
    return x > 0 ? 1.0f : 0.01f;
}


void softmax(float* v,int size) {
    float sum = 0.0f;
    for(int i = 0;i<size;i++) {
        v[i] = exp(v[i]);
        sum += v[i];
    }
    for(int i = 0;i<size;i++)
        v[i] /= sum;
}

float random_weight(int input_dim,int output_dim) {
    float limit = sqrt(6.0 / (input_dim + output_dim));
    return ((float)rand() / RAND_MAX) * 2 * limit - limit;
}

float mse_loss(float* y_true, float* y_pred, int size) {
    float loss = 0.0f;
    for (int i = 0; i < size; i++) {
        float diff = y_true[i] - y_pred[i];
        loss += diff * diff;
    }
    return loss / size;
}

float clip_gradients(float x) {
    if(x > 2.0f) {
        x = 2.0f;
    }
    else if(x < -2.0f) {
        x = -2.0f;
    }
    if(x > 0 && x < 1e-3) {
        x = 1e-3;
    }
    if(x < 0 && x > -1e-3) {
        x = -1e-3;
    }
    return x;
}

void test_loss(NeuralNet *ann,float **X, float **y,int n_samples,Activation f,int flag) {
    float loss_count = 0.0f;
    int acc_count = 0;
    float** data = NULL;
    float epsilon = 1e-6;
    if(flag) {
        data = (float**) malloc(sizeof(float*) * n_samples);
    }

    for (int i = 0;i < n_samples ;i++) {
        classification_feed_forward(ann,X[i],f);
        for(int j = 0;j < ann->output->dim.h;j++) {
            float p = ann->prediction[j] > epsilon ? ann->prediction[j] : epsilon;
            loss_count -= y[i][j] * log(p);
        }
        if(get_max_index(ann->prediction,ann->output->dim.h) == get_max_index(y[i],ann->output->dim.h))
            acc_count++;
        if(flag) {
            data[i] = malloc(sizeof(float) * ann->output->dim.h);
            for(int j = 0;j < ann->output->dim.h;j++) {
                data[i][j] = ann->prediction[j];
            }
        }
    }

    if(flag) {
        decode_vector_to_category(y,ann->output->dim.h,n_samples);
        decode_vector_to_category(data,ann->output->dim.h,n_samples);
        save_predictions_to_file(data,y,n_samples,1,"./data/prediction.csv");
    }
    if(flag) {
        for (int i = 0; i < n_samples; i++) {
            free(data[i]);
        }
        free(data);
    }

    printf("LOSS: %.5f  ACC: %.5f \n",loss_count / n_samples,(float) acc_count / n_samples);
}

void linear_test_loss(NeuralNet *ann,float **X, float **y,int n_samples,Activation f,int flag) {
    float loss_count = 0.0f;
    float** predictions = NULL;
    if(flag) {
        predictions = (float**)malloc(sizeof(float*) * n_samples);
    }
    for(int i = 0;i < n_samples ;i++) {
        linear_regression_feed_forward(ann, X[i],f);
        if(predictions != NULL) {
            predictions[i] = (float*)malloc(sizeof(float) * ann->output->dim.h);
            for(int j = 0;j < ann->output->dim.h ;j++) {
                predictions[i][j] = ann->prediction[j];
            }
        }
        loss_count += mse_loss(ann->prediction,y[i],ann->output->dim.h);
    }
    if(predictions != NULL) {
        save_predictions_to_file(predictions,y,n_samples,1,"./data/prediction.csv");
    }
    float temp = loss_count / n_samples;
    printf("LOSS: %.5f \n",temp);
    if(predictions != NULL) {
        for(int i = 0;i < n_samples; i++) {
            free(predictions[i]);
        }
        free(predictions);
    }
}

void backpropagation(NeuralNet* ann,float* input, float* y_true,float learning_rate,ActivationDerivative fd) {
    int num_layers = 0;
    for (layer* l = ann->output; l != ann->input; l = l->pre) {
        num_layers++;
    }

    float** deltas = (float**)malloc(num_layers * sizeof(float*));
    int layer_index = 0;
    for (layer* l = ann->output; l != ann->input; l = l->pre) {
        deltas[layer_index] = (float*)malloc(l->dim.h * sizeof(float));
        layer_index++;
    }

    for (int i = 0; i < ann->output->dim.h; i++) {
        deltas[0][i] = (ann->prediction[i] - y_true[i]);
    }

    layer_index = 0;
    for (layer* l = ann->output->pre; l != ann->input; l = l->pre) {
        int next_layer_index = layer_index + 1;
        for (int j = 0; j < l->dim.h; j++) {
            float delta_sum = 0.0;
            for (int k = 0; k < l->dim.w; k++) {
                delta_sum += deltas[layer_index][k] * l->weight[k][j];
            }
            deltas[next_layer_index][j] = delta_sum * fd(l->input[j]);
        }
        layer_index++;
    }


    layer_index = 0;
    for (layer* l = ann->output->pre; l != ann->input; l = l->pre) {
        for (int i = 0; i < l->dim.w; i++) {
            for (int j = 0; j < l->dim.h; j++) {
                l->weight[i][j] -= learning_rate * clip_gradients(deltas[layer_index][i]) * l->input[j];
            }
            l->biases[i] -= learning_rate * clip_gradients(deltas[layer_index][i]);
        }
        layer_index++;
    }
    for(int i = 0;i < ann->input->dim.w;i++) {
        for(int j = 0;j < ann->input->dim.h;j++) {
            ann->input->weight[i][j] -= learning_rate * clip_gradients(deltas[layer_index][i]) * input[j];
        }
        ann->input->biases[i] -= learning_rate * clip_gradients(deltas[layer_index][i]);
    }

    for (int i = 0; i < num_layers; i++) {
        free(deltas[i]);
    }
    free(deltas);
}
