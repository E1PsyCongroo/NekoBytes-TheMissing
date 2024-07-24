<div align="center">
  <img src="https://cdn.xyxsw.site/hdu-cs-wiki%20full.svg" alt="logo" width="450rem" height="450rem"/>
</div>

***

## 1. 项目总览
本次任务的目标是搭建一个简单的神经网络来实现手机价格区间分类任务
任务中有关数学的大部分都已完成、。
本次搭建的神经网络非常简单，所以在一些复杂的数据集上取得不好的成绩是正常的


本次任务中unity_internals.h,unity.h和unity.c是用于编写测试的第三方库，无需更改
math.c是完成好的有关数学部分的代码，也无需修改


你需要修改的函数如下
* connect() in perceptron.c
* add_hidden_layer() in perceptron.c
* classification_feed_forward() in perceptron.c
* linear_regression_feed_forward() in perceptron.c(选做)
* train() in perceptron.c
* read_csv() in data_utils.c
* encode_category_to_vector()和decode_vector_to_category() in data_utils.c

### 编译与使用

请在本主目录下按照以下方式构建程序

    make
运行主程序：

    ./main
运行测试：

    ./test

***
## 2.神经网络的构建
在神经网络中，通常权重矩阵的维度是 [input][output]即每一行表示一个输入节点的权重，每一列表示一个输出节点的权重。比如，现在有一个输入长度为2，输出长度为3的层，那么它的权重矩阵将是[2][3]。然而，在这次作业中，我们的权重矩阵是[w][h] 类型的，即每一行表示一个输出节点的权重，每一列表示一个输入节点的权重，这与常规的权重矩阵不同。所以在之前的列子中我们的权重矩阵是[3][2]

<u>在尝试编写此函数之前请认真阅读有关layer和NeuralNet的初始化和删除代码！</u>

### void connect(layer* pre,layer* next):用于连接两个层
connect的作用是将pre和next连接在一起，就像链表一样!
除了使用layer中的指针将两者相连外，你还需要完成以下的事情
* 初始化pre的w变量，它的输出长度就是next的输入长度
* 为pre的output分配空间
* 初始化pre的权重矩阵，一旦w,h都已知，权重矩阵的大小就可以确定了.<u>权重矩阵的初始值请调用函数random_weight来获得！</u>
* 初始化pre的偏置向量，偏执向量的长度等于输出长度.偏置向量的初始值是0

 请注意！如果pre原来已经跟其他层相连过了，那么它的output,weight等都是非空的，在重新分配前不要忘记释放内存！

你可能会使用的函数：
* random_weight(int input_dim,int output_dim):input_dim和output_dim是本层的输入长度和输出长度
* free 和 malloc 用于释放和分配内存



### add_hidden_layer(NeuralNet* neuralnet,int h):用于向网络中添加隐藏层
add_hidden_layer 函数的作用是向现有的神经网络中添加一个新的隐藏层，并将其正确地连接到现有的层中。你需要完成
* 新建一个长度为h层
* 用connect将新层插入网络中
* 注意neuralnet的prediction的指向

你可能会使用的函数：
* init_layer(int h)
* connect(layer* pre,layer* next)


完成上述两个函数后，现在我们已经能搭建起一个简单的神经网络了，接下来我们就可以使用这个神经网络来训练和预测了！

***
## 3. 神经网络的训练

假设有一个单层神经网络，前向传播的公式可以表示为：

\[ z = W \cdot x + b \]
\[ a = f(z) \]

其中：
- \( W \) 是权重矩阵
- \( x \) 是输入向量
- \( b \) 是偏置向量
- \( z \) 是线性变换后的结果
- \( a \) 是激活函数 \( f \) 应用于 \( z \) 后的输出

假设有一个神经网络层，激活函数为 \( f \)，层的维度为 \( h = 2 \) 和 \( w = 2 \)，其权重矩阵和偏置向量如下：

