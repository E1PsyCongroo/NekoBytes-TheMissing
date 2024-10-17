#include <stdint.h>
#include <stdio.h>

extern int mm_init(void);
extern void *mm_malloc(size_t size);
extern void mm_free(void *ptr);
extern void *mm_realloc(void *ptr, size_t size);

/*
 * Students work in teams of one or two.  Teams enter their team name,
 * personal names and login IDs in a struct of this
 * type in their bits.c file.
 */
typedef struct {
  char *teamname; /* ID1+ID2 or ID1 */
  char *name1;    /* full name of first member */
  char *id1;      /* login ID of first member */
  char *name2;    /* full name of second member (if any) */
  char *id2;      /* login ID of second member */
} team_t;

extern team_t team;

struct Block {
  struct Block *pre;
  struct Block *nxt;
  void *ptr;
  size_t size;
  int empty;
};
typedef struct Block block;
extern block *head, *tail;

extern void block_init(block *bk);

extern block *find_fit(size_t size);
extern block *extend_heap(size_t words);
extern block *coalesce(block *bk);
extern block *find_by_ptr(void *ptr);
extern void *place(block *bk, size_t size);
extern void print_all();
