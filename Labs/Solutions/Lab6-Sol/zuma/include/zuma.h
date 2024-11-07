#ifndef __ZUMA_H__
#define __ZUMA_H__

#include <stdio.h>
#include <stdlib.h>

struct Zuma {
  struct Zuma *pre, *nxt;
  int color, val;
};
typedef struct Zuma zuma;

extern zuma *head, *tail;
extern int len, ans, K;

void match(zuma *node);
void Insert(int k, int color, int val);
void Delete(int k);
void move_back();
void set_top(int k);
void init();
void solve();
void print_all();

#endif
