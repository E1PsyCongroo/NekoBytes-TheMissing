# Lab2 C 语言基本语法

## Lab2_1 C 语言基本语法

- 完成lab2_1中的四个.c文件
  - 请根据每个ex_中的TODO完成内容。
  - 你可以使用 make 自动编译可执行文件

    ```bash
    make # 编译所有可执行文件
    make ex1_ptr # 仅编译 ex1_ptr.c
    ./ex1_ptr # 运行 ex1_ptr
    make clean # 删除可执行文件
    ```

## Lab2_2 字符串和循环

- 本实验使用了参数char *argv[]，请在编译后尝试向程序输入命令行参数，如:

  ```bash
  make
  ./str_and_cyc California Oregon Washington Texas
  ```

  输出内容，如下所示:

  ```bash
  for:
  arg 1: California
  arg 2: Oregon
  arg 3: Washington
  arg 4: Texas

  state 0: California
  state 1: Oregon
  state 2: Washington
  state 3: Texas

  while:
  arg 0: ./str_and_cyc
  arg 1: California
  arg 2: Oregon
  arg 3: Washington
  arg 4: Texas

  state 0: California
  state 1: Oregon
  state 2: Washington
  state 3: Texas
  ```

- 请对srt_and_cyc.c文件中的for和while循环尝试以下操作并查看结果。
- for循环
  - 将i初始化为0看看会发生什么。是否也需要改动argc，不改动的话它能正常工作吗？为什么下标从0开始可以正常工作？
  - 将num_states改为错误的值(使它变大)，来看看会发生什么。
  - RTFM: NULL是什么东西，尝试将它用做states的一个元素，看看它会打印出什么。
  - 看看你是否能在打印之前将states的一个元素赋值给argv中的元素，再试试相反的操作。
- while循环
  - 使用while循环将argv中的值复制到states。
  - 让这个复制循环不会执行失败，即使argv之中有很多元素也不会全部放进states。
  - 研究你是否真正复制了这些字符串。答案可能会让你感到意外和困惑。

## 递归(可选，难度较大)

- 经典递归例子

  ```C
  #include <stdio.h>
  int fibonacci(int n) {
      if (n < 1) {
          return -1;
      }
      if (n == 1 || n == 2) {
          return 1;
      }
      else {
          return fibonacci(n - 1) + fibonacci(n - 2);
      }
  }

  int main(void)
  {
      int a;
      while (scanf("%d", &a) != EOF) {
          printf("Fibonacci数列第%d项为:%d\n", a, fibonacci(a));
      }
      return 0;
  }
  ```

- 理解递归的重要方式
  - Base Case：递归主体以一个基本情况开始，通常它是这个条件语句，定义了函数对最简单的输入的行为，并通常被用作递归结束的出口。
  - Recursive Calls：在Base Case之后，是一个或多个递归调用。递归调用总是有一个特点：它们简化了原来的问题。
  - 数学归纳法理解：
    1. 验证递归函数`F(X)`取Base Case时成立.
    2. 假设X = n时成立，那么可以推导出在X = n+1时递归函数`F(X)`做出正确的行为。
    3. 最后一步总结表述。

- 数独

  - 数独（Sudoku）是一种经典的逻辑数字游戏，通常由一个9x9的网格组成，这个网格被进一步划分为9个3x3的小方块。游戏的目标是通过填充数字1到9，使得每一行、每一列和每一个3x3的小方块都包含数字1到9，且数字不能重复。

  - 实现一个递归函数`bool solveSudoku(int board[N][N], int row, int col)`判断数独是否可解，有解则填充正确答案。

  - 题中数独采用二维数组，需解答填充的数字用0代替如：

    ```txt
    0 6 0 0 0 0 0 7 1
    7 0 5 4 0 3 0 0 0
    0 0 0 6 7 0 3 0 0
    0 3 7 2 4 1 8 6 0
    0 0 0 0 0 5 1 9 0
    1 5 8 7 9 0 2 3 0
    6 0 1 0 2 0 0 0 3
    0 7 9 0 0 0 5 0 2
    0 0 0 0 0 4 7 0 0
    ```

  - 使用`printBoard(int board[N][N])`函数打印数独
  - 使用`isSafe(int board[N][N], int row, int col, int num)`函数检查数字是否可以放在board[row][col]位置。
  - 运行judge.sh检测程序正确性。
- 完成文件`sudoku.c`中的`solveSudoku`函数编写。
