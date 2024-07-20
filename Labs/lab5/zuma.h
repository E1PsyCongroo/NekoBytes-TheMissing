#include <stdio.h>
#include <stdlib.h>

/*
链表节点结构体
前继节点指针pre
后继节点指针nxt
珠子颜色color
珠子价值val
*/
struct Zuma {
  struct Zuma *pre, *nxt;
  int color, val;
};
typedef struct Zuma zuma;

/*
链表头head
链表尾tail
*/
extern zuma *head, *tail;
/*
链表总长len
最终得分ans
当次操作消除轮数K
*/
extern int len, ans, K;

/*
以node节点为中心，向左右方向延伸尝试消除与node同颜色珠子
*/
void match(zuma *node);
/*
在node节点后插入新节点new_node
*/
void insert(zuma *node, zuma *new_node);
/*
在第k个珠子后插入颜色为color，价值为val的珠子
若k为0则表示当前局面为空，当前插入的珠子为第一颗珠子
*/
void Insert(int k, int color, int val);
/*
删除链表节点node并释放空间
*/
void delete(zuma *node);
/*
放逐第k个珠子
*/
void Delete(int k);
/*
将头部珠子移动到尾部
*/
void move_back();
/*
将第k个珠子置顶
*/
void set_top(int k);
/*
处理初始局面输入
*/
void init();
/*
处理每一轮的操作
*/
void solve();
/*
调试使用，从头到尾按顺序输出当前链表节点状态
*/
void print_all();