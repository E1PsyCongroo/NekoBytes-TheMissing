# Lab3_1 C语言基本语法
- 完成lab3_1中的四个.c文件
  - 本lab每个.c文件中都有相应的说明，足够完成填空没有相应solution，自行判断对错，请根据说明完成填空。

# Lab3_2 递归

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

    0 6 0 0 0 0 0 7 1  
    7 0 5 4 0 3 0 0 0  
    0 0 0 6 7 0 3 0 0  
    0 3 7 2 4 1 8 6 0  
    0 0 0 0 0 5 1 9 0  
    1 5 8 7 9 0 2 3 0  
    6 0 1 0 2 0 0 0 3  
    0 7 9 0 0 0 5 0 2  
    0 0 0 0 0 4 7 0 0      
    提供了`printBoard(int board[N][N])`函数打印数独和`isSafe(int board[N][N], int row, int col, int num)`函数检查数字是否可以放在board[row][col]位置。
   - 运行judge.sh检测程序正确性。
- 完成文件`sudoku.c`中的`solveSudoku`函数编写。