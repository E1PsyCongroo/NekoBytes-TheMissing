<div align="center">
  <img src="https://cdn.xyxsw.site/hdu-cs-wiki%20full.svg" alt="logo" width="450rem" height="450rem"/>
</div>

## 1. 项目总览

本次任务是实现一个简单的一元线性回归模型。我们将通过以下几个主要步骤来完成任务：

* **读取CSV文件**：实现一个函数 float* read_csv(int start_row, int num_rows, int col, char* file_path) 来读取指定列的数据。

* **计算回归系数和截距**：实现 float calculate_slope(float* x, float* y, int n, float x_average, float y_average) 和 float calculate_intercept(float slope, float x_average, float y_average) 来计算线性回归模型的斜率和截距。

### 编译与使用

请在本主目录下按照以下方式构建程序

    make
运行主程序：

    ./main
运行测试：

    ./test

***

## 2.代码实现

### read_csv:

打开路径为file_path的文件，读取从start_row行开始的num_rows行，第col列的数据，返回一个float数组。

可能用到的函数：

* fopen
* fclose
* malloc
* strtok
* atof

### calculate_slope:

计算线性回归模型的斜率。
在一元线性回归中，斜率（Slope, \(\beta_1\)）的计算公式为：

\[
\beta_1 = \frac{\sum_{i=1}^{n} (x_i - \bar{x})(y_i - \bar{y})}{\sum_{i=1}^{n} (x_i - \bar{x})^2}
\]

其中：
- \( x_i \) 是第 \( i \) 个数据点的自变量值。
- \( y_i \) 是第 \( i \) 个数据点的因变量值。
- \( \bar{x} \) 是自变量 \( x \) 的平均值。
- \( \bar{y} \) 是因变量 \( y \) 的平均值。
- \( n \) 是数据点的数量。

### calculate_intercept:

计算线性回归模型的截距。
在一元线性回归中，截距（Intercept, \(\beta_0\)）的计算公式为：

\[
\beta_0 = \bar{y} - \beta_1 \cdot \bar{x}
\]

其中：
- \( \beta_1 \) 是斜率。
- \( \bar{x} \) 是自变量 \( x \) 的平均值。
- \( \bar{y} \) 是因变量 \( y \) 的平均值。

***

## 3.测试

以上函数都有对应的测试，可以通过以下命令进行测试：

    ./test

我提供的测试非常简单，你可以根据需要自己编写测试

## 运行

运行主程序：

    ./main

你会看到运行结果还挺不错的。
这是应为data.csv中的数据是我自己生成的，我在一元一次函数中加了点噪声
现在我们用上真正的数据集，波士顿房价数据集来试一下
将文件名改成BostonHousing.csv
我们选择看房间数量和放假的关系
也就是把代码改成这样
```c
    float* train_x = read_csv(1, train_len, 5, file_path); // 第6列：房间数量（RM）
    float* train_y = read_csv(1, train_len, 13, file_path); // 第14列：房价（MEDV）
    float* test_x = read_csv(train_len + 1, test_len, 5, file_path);
    float* test_y = read_csv(train_len + 1, test_len, 13, file_path);

```
运行之后看起来loss还挺大的
接下来我们尝试使用多次去拟合
现在选择使用三次函数去拟合
```c
    Vector v = calculate_multiple_regression_coefficients(train_x, train_y, train_len, 3);
    float* multiple_pre = multiple_regression_prediction(test_x, test_len, v);
    printf("Multiple Regression LOSS: %.5f\n", calculate_residual_variance(test_y, multiple_pre, test_len));
```

应该可以看到loss下降了，但还是不低，能不能用更高次去拟合

尝试使用6次去拟合
```c
    Vector v = calculate_multiple_regression_coefficients(train_x, train_y, train_len, 6);
```
但是loss反而增加了
如果去把在训练集上的loss也打印出来
```c
    Vector v = calculate_multiple_regression_coefficients(train_x, train_y, train_len, 6);
    float* multiple_pre = multiple_regression_prediction(train_x, train_len, v);
    printf("Multiple Regression LOSS: %.5f\n", calculate_residual_variance(train_y, multiple_pre, train_len));
```
你会发现随着次数增加，训练集上的loss在减少，但是测试的loss基本不动甚至增加这种现象被称为过拟合。主要原因是模型过于复杂，记住了训练数据中的噪声和细节，而不是学习到数据的整体趋势。

所以我们应该选择一个合适的次数去拟合，使得训练集和测试集上的loss都尽可能小。

同时，因为我们只选择了一个特征来进行预测，选择多个特征来进行预测结果会好很多。