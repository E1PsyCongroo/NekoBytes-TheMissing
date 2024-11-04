/*
 * mm-naive.c - The fastest, least memory-efficient malloc package.
 *
 * In this naive approach, a block is allocated by simply incrementing
 * the brk pointer.  A block is pure payload. There are no headers or
 * footers.  Blocks are never coalesced or reused. Realloc is
 * implemented directly using mm_malloc and mm_free.
 *
 * NOTE TO STUDENTS: Replace this header comment with your own header
 * comment that gives a high level description of your solution.
 */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "memlib.h"
#include "mm.h"

block *head = NULL, *tail = NULL;

// #define ENABLE_DEBUG

/* 块对齐要求量 */
#define ALIGNMENT 8

/* 宏:将当前地址自动向上对齐 */
#define ALIGN(size) (((size) + (ALIGNMENT - 1)) & ~0x7)
/*
测试前将调用该函数
你可以在该函数中执行一些操作
返回值为0表示正常初始化
*/
int mm_init(void) {
  head = NULL;
  tail = NULL;
  return 0;
}

/*
传入申请空间大小size
返回指向符合需求的空间的void*类型指针
*/
void *mm_malloc(size_t size) { return NULL; }

/*
传入需要释放的空间的起始地址，不需要返回值
通过该函数的传入信息用你的方式维护你的结构体链表
*/
void mm_free(void *ptr) { return; }

/*
传入原数据所在空间地址void* ptr、新的空间区域大小size
1. 如果ptr为NULL，此调用等价于mm_malloc(size)
2. 如果size为0，此调用等价于mm_free(ptr)
3.
否则，为其重新分配一片空间并继承原数据,若新空间大小小于原空间大小，则继承靠前的数据（**警惕数据污染**）
*/
void *mm_realloc(void *ptr, size_t size) { return NULL; }

/*
传入指向需要初始化的块结构体的指针
初始化该块结构体
*/
extern void block_init(block *bk) {
  bk->pre = NULL;
  bk->nxt = NULL;
  bk->ptr = NULL;
  bk->size = 0;
  bk->empty = 1;
}

/*
你可以在需要的地方调用该函数进行调试输出
关于ifdef与endif的用法，请查阅：https://zh.cppreference.com/w/c/preprocessor/conditional
你可以将本文件开头的"#define ENABLE_DEBUG"取消注释来启用显示为虚色的代码
（如果你用的是VSCODE视觉效果应当是虚色代码表示未启用代码）
*/
void print_all() {
#ifdef ENABLE_DEBUG
  block *bk = head;
  printf("BEGIN\n");
  printf("head:[%p] tail:[%p]\n", head == NULL ? head : head->ptr,
         tail == NULL ? tail : tail->ptr);
  while (bk != NULL) {
    printf("ptr:[%p] size:[%lu] empty:[%d]\n", bk->ptr, bk->size, bk->empty);
    bk = bk->nxt;
  }
  printf("END\n");
#endif
  return;
}

/*
以下函数为可选实现
实现以下函数后，在上文简单调用函数并做一些操作便可完成该项目
并且使你的代码可读性更好
强烈推荐优先实现以下函数
*/

/*
传入需分配的空间的大小size
顺序遍历当前链表
当找到满足要求的块时返回指向该块的指针
否则返回空指针
*/
block *find_fit(size_t size) { return NULL; }

/*
传入指向堆空间地址的指针ptr
顺序遍历链表
返回指向该地址的块（维护该空间地址信息的块）的指针
*/

block *find_by_ptr(void *ptr) { return NULL; }

/*
传入空闲块指针bk，传入分配空间大小size
将空闲块指针bk靠前的size份空间标记为已分配
修改原空闲块的信息
为新的占用块分配块结构体进行维护
维护链表的前驱后继
返回分配空间的起始地址
*/
void *place(block *bk, size_t size) { return NULL; }

/*
传入空闲块指针bk
将该空闲块与相邻的空闲块合并
返回指向合并后的块的指针
*/
block *coalesce(block *bk) { return NULL; }

/*
传入需要向堆空间申请的空间大小size
将申请得到的空间用block结构体并接入链表尾部
*/
block *extend_heap(size_t size) { return NULL; }