权重矩阵：
\[
W = \begin{bmatrix}
1 & 0 \\
2 & 3 \\
\end{bmatrix}
\]

偏置向量：
\[
b = \begin{bmatrix}
b_0 \\
b_1 \\
\end{bmatrix}
\]

输入向量：
\[
x = \begin{bmatrix}
1 \\
2 \\
\end{bmatrix}
\]

计算输出：
\[
\begin{aligned}
z_0 &= W_{00} \cdot x_0 + W_{01} \cdot x_1 + b_0 \\
    &= 1 \cdot 1 + 0 \cdot 2 + b_0 \\
    &= 1 + b_0 \\
a_0 &= f(z_0)
\end{aligned}
\]

\[
\begin{aligned}
z_1 &= W_{10} \cdot x_0 + W_{11} \cdot x_1 + b_1 \\
    &= 2 \cdot 1 + 3 \cdot 2 + b_1 \\
    &= 2 + 6 + b_1 \\
    &= 8 + b_1 \\
a_1 &= f(z_1)
\end{aligned}
\]

输出向量：
\[
a = \begin{bmatrix}
a_0 \\
a_1 \\
\end{bmatrix}
\]

其中：
- \( W \) 是权重矩阵
- \( b \) 是偏置向量
- \( x \) 是输入向量
- \( z \) 是线性变换后的结果
- \( a \) 是激活函数 \( f \) 应用于 \( z \) 后的输出

### classification_feed_forward(NeuralNet *ann, float *X, Activation f):前向传播

classification_feed_forward 函数用于执行神经网络的前向传播，以进行分类任务。该函数将输入向量传递给神经网络的输入层，然后依次计算每一层的输出，直到最终输出层。最后，通过 softmax 函数计算输出层的分类概率。

你需要完成：

* 遍历每一层（直到输出层），计算每个神经元的输出。计算公式为：
\[
\text{output}[j] = f\left( \sum_{k=0}^{h-1} \text{input}[k] \cdot \text{weight}[j][k] \right) + \text{biases}[j]
\]

* 对输出层的每个神经元，计算线性变换结果。计算公式为：
\[
\text{output}[j] = \sum_{k=0}^{h-1} \text{input}[k] \cdot \text{weight}[j][k] + \text{biases}[j]
\]

* 对输出层的结果应用 softmax 函数，计算分类概率。
* 第一层的输入是input,其他层的输入是前一层的输出


你可能需要用到的函数:
* dot_product(float *v, float *u, int size):计算两个向量的点积
* softmax(float *v, int size):计算 softmax 函数

当你完成这个函数后应该可以通过classification_feed_forward的测试

### train(NeuralNet *ann, float **X, float **y, int n_samples,int n_epoch,float learning_rate,Activation f,ActivationDerivative fd):训练神经网络

train 函数用于训练神经网络，以最小化损失函数。该函数将输入数据集和目标标签传递给神经网络，并使用梯度下降算法更新神经网络的权重和偏置，以最小化损失函数。

你需要完成：
* 对每个样本，执行前向传播
* 使用反向传播，计算梯度和更新参数
* 重复上述步骤，直到达到指定的训练轮数

你可能需要用到的函数:
* backpropagation(NeuralNet* ann, float* input, float* y_true, float learning_rate, ActivationDerivative f):反向传播函数，在前向传播后调用来计算梯度并更新参数

***
## 4. 数据的读取和处理

### read_csv(int start_row, int num_rows, int start_col, int num_cols, char* file_path):用于读取数据
read_csv 函数用于从指定的CSV文件中读取数据。该函数从指定的行和列开始读取数据，并将读取的数据存储在二维浮点数组中
参数
* int start_row: 从第几行开始读取数据。
* int num_rows: 要读取的行数。
* int start_col: 从第几列开始读取数据。
* int num_cols: 要读取的列数。
* char* file_path: CSV 文件的路径。

你需要完成：

