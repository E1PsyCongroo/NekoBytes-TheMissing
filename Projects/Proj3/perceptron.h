/*Create by YJS*/

#ifndef PERCEPTRON_H
#define PERCEPTRON_H

// 定义维度结构体
typedef struct Dim {
    int h; // 高度
    int w; // 宽度
} Dim;

// 定义层结构体，表示神经网络中的一层
typedef struct layer {
    Dim dim;         // 层的维度
    float** weight;  // 层的权重矩阵
    float* biases;   // 层的偏置向量
    float* input;    // 层的输入向量
    float* output;   // 层的输出向量
    struct layer *next, *pre; // 指向下一层和前一层的指针
} layer;

// 定义神经网络结构体，表示一个神经网络
typedef struct NeuralNet {
    layer *input;    // 指向输入层的指针
    layer *output;   // 指向输出层的指针
    float* prediction; // 神经网络的预测结果向量
} NeuralNet;

// 激活函数及其导数类型定义
typedef float (*Activation) (float); // 激活函数
typedef float (*ActivationDerivative)(float); // 激活函数的导数

extern void (*print_loss)(NeuralNet *,float**,float**,int,Activation,int);
extern void (*feed_forward)(NeuralNet *,float*,Activation);

// 函数声明部分

// 初始化一层，返回指向该层的指针
layer* init_layer(int h);

// 删除一层，释放内存
void delete_layer(layer* n);

// 初始化一个神经网络，返回指向该神经网络的指针
NeuralNet* init_NeuralNet(int input, int output);

// 删除一个神经网络，释放内存
void delete_NeuralNet(NeuralNet* n);

// 连接两层
void connect(layer* pre, layer* next);

// 为神经网络添加隐藏层
void add_hidden_layer(NeuralNet* neuralnet, int h);

// 线性回归的前向传播
void linear_feed_forward(NeuralNet *ann, float *X, Activation f);

// 分类的前向传播
void classification_feed_forward(NeuralNet *ann, float *X, Activation f);

// 训练神经网络
void train(NeuralNet *ann, float **X, float **y, int n_samples, int n_epoch, float learning_rate, Activation f, ActivationDerivative fd);

// 点乘运算
float dot_product(float *v, float *u, int n);

// 激活函数和激活函数的导数
float sigmoid(float x);
float sigmoid_derivative(float x);
float ReLU_derivative(float x);
float ReLU(float x);
float tanh_(float x);
float tanh_derivative(float x);
float leakyReLU(float x);
float leakyReLU_derivative(float x);

// 随机初始化权重
float random_weight(int input_dim, int output_dim);

// 均方误差损失函数
float mse_loss(float* y_true, float* y_pred, int size);

// 反向传播算法
void backpropagation(NeuralNet* ann, float* input, float* y_true, float learning_rate, ActivationDerivative f);

// 梯度裁剪
float clip_gradients(float x);

// softmax函数
void softmax(float* v, int size);

// 测试损失函数
void classification_test_loss(NeuralNet *ann, float **X, float **y, int n_samples, Activation f, int flag);

// 线性回归的测试损失函数
void linear_test_loss(NeuralNet *ann, float **X, float **y, int n_samples, Activation f, int flag);

// 删除读取的CSV数据
void delete_csv_data(float** data, int len);

// 读取CSV数据
float** read_csv(int start_row, int num_rows, int start_col, int num_cols, char* file_path);

// 获取文件行数
int get_file_len(char* file_path);

// 将预测结果保存到文件
void save_predictions_to_file(float **predictions, float** actual, int n_samples, int n_outputs, char* file_path);

// 将种类编码为向量
void encode_category_to_vector(float** data, int category, int len);

// 将向量解码为种类
void decode_vector_to_category(float** data, int num_category, int len);

// 获取向量中最大值的索引
int get_max_index(float* v, int num_category);

#endif // PERCEPTRON_H

