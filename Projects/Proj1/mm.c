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

/*********************************************************
 * NOTE TO STUDENTS: Before you do anything else, please
 * provide your team information in the following struct.
 ********************************************************/
team_t team = {
    /* Team name */
    "_",
    /* First member's full name */
    "_",
    /* First member's email address */
    "_",
    /* Second member's full name (leave blank if none) */
    "",
    /* Second member's email address (leave blank if none) */
    ""};
block *head = NULL, *tail = NULL;

// #define ENABLE_DEBUG

/* single word (4) or double word (8) alignment */
#define ALIGNMENT 8

/* rounds up to the nearest multiple of ALIGNMENT */
#define ALIGN(size) (((size) + (ALIGNMENT - 1)) & ~0x7)
/*
 * mm_init - initialize the malloc package.
 */
int mm_init(void) {
  head = NULL;
  tail = NULL;
  return 0;
}

/*
 * mm_malloc - Allocate a block by incrementing the brk pointer.
 *     Always allocate a block whose size is a multiple of the alignment.
 */
void *mm_malloc(size_t size) {
#ifdef ENABLE_DEBUG
  printf("DEBUG: ENTER mm_malloc with size:[%u]\n", size);
#endif
  size = ALIGN(size);
  block *bk;
  bk = find_fit(size);
  if (bk == NULL) {
    bk = extend_heap(size);
  }
  return place(bk, size);
}

/*
 * mm_free - Freeing a block does nothing.
 */
void mm_free(void *ptr) {
#ifdef ENABLE_DEBUG
  printf("DEBUG: ENTER mm_free with ptr:[%p]\n", ptr);
#endif
  block *bk = find_by_ptr(ptr);
  bk->empty = 1;
  coalesce(bk);
#ifdef ENABLE_DEBUG
  print_all();
#endif
  return;
}

/*
 * mm_realloc - Implemented simply in terms of mm_malloc and mm_free
 */
void *mm_realloc(void *ptr, size_t size) {
  size = ALIGN(size);
  if (size == 0) {
    mm_free(ptr);
    return NULL;
  }
  if (ptr == NULL) {
    return mm_malloc(size);
  }
  block *bk = find_by_ptr(ptr);
  size_t old_size = bk->size;
  void *new_ptr = mm_malloc(size);
  memcpy(new_ptr, ptr, old_size < size ? old_size : size);
  mm_free(ptr);
  return new_ptr;
}

extern void block_init(block *bk) {
  bk->pre = NULL;
  bk->nxt = NULL;
  bk->ptr = NULL;
  bk->size = 0;
  bk->empty = 1;
}

block *find_fit(size_t size) {
  block *bk = head;
  while (bk != NULL) {
    if (bk->empty * bk->size >= size)
      return bk;
    bk = bk->nxt;
  }
  return NULL;
}

block *extend_heap(size_t size) {
#ifdef ENABLE_DEBUG
  printf("DEBUG: ENTER extend_heap with size:[%u]\n", size);
  c
#endif
      void *ptr = mem_sbrk(size);
  block *bk = (block *)malloc(sizeof(block));
  block_init(bk);
  bk->empty = 1;
  bk->size = size;
  bk->ptr = ptr;
  if (head == NULL) {
    head = bk;
    tail = bk;
  } else {
    tail->nxt = bk;
    bk->pre = tail;
    tail = bk;
  }
#ifdef ENABLE_DEBUG
  print_all();
#endif
  return coalesce(bk);
}

block *coalesce(block *bk) {
#ifdef ENABLE_DEBUG
  printf("DEBUG: ENTER coalesce with ptr:[%p]\n", bk->ptr);
#endif
  block *pre_bk = bk->pre, *nxt_bk = bk->nxt;
  int pre_empty = (pre_bk != NULL && pre_bk->empty == 1),
      nxt_empty = (nxt_bk != NULL && nxt_bk->empty == 1);
  /*if (!pre_empty && !nxt_empty) {
    return bk;
  } else if (pre_empty && !nxt_empty) {
    bk->size += pre_bk->size;
    bk->ptr = pre_bk->ptr;
    if (pre_bk->pre != NULL)
      pre_bk->pre->nxt = bk;
    bk->pre = pre_bk->pre;
    free(pre_bk);
    return bk;
  } else if (!pre_empty && nxt_empty) {
    bk->size += nxt_bk->size;
    if (nxt_bk->nxt != NULL)
      nxt_bk->nxt->pre = bk;
    bk->nxt = nxt_bk->nxt;
    free(nxt_bk);
    return bk;
  } else {
    bk->size += pre_bk->size + nxt_bk->size;
    bk->ptr = pre_bk->ptr;
    if (pre_bk->pre != NULL)
      pre_bk->pre->nxt = bk;
    if (nxt_bk->nxt != NULL)
      nxt_bk->nxt->pre = bk;
    bk->pre = pre_bk->pre;
    bk->nxt = nxt_bk->nxt;
    free(pre_bk);
    free(nxt_bk);
    return bk;
  }*/
  if (pre_empty) {
    bk->size += pre_bk->size;
    bk->ptr = pre_bk->ptr;
    if (pre_bk->pre != NULL)
      pre_bk->pre->nxt = bk;
    bk->pre = pre_bk->pre;
    if (pre_bk == head)
      head = bk;
    if (pre_bk == tail)
      tail = bk;
    free(pre_bk);
  }
  if (nxt_empty) {
    bk->size += nxt_bk->size;
    if (nxt_bk->nxt != NULL)
      nxt_bk->nxt->pre = bk;
    bk->nxt = nxt_bk->nxt;
    if (nxt_bk == head)
      head = bk;
    if (nxt_bk == tail)
      tail = bk;
    free(nxt_bk);
  }
#ifdef ENABLE_DEBUG
  print_all();
#endif
  return bk;
}

void *place(block *bk, size_t size) {
  if (size == bk->size) {
    bk->empty = 0;
#ifdef ENABLE_DEBUG
    print_all();
#endif
    return bk->ptr;
  }
  block *new_bk = malloc(sizeof(block));
  block_init(new_bk);
  new_bk->ptr = bk->ptr;
  new_bk->size = size;
  new_bk->empty = 0;
  bk->ptr = (void *)((uintptr_t)(bk->ptr) + size);
  bk->size -= size;
  new_bk->pre = bk->pre;
  new_bk->nxt = bk;
  if (bk->pre != NULL)
    bk->pre->nxt = new_bk;
  bk->pre = new_bk;
  if (bk == head)
    head = new_bk;
#ifdef ENABLE_DEBUG
  print_all();
#endif
  return new_bk->ptr;
}

block *find_by_ptr(void *ptr) {
  block *bk = head;
  while (bk != NULL) {
    if (bk->ptr == ptr) {
      return bk;
    }
    bk = bk->nxt;
  }
#ifdef ENABLE_DEBUG
  printf("ERROR:can't find block by ptr:[%p]!!!", ptr);
#endif
  exit(0);
}

void print_all() {
  block *bk = head;
  printf("BEGIN\n");
  printf("head:[%p] tail:[%p]\n", head == NULL ? head : head->ptr,
         tail == NULL ? tail : tail->ptr);
  while (bk != NULL) {
    printf("ptr:[%p] size:[%u] empty:[%d]\n", bk->ptr, bk->size, bk->empty);
    bk = bk->nxt;
  }
  printf("END\n");
  return;
}