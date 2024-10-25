#include "2048.h"
#include <assert.h>  //for assert
#include <stdbool.h> // for bool
#include <stdio.h>
#include <stdlib.h>
#include <termios.h> // for tcsetattr
#include <time.h>    // for time
#include <unistd.h>  // for STDOUT_FILENO

int board[BOARD_SIZE][BOARD_SIZE];

void run_game(void) {
  srand(time(0));
  initialize_board();
  generate_number();
  print_board();
  enum Direction direction;
  bool generate_flag = true;
  do {
    if (generate_flag) {
      generate_number();
    }
    print_board();
    while ((direction = choose_direction()) == NONE) {
      continue;
    }
    switch (direction) {
    case UP:
      generate_flag = move_and_merge_up();
      break;
    case DOWN:
      generate_flag = move_and_merge_down();
      break;
    case LEFT:
      generate_flag = move_and_merge_left();
      break;
    case RIGHT:
      generate_flag = move_and_merge_right();
      break;
    default:
      assert(0);
    }
  } while (!is_finished());
}

bool is_finished(void) {
  bool flag_no_space = true;
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      if (board[i][j] == 2048) {
        return true;
      }
      if (board[i][j] == 0) {
        flag_no_space = false;
      }
    }
  }
  return flag_no_space;
}

void initialize_board(void) {
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      board[i][j] = 0;
    }
  }
}

void generate_number(void) {
  int empty_space[BOARD_SIZE * BOARD_SIZE][2];
  int count = 0;

  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      if (board[i][j] == 0) {
        empty_space[count][0] = i;
        empty_space[count][1] = j;
        count++;
      }
    }
  }

  if (count > 0) {
    int index = rand() % count;
    int x = empty_space[index][0];
    int y = empty_space[index][1];
    board[x][y] = (rand() % 2 + 1) * 2;
  }
}

enum Direction choose_direction(void) {
  char dir = getchar();
  switch (dir) {
  case 'A':
  case 'a':
    return LEFT;
  case 'W':
  case 'w':
    return UP;
  case 'S':
  case 's':
    return DOWN;
  case 'D':
  case 'd':
    return RIGHT;
  default:
    return NONE;
  }
}

void print_board(void) {
  system("clear");
  printf("-------------------------\n");
  for (int i = 0; i < BOARD_SIZE; i++) {
    putchar('|');
    for (int j = 0; j < BOARD_SIZE; j++) {
      if (board[i][j] != 0) {
        printf("%5d|", board[i][j]);
      } else {
        printf("     |");
      }
    }
    putchar('\n');
  }
  printf("-------------------------\n");
}

void swap(int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

bool move_and_merge_left(void) {
  bool moved_flag = false;
  for (int row = 0; row < BOARD_SIZE; row++) {
    for (int col = 0; col < BOARD_SIZE - 1; col++) {
      if (board[row][col] == 0) {
        for (int search_col = col + 1; search_col < BOARD_SIZE; search_col++) {
          if (board[row][search_col] != 0) {
            moved_flag = true;
            swap(&board[row][col], &board[row][search_col]);
            break;
          }
        }
      }
      int next_not_zero_col = col + 1;
      while (board[row][next_not_zero_col] == 0 &&
             next_not_zero_col < BOARD_SIZE)
        next_not_zero_col++;
      if (next_not_zero_col < BOARD_SIZE &&
          board[row][col] == board[row][next_not_zero_col]) {
        moved_flag = true;
        board[row][col] *= 2;
        board[row][next_not_zero_col] = 0;
      }
    }
  }
  return moved_flag;
}

bool move_and_merge_right(void) {
  bool moved_flag = false;
  for (int row = 0; row < BOARD_SIZE; row++) {
    for (int col = BOARD_SIZE - 1; col > 0; col--) {
      if (board[row][col] == 0) {
        for (int search_col = col - 1; search_col >= 0; search_col--) {
          if (board[row][search_col] != 0) {
            moved_flag = true;
            swap(&board[row][col], &board[row][search_col]);
            break;
          }
        }
      }
      int next_not_zero_col = col - 1;
      while (board[row][next_not_zero_col] == 0 && next_not_zero_col >= 0)
        next_not_zero_col--;
      if (next_not_zero_col >= 0 &&
          board[row][col] == board[row][next_not_zero_col]) {
        moved_flag = true;
        board[row][col] *= 2;
        board[row][next_not_zero_col] = 0;
      }
    }
  }
  return moved_flag;
}

bool move_and_merge_up(void) {
  bool moved_flag = false;
  for (int col = 0; col < BOARD_SIZE; col++) {
    for (int row = 0; row < BOARD_SIZE - 1; row++) {
      if (board[row][col] == 0) {
        for (int search_row = row + 1; search_row < BOARD_SIZE; search_row++) {
          if (board[search_row][col] != 0) {
            moved_flag = true;
            swap(&board[row][col], &board[search_row][col]);
            break;
          }
        }
      }
      int next_not_zero_row = row + 1;
      while (board[next_not_zero_row][col] == 0 &&
             next_not_zero_row < BOARD_SIZE)
        next_not_zero_row++;
      if (next_not_zero_row < BOARD_SIZE &&
          board[row][col] == board[next_not_zero_row][col]) {
        moved_flag = true;
        board[row][col] *= 2;
        board[next_not_zero_row][col] = 0;
      }
    }
  }
  return moved_flag;
}

bool move_and_merge_down(void) {
  bool moved_flag = false;
  for (int col = 0; col < BOARD_SIZE; col++) {
    for (int row = BOARD_SIZE - 1; row > 0; row--) {
      if (board[row][col] == 0) {
        for (int search_row = row - 1; search_row >= 0; search_row--) {
          if (board[search_row][col] != 0) {
            moved_flag = true;
            swap(&board[row][col], &board[search_row][col]);
            break;
          }
        }
      }
      int next_not_zero_row = row - 1;
      while (board[next_not_zero_row][col] == 0 && next_not_zero_row >= 0)
        next_not_zero_row--;
      if (next_not_zero_row >= 0 &&
          board[row][col] == board[next_not_zero_row][col]) {
        moved_flag = true;
        board[row][col] *= 2;
        board[next_not_zero_row][col] = 0;
      }
    }
  }
  return moved_flag;
}

/* 禁用终端缓存区和回显 */
void disable_buffering(struct termios *old_attr) {
  struct termios new_attr;
  tcgetattr(STDIN_FILENO, old_attr);
  new_attr = *old_attr;
  new_attr.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &new_attr);
}

/* 恢复终端 */
void restore_buffering(struct termios *old_attr) {
  tcsetattr(STDIN_FILENO, TCSANOW, old_attr);
}

int main(void) {
  struct termios old_attr;
  disable_buffering(&old_attr);
  run_game();
  restore_buffering(&old_attr);
  printf("Game End...\n");
  return 0;
}
