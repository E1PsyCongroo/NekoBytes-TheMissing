#include "state.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "snake_utils.h"
/* test vscode git*/
/* Helper function definitions */
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
  game_state_t * state = (game_state_t*)malloc(sizeof(game_state_t));
  state->snakes = (snake_t*)malloc(sizeof(snake_t));
  state->board = (char**)malloc(18 * sizeof(char*));
  for (int i = 0;i < 18;i++)
  {
    (state->board)[i] = (char*)malloc(21 * sizeof(char));
  }
  strcpy((state->board)[0], "####################");
  strcpy((state->board)[17], "####################");
  for (int i = 1;i < 17;i++)
  {
    strcpy((state->board)[i],"#                  #");
  }
  strcpy((state->board)[2], "# d>D    *         #");
  state->num_rows = 18;
  state->num_snakes = 1;
  state->snakes->head_row = 2;
  state->snakes->head_col = 4;
  state->snakes->tail_row = 2;
  state->snakes->tail_col = 2;
  state->snakes->live = true;
  return state;
}

/* Task 2 */
void free_state(game_state_t* state) {
  free(state->snakes);
  state->snakes = NULL;
  for(int i = 0;i < state->num_rows;i++)
  {
    free((state->board)[i]);
    (state->board)[i] = NULL;
  }
  free(state->board);
  state->board = NULL;
  free(state);
  state = NULL;
  return;
}

/* Task 3 */
void print_board(game_state_t* state, FILE* fp) {
  for (int i = 0;i < state->num_rows;i++)
  {
    fprintf(fp, "%s\n", state->board[i]);
  }
  return;
}

/*
  Saves the current state into filename. Does not modify the state object.
  (already implemented for you).
*/
void save_board(game_state_t* state, char* filename) {
  FILE* f = fopen(filename, "w");
  print_board(state, f);
  fclose(f);
}

/* Task 4.1 */

/*
  Helper function to get a character from the board
  (already implemented for you).
*/
char get_board_at(game_state_t* state, unsigned int row, unsigned int col) {
  return state->board[row][col];
}

/*
  Helper function to set a character on the board
  (already implemented for you).
*/
static void set_board_at(game_state_t* state, unsigned int row, unsigned int col, char ch) {
  state->board[row][col] = ch;
}

/*
  Returns true if c is part of the snake's tail.
  The snake consists of these characters: "wasd"
  Returns false otherwise.
*/
static bool is_tail(char c) {
  char tail[5] = "wasd";
  for (int i = 0;i < 4;i++)
  {
    if (c == tail[i])
    {
      return true;
    } 
  }
  return false;
}

/*
  Returns true if c is part of the snake's head.
  The snake consists of these characters: "WASDx"
  Returns false otherwise.
*/
static bool is_head(char c) {
  char head[6] = "WASDx";
  for (int i = 0;i < 5;i++)
  {
    if (c == head[i])
    {
      return true;
    } 
  }
  return false;
}

/*
  Returns true if c is part of the snake.
  The snake consists of these characters: "wasd^<v>WASDx"
*/
static bool is_snake(char c) {
  char snake[14] = "wasd^<v>WASDx";
  for (int i = 0;i < 13;i++)
  {
    if (c == snake[i])
    {
      return true;
    } 
  }
  return false;
}

/*
  Converts a character in the snake's body ("^<v>")
  to the matching character representing the snake's
  tail ("wasd").
*/
static char body_to_tail(char c) {
  switch (c)
  {
  case '^':
    return 'w';
  case '<':
    return 'a';
  case 'v':
    return 's';
  case '>':
    return 'd';
  default:
    return '?';
  }
}

/*
  Converts a character in the snake's head ("WASD")
  to the matching character representing the snake's
  body ("^<v>").
*/
static char head_to_body(char c) {
  switch (c)
  {
  case 'W':
    return '^';
  case 'A':
    return '<';
  case 'S':
    return 'v';
  case 'D':
    return '>';
  default:
    return '?';
  }
}

/*
  Returns cur_row + 1 if c is 'v' or 's' or 'S'.
  Returns cur_row - 1 if c is '^' or 'w' or 'W'.
  Returns cur_row otherwise.
*/
static unsigned int get_next_row(unsigned int cur_row, char c) {
  if (c == 'v' || c == 's' || c == 'S')
  {
    return cur_row + 1;
  }
  else if (c == '^' || c == 'w' || c == 'W')
  {
    return cur_row - 1;
  }
  return cur_row;
}

/*
  Returns cur_col + 1 if c is '>' or 'd' or 'D'.
  Returns cur_col - 1 if c is '<' or 'a' or 'A'.
  Returns cur_col otherwise.
*/
static unsigned int get_next_col(unsigned int cur_col, char c) {
  if (c == '>' || c == 'd' || c == 'D')
  {
    return cur_col + 1;
  }
  else if ( c == '<' || c == 'a' || c == 'A')
  {
    return cur_col - 1;
  }
  return cur_col;
}