* 跳过指定的行数，开始读取数据
* 从指定的列开始读取数据，并存储在二维浮点数组中
* 读取完成后，返回指向该数组的指针

你可能需要用到的函数:

* fopen: 打开文件
* fgets: 读取文件中的一行
* strtok: 分割字符串
* atof: 将字符串转换为浮点数
* malloc: 分配内存
* free: 释放内存

运行test可以检查是否正确

### encode_category_to_vector()和decode_vector_to_category():用于将分类标签编码为向量/将向量解码为分类标签

encode_category_to_vector 和 decode_vector_to_category 函数用于在分类问题中处理分类标签和向量之间的转换。

encode_category_to_vector 函数将分类标签编码为独热编码向量（One-Hot Encoding）。每个分类标签将被转换为一个向量，其中只有一个元素为1，其他元素为0。
encode_category_to_vector 函数遍历数据数组，将每个分类标签编码为独热编码向量。假设分类种类数量为4，分类标签为2的样本将被编码为 [0, 0, 1, 0]。
假设数据中有以下分类标签：

    data = [[2], [0], [3]]

编码后变为：

    data = [[0, 0, 1, 0], [1, 0, 0, 0], [0, 0, 0, 1]]

decode_vector_to_category 函数将独热编码向量解码为分类标签。每个向量将被转换为其最大值所在的索引。

假设数据中有以下独热编码向量：

    data = [[0, 0, 1, 0], [1, 0, 0, 0], [0, 0, 0, 1]]

解码后变为：

    data = [[2], [0], [3]]
    
你需要完成：

* 编写 encode_category_to_vector 函数，将分类标签编码为独热编码向量。
* 编写 decode_vector_to_category 函数，将独热编码向量解码为分类标签。

你可能需要用到的函数:

* get_max_index(float* v,int num_category):返回数组中最大值的下标
* realloc:重新分配内存

运行test可以检查是否正确

到此为止，你已经完成了全部的函数编写！

***
## 5.运行

<u>test提供的测试非常简单，就算通过了test也并不能保证一定正确！</u>

运行main程序，会用data.csv来进行测试,测试机按2：8拆分成训练集和测试集，训练集用于训练神经网络，测试集用于测试神经网络。

你可以更改网络的隐藏层，种子，学习率和训练轮数来观察神经网络的表现。

每次运行完后会显示测试集上的正确率，测试机上的结果会保存prediction.csv中,你可以打开查看。

## 选作

### 更多的激活函数
你可以尝试更多的激活函数，我提供了 ReLU、Leaky ReLU、Sigmoid、Tanh。这些激活函数在神经网络中经常使用

在main.c中下面的代码中更换激活函数

```c
    train(n,train_data,train_ans,train_len,n_epoch,learnint_rate,ReLU,ReLU_derivative);
    printf("TEST LOSS :");
    test_loss(n,test_date,test_ans,test_len,ReLU,1);
```
我们在main中使用了ReLU作为激活函数，你可以尝试使用其他激活函数，观察神经网络的表现
修改ReLU,ReLU_derivative为对应的激活函数和激活函数的导数

* 如果想使用tanh,需要调用tanh_函数，因为tanh已经被定义在了math.h中
* 更换激活函数你可能会看到正确率下降。每个激活函数对学习率的敏感度不同，你可能需要调整学习率来适应你选择的激活函数

### 线性回归预测

我们之前完成的神经网络，只能用于分类问题，现在我们尝试使用神经网络进行线性回归预测。

完成perceptron.c中的linear_regression_feed_forward函数。他与classification_feed_forward的唯一区别就是最后一层不需要应用任何的激活函数.
同时需要修改train,更换前向传播的函数和测试函数，需要将test_loss改为linear_test_loss(已完成),不需要修改test_loss传递的参数,不需要修改反向传播函数.

完成之后请尝试自己编写main程序，自己设计神经网络.可以使用linear_data.csv进行测试,这是一份关于水泥强硬度的数据集。你也可以尝试寻找其他的训练集进行测试