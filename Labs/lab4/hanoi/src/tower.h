#include <stdio.h>
#include <stdlib.h>
#include <string.h>
extern int tower[3][20];
extern int top[3];
extern int tower_size, move_cnt;
void move(int id, char from, char to);
void tower_init(int siz);
void tower_check();
void tower_print_all();