#ifndef _SNK_SNAKE_UTILS_H
#define _SNK_SNAKE_UTILS_H

#include <stdint.h>
#include "state.h"

/* 为交互模式定义按键 */
#define KEY_MOVEUP 0x77
#define KEY_MOVERIGHT 0x64
#define KEY_MOVEDOWN 0x73
#define KEY_MOVELEFT 0x61
#define KEY_QUIT 0x71

/* 一个简单的确定性随机函数，你可以通过搜索LFSR来进一步了解 */
unsigned int det_rand(unsigned int* state);

/* 确定性地在棋盘上生成食物。 */
int deterministic_food(game_state_t* state);

/* 在地图的左上角生成食物。 */
int corner_food(game_state_t* state);

/* 改变由玩家操作的蛇的方向 */
void redirect_snake(game_state_t* state, char input_direction);

/* 使被选中的蛇随机左转或右转 */
void random_turn(game_state_t* state, int snum);

#endif
