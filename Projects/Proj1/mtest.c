#include <assert.h>
#include <errno.h>
#include <float.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#include "config.h"
#include "fsecs.h"
#include "memlib.h"
#include "mm.h"

#define PTR(x) ((void *)((uintptr_t)(x)))

void test_0() {
  // 在此处写你自己的单元测试
  return;
}

void test_1() {
  block bk[5];
  head = &bk[0];
  tail = &bk[4];
  for (int i = 0; i < 5; i++) {
    block_init(&bk[i]);
    bk[i].nxt = i == 4 ? NULL : &bk[i + 1];
    bk[i].pre = i == 0 ? NULL : &bk[i - 1];
    bk[i].ptr = (void *)((uintptr_t)((i + 1) * 16));
    bk[i].size = (i + 1) * 8;
  }
  bk[2].empty = 0;
  assert(find_fit(1919810) == NULL);
  assert(find_fit(8) == &bk[0]);
  assert(find_fit(16) == &bk[1]);
  assert(find_fit(24) == &bk[3]);
  assert(find_fit(32) == &bk[3]);
  assert(find_fit(40) == &bk[4]);
  assert(find_by_ptr((void *)((uintptr_t)(16))) == &bk[0]);
  assert(find_by_ptr((void *)((uintptr_t)(32))) == &bk[1]);
  assert(find_by_ptr((void *)((uintptr_t)(48))) == &bk[2]);
  assert(find_by_ptr((void *)((uintptr_t)(64))) == &bk[3]);
  assert(find_by_ptr((void *)((uintptr_t)(80))) == &bk[4]);
  return;
}

void test_2() {
  block bk[3];
  head = &bk[0];
  tail = &bk[0];
  block_init(&bk[0]);
  bk[0].ptr = PTR(8);
  bk[0].size = 24;
  assert(place(&bk[0], 8) == PTR(8));
  assert(head->ptr == PTR(8));
  assert(head->size == 8);
  assert(head->empty == 0);
  assert(tail->ptr == PTR(16));
  assert(tail->size == 16);
  assert(tail->empty == 1);
  assert(head->nxt == tail);
  assert(tail->pre == head);
  block_init(&bk[0]);
  block_init(&bk[1]);
  block_init(&bk[2]);
  head = &bk[0];
  tail = &bk[2];
  bk[0].nxt = &bk[1];
  bk[1].nxt = &bk[2];
  bk[2].pre = &bk[1];
  bk[1].pre = &bk[0];
  bk[0].ptr = PTR(8);
  bk[1].ptr = PTR(16);
  bk[2].ptr = PTR(32);
  bk[0].size = 8;
  bk[1].size = 16;
  bk[2].size = 8;
  place(&bk[1], 8);
  block *tmp = head;
  int i;
  for (i = 1; i <= 4; i++) {
    assert(tmp != NULL);
    if (i == 4) {
      assert(tmp == tail);
    }
    if (i >= 2) {
      assert(tmp->pre != NULL);
      assert(tmp == tmp->pre->nxt);
    }
    if (i == 2) {
      assert(tmp->empty == 0);
    } else {
      assert(tmp->empty == 1);
    }
    assert(tmp->size == 8);
    assert(tmp->ptr == PTR(i * 8));
    tmp = tmp->nxt;
  }
  return;
}

void test_3() {
  block *bk[3];
  int i;
  for (i = 0; i <= 2; i++) {
    bk[i] = (block *)malloc(sizeof(block));
    block_init(bk[i]);
  }
  head = bk[0];
  tail = bk[2];
  bk[0]->nxt = bk[1];
  bk[1]->nxt = bk[2];
  bk[2]->pre = bk[1];
  bk[1]->pre = bk[0];
  bk[0]->ptr = PTR(8);
  bk[1]->ptr = PTR(16);
  bk[2]->ptr = PTR(32);
  bk[0]->size = 8;
  bk[1]->size = 16;
  bk[2]->size = 32;
  coalesce(bk[1]);
  assert(head == tail);
  assert(head->pre == NULL);
  assert(head->nxt == NULL);
  assert(head->ptr == PTR(8));
  assert(head->size == 56);
  return;
}

void test_4() {
  void *Ptr;
  int i;
  head = NULL;
  tail = NULL;
  for (i = 1; i <= 5; i++) {
    if (i == 1)
      Ptr = extend_heap(8)->ptr;
    else
      extend_heap(8);
    assert(head != NULL);
    assert(head == tail);
    assert(head->empty == 1);
    assert(head->size == i * 8);
    assert(head->ptr == Ptr);
  }
  return;
}

/*

在命令行中运行mtest [num]以运行对应测试，如：
mtest 1
执行Task1的单元测试

mtest 0
运行自定义测试

mtest a
运行所有预设测试

mtest A
运行所有测试（包括自定义）

*/
int main(int argc, char **argv) {
  mem_init();
  if (argc < 2) {
    printf("ERROR: Missing arguments\n");
    exit(1);
  }
  if (argc > 2) {
    printf("ERROR: Too many arguments\n");
    exit(1);
  }
  switch (argv[1][0]) {
  case '0':
    test_0();
    break;
  case '1':
    test_1();
    break;
  case '2':
    test_2();
    break;
  case '3':
    test_3();
    break;
  case '4':
    test_4();
    break;
  case 'a':
    test_1();
    test_2();
    test_3();
    test_4();
    break;
  case 'A':
    test_0();
    test_1();
    test_2();
    test_3();
    test_4();
    break;
  default:
    printf("ERROR: Wrong argument\n");
    exit(1);
    break;
  }
  printf("Success!\n");
  return 0;
}