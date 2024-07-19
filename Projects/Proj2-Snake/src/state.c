#include "state.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "snake_utils.h"

/* 辅助函数定义 */
static void set_board_at(game_state_t* state, unsigned int row, unsigned int col, char ch);
static bool is_tail(char c);
static bool is_head(char c);
static bool is_snake(char c);
static char body_to_tail(char c);
static char head_to_body(char c);
static unsigned int get_next_row(unsigned int cur_row, char c);
static unsigned int get_next_col(unsigned int cur_col, char c);
static void find_head(game_state_t* state, unsigned int snum);
static char next_square(game_state_t* state, unsigned int snum);
static void update_tail(game_state_t* state, unsigned int snum);
static void update_head(game_state_t* state, unsigned int snum);

/* Task 1 */
game_state_t* create_default_state() {
  // TODO: 完成这个函数
  return NULL;
}

/* Task 2 */
void free_state(game_state_t* state) {
  // TODO: 完成这个函数
  return;
}

/* Task 3 */
void print_board(game_state_t* state, FILE* fp) {
  // TODO: 完成这个函数
  return;
}

/*
  保存现在的state到filename中
  请不要修改state(已经帮你实现了)
*/
void save_board(game_state_t* state, char* filename) {
  FILE* f = fopen(filename, "w");
  print_board(state, f);
  fclose(f);
}

/* Task 4.1 */

/*
  从游戏板中获得一个字符的辅助函数(已经实现)
*/
char get_board_at(game_state_t* state, unsigned int row, unsigned int col) {
  return state->board[row][col];
}

/*
  从游戏板中设置一个字符的辅助函数(已经实现)
*/
static void set_board_at(game_state_t* state, unsigned int row, unsigned int col, char ch) {
  state->board[row][col] = ch;
}

/*

  如果 c 是蛇尾的一部分，则返回 true,否则返回 false。
  注意：蛇的尾巴由以下字符组成：“wasd”
*/
static bool is_tail(char c) {
  // TODO: 完成这个函数
  return true;
}

/*
  如果 c 是蛇头的一部分，则返回 true,否则返回 false。
  注意：蛇由以下字符组成：“WASDx”
*/
static bool is_head(char c) {
  // TODO: 完成这个函数
  return true;
}

/*
  如果 c 是蛇的一部分，则返回 true,否则返回 false。
  注意：蛇由以下字符组成：“wasd^<v>WASDx”
*/
static bool is_snake(char c) {
  // TODO: 完成这个函数
  return true;
}

/*
  将蛇身中的字符 ("^<v>") 转换为相应的蛇尾字符 ("wasd")。
*/
static char body_to_tail(char c) {
  // TODO: 完成这个函数
  return '?';
}

/*
  将蛇头中的字符（“WASD”）转换为相应的蛇身字符（“^<v>”）。
*/
static char head_to_body(char c) {
  // TODO: 完成这个函数
  return '?';
}

/*
  如果 c 为 'v' 或 's' 或 'S'，则返回 cur_row + 1。
  如果 c 为 '^' 或 'w' 或 'W'，则返回 cur_row - 1。
  否则，返回 cur_row。 
*/
static unsigned int get_next_row(unsigned int cur_row, char c) {
  // TODO: 完成这个函数
  return cur_row;
}

/*
  如果 c 为 '>' 或 'd' 或 'D'，则返回 cur_col + 1。
  如果 c 为 '<' 或 'a' 或 'A'，则返回 cur_col - 1。
  否则，返回 cur_col。
*/
static unsigned int get_next_col(unsigned int cur_col, char c) {
  // TODO: 完成这个函数
  return cur_col;
}

/*
  Task 4.2

  update_state的辅助函数。
  返回snake即将进入的下一个格子的字符。
  这个函数不应该改变任何东西。

*/
static char next_square(game_state_t* state, unsigned int snum) {
  // TODO: 完成这个函数
  return '?';
}

/*
  Task 4.3

  update_state的辅助函数。用于更新head

  在游戏板上: 在snake即将进入的位置添加一个字符

  在结构体snake中： 更新head的行与列

  注意这个函数在移动头部时忽略了食物，墙以及蛇身。
*/
static void update_head(game_state_t* state, unsigned int snum) {
  // TODO: 完成这个函数
  return;
}

/*
  Task 4.4

  update_state的辅助函数。用于更新tail

  在游戏板上: 删除当前尾部，并将新尾部从蛇身字符 (^<v>) 更改为尾部字符 (wasd)

  在结构体snake中： 更新tail的行与列
*/
static void update_tail(game_state_t* state, unsigned int snum) {
  // TODO: 完成这个函数
  return;
}

/* Task 4.5 */
void update_state(game_state_t* state, int (*add_food)(game_state_t* state)) {
  // TODO: 完成这个函数
  return;
}

/* Task 5 */
game_state_t* load_board(FILE* fp) {
  // TODO: 完成这个函数
  return NULL;
}

/*
  Task 6.1

  initialize_snakes的辅助函数
  给定一个snake结构体，其中尾行和列已知，
  追踪棋盘以找到蛇头的行和列，
  并在结构体中填入蛇头的行和列。
*/
static void find_head(game_state_t* state, unsigned int snum) {
  // TODO: 完成这个函数
  return;
}

/* Task 6.2 */
game_state_t* initialize_snakes(game_state_t* state) {
  // TODO: 完成这个函数
  return NULL;
}
