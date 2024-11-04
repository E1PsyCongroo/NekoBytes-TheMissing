#include <stdint.h>
#include <stdio.h>

extern int mm_init(void);
extern void *mm_malloc(size_t size);
extern void mm_free(void *ptr);
extern void *mm_realloc(void *ptr, size_t size);

/*块结构体*/
struct Block {
  // 指向前一个块的指针，没有则为NULL
  struct Block *pre;
  // 指向后一个块的指针，没有则为NULL
  struct Block *nxt;
  // 块所对应的堆空间起始地址
  void *ptr;
  // 块所占堆空间大小
  size_t size;
  // 0:块不处于占用状态 1:块处于占用状态
  int empty;
};
typedef struct Block block;
// 头指针，指向链表中第一个块
extern block *head;
// 尾指针，指向链表中最后一个块
extern block *tail;

extern void block_init(block *bk);

extern block *find_fit(size_t size);
extern block *extend_heap(size_t words);
extern block *coalesce(block *bk);
extern block *find_by_ptr(void *ptr);
extern void *place(block *bk, size_t size);
extern void print_all();