/*
  Task 4.2
  Helper function for update_state. Return the character in the cell the snake is moving into.

  This function should not modify anything.
*/
static char next_square(game_state_t* state, unsigned int snum) {
  unsigned int head_row = state->snakes[snum].head_row;
  unsigned int head_col = state->snakes[snum].head_col;
  char head = get_board_at(state, head_row, head_col);
  unsigned int next_head_row = get_next_row(head_row, head);
  unsigned int next_head_col = get_next_col(head_col, head);
  return get_board_at(state, next_head_row, next_head_col);
}

/*
  Task 4.3
  Helper function for update_state. Update the head...

  ...on the board: add a character where the snake is moving

  ...in the snake struct: update the row and col of the head

  Note that this function ignores food, walls, and snake bodies when moving the head.
*/
static void update_head(game_state_t* state, unsigned int snum) {
  unsigned int head_row = state->snakes[snum].head_row;
  unsigned int head_col = state->snakes[snum].head_col;
  char head = get_board_at(state, head_row, head_col);
  unsigned int next_head_row = get_next_row(head_row, head);
  unsigned int next_head_col = get_next_col(head_col, head);
  state->snakes[snum].head_row = next_head_row;
  state->snakes[snum].head_col = next_head_col;
  set_board_at(state, next_head_row, next_head_col, head); //更新头部
  set_board_at(state, head_row, head_col, head_to_body(head)); //更新原头部位置
  return;
}

/*
  Task 4.4

  Helper function for update_state. Update the tail...

  ...on the board: blank out the current tail, and change the new
  tail from a body character (^<v>) into a tail character (wasd)

  ...in the snake struct: update the row and col of the tail
*/
static void update_tail(game_state_t* state, unsigned int snum) {
  unsigned int tail_row = state->snakes[snum].tail_row;
  unsigned int tail_col = state->snakes[snum].tail_col;
  char tail = get_board_at(state, tail_row, tail_col);
  unsigned int next_tail_row = get_next_row(tail_row, tail);
  unsigned int next_tail_col = get_next_col(tail_col, tail);
  state->snakes[snum].tail_row = next_tail_row;
  state->snakes[snum].tail_col = next_tail_col;
  set_board_at(state, next_tail_row, next_tail_col, body_to_tail(get_board_at(state, next_tail_row, next_tail_col))); //更新尾部坐标
  set_board_at(state, tail_row, tail_col, ' '); //更新原尾部内容
  return;
}

/* Task 4.5 */
void update_state(game_state_t* state, int (*add_food)(game_state_t* state)) {
  for (unsigned int i = 0;i < state->num_snakes;i++)
  {
    if (state->snakes[i].live)
    {
      char next_pos = next_square(state, i);
      if (is_snake(next_pos) || next_pos == '#') // 死亡
      {
        state->snakes[i].live = false;
        set_board_at(state, state->snakes[i].head_row, state->snakes[i].head_col, 'x');
        continue;
      }
      else if (next_pos == '*')
      {
        update_head(state, i);
        add_food(state);
        continue;
      }
      update_head(state,i);
      update_tail(state,i);
    }
  }
  return;
}

/* Task 5 */
game_state_t* load_board(FILE* fp) {
  game_state_t* state = (game_state_t*)malloc(sizeof(game_state_t));
  state->snakes = NULL;
  state->num_snakes = 0;
  state->num_rows = 0;
  char buff[120000];// 中途缓存
  while (fgets(buff, 120000, fp)) 
  {
    state->board = (char**)realloc(state->board, sizeof(char*) * (state->num_rows + 1));
    state->board[state->num_rows] = (char*)malloc(sizeof(char) * (strlen(buff) + 1));
    strcpy(state->board[state->num_rows], buff);
    state->board[state->num_rows][strlen(buff) - 1] = '\0'; //去除\n
    state->num_rows++;
  }
  return state;
}
/*
  Task 6.1

  Helper function for initialize_snakes.
  Given a snake struct with the tail row and col filled in,
  trace through the board to find the head row and col, and
  fill in the head row and col in the struct.
*/
static void find_head(game_state_t* state, unsigned int snum) {
  unsigned int now_col = state->snakes[snum].tail_col;
  unsigned int now_row = state->snakes[snum].tail_row;
  char now = get_board_at(state, now_row, now_col);
  while(!is_head(now))
  {
    now_col = get_next_col(now_col, now);
    now_row = get_next_row(now_row, now);
    now = get_board_at(state, now_row, now_col);
  }
  state->snakes[snum].head_col = now_col;
  state->snakes[snum].head_row = now_row;
  return;
}

/* Task 6.2 */
game_state_t* initialize_snakes(game_state_t* state) {
  for (unsigned int i = 0;i < state->num_rows;i++)
  {
    for (unsigned int j = 0;j < strlen(state->board[i]);j++)
    {
      if (is_tail(get_board_at(state, i, j)))
      {
        state->snakes = (snake_t*)realloc(state->snakes, sizeof(snake_t) * (state->num_snakes + 1));
        state->snakes[state->num_snakes].live = true;
        state->snakes[state->num_snakes].tail_row = i;
        state->snakes[state->num_snakes].tail_col = j;
        find_head(state, state->num_snakes);
        state->num_snakes++;
      }
    }
  }
  return state;
}
