#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define N 9

// 打印数独
void printBoard(int board[N][N]) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      printf("%d ", board[i][j]);
    }
    printf("\n");
  }
}

// 检查数字是否可以放在 board[row][col] 位置
bool isSafe(int board[N][N], int row, int col, int num) {
  // 检查行
  for (int x = 0; x < N; x++) {
    if (board[row][x] == num) {
      return false;
    }
  }

  // 检查列
  for (int x = 0; x < N; x++) {
    if (board[x][col] == num) {
      return false;
    }
  }

  // 检查 3x3 子矩阵
  int startRow = row - row % 3;
  int startCol = col - col % 3;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (board[i + startRow][j + startCol] == num) {
        return false;
      }
    }
  }

  return true;
}

// 递归解数独
// Note: row表示行 col表示列
bool solveSudoku(int board[N][N], int row, int col) {
  // 如果到达最后一行，数独已解完
  if (_____) {
    return true;
  }

  // 如果到达最后一列，移动到下一行
  if (_____) {
    row++;
    col = 0;
  }

  // 如果当前单元格已填充，递归到下一个单元格
  // Note: 0表示单元格未填充
  if (_____) {
    return solveSudoku(board, row, col + 1);
  }

  // 尝试填充数字 1 到 9
  for (int num = 1; num <= N; num++) {
    if (_____) {
      board[row][col] = num;
      if (_____) {
        return true;
      }
      // 如果填充失败，回溯
      board[row][col] = 0;
    }
  }

  return false;
}

// 从文件读取数独棋盘
void readBoardFromFile(const char *filename, int board[N][N]) {
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    perror("Unable to open file");
    return;
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      fscanf(file, "%d", &board[i][j]);
    }
  }

  fclose(file);
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <input_file>\n", argv[0]);
    return EXIT_FAILURE;
  }

  int board[N][N];

  // 从文件读取棋盘数据
  readBoardFromFile(argv[1], board);

  // 解决数独并打印结果
  if (solveSudoku(board, 0, 0)) {
    printBoard(board);
  } else {
    printf("No solution exists.\n");
  }

  return EXIT_SUCCESS;
}
