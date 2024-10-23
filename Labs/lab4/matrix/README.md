# 问题描述

在之前的学习中我们学习使用了二维数组

在线性代数中也存在与二维数组极其相似的结构——矩阵

矩阵是一个按照矩形排列的数字、符号或表达式的集合，通常用于表示线性方程组、变换和数据。


一个矩阵 $ A $ 是一个由 $ m $ 行和 $ n $ 列组成的数组，可以表示为：

$$
A = \begin{bmatrix}
a_{11} & a_{12} & \cdots & a_{1n} \\
a_{21} & a_{22} & \cdots & a_{2n} \\
\vdots & \vdots & \ddots & \vdots \\
a_{m1} & a_{m2} & \cdots & a_{mn}
\end{bmatrix}
$$

其中 $ a_{ij} $ 表示矩阵中第 $ i $ 行第 $ j $ 列的元素。

显然，我们可以用二维数组来存储矩阵

同时，线性代数中对矩阵之间的乘法做出了描述

给定两个矩阵 $ A $ 和 $ B $，它们的乘积 $ C = AB $ 定义为：

如果 $ A $ 是一个 $ m \times n $ 矩阵，$ B $ 是一个 $ n \times p $ 矩阵，则它们的乘积 $ C $ 是一个 $ m \times p $ 矩阵。

矩阵 $ C $ 的元素 $ C_{ij} $ 由以下公式计算：

$$
C_{ij} = \sum_{k=1}^{n} A_{ik} B_{kj}
$$


考虑以下两个矩阵：

$$
A = \begin{bmatrix}
1 & 2 \\
3 & 4
\end{bmatrix}, \quad
B = \begin{bmatrix}
5 & 6 \\
7 & 8
\end{bmatrix}
$$

它们的乘积 $ C = AB $ 为：

$$
\begin{align*}
C &= \begin{bmatrix}
1 & 2 \\
3 & 4
\end{bmatrix}
\begin{bmatrix}
5 & 6 \\
7 & 8
\end{bmatrix} \\
&= \begin{bmatrix}
1 \cdot 5 + 2 \cdot 7 & 1 \cdot 6 + 2 \cdot 8 \\
3 \cdot 5 + 4 \cdot 7 & 3 \cdot 6 + 4 \cdot 8
\end{bmatrix} \\
&= \begin{bmatrix}
19 & 22 \\
43 & 50
\end{bmatrix}
\end{align*}
$$

# 实验要求

对于矩阵乘法，朴素的迭代算法实现如下：

```c
for (i = 0; i < A.r; i++) {
  for (j = 0; j < B.c; j++) {
    for (k = 0; k < A.c; k++) {
      C[i][j] += A[i][k] * B[k][j];
    }
  }
}
```

显然

$$
\begin{align*}
\begin{bmatrix}
C_{11} & C_{12} \\
C_{21} & C_{22}
\end{bmatrix}
&=
\begin{bmatrix}
A_{11} & A_{12} \\
A_{21} & A_{22}
\end{bmatrix}
\begin{bmatrix}
B_{11} & B_{12} \\
B_{21} & B_{22}
\end{bmatrix}
\end{align*}
$$