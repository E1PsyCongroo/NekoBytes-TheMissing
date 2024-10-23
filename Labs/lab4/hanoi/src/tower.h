#include <stdio.h>
#include <stdlib.h>
#include <string.h>
extern int tower[3][20];
extern int top[3];
extern int tower_size, move_cnt, enable_debug;
/*将大小为plate的盘子从from柱移动到to柱*/
void tower_move(int plate, char from, char to);
void tower_init(int siz);
void tower_check();
void tower_print_all();
void tower_set_debug();