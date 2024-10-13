#include <stdio.h>
#include <stdlib.h>

int *int_on_stack(void) {
  // 在栈上为整数分配内存
  int x = 12;

  /* 返回一个指向数字 12 的指针
   * clangd 静态语法检查器和编译时的 gcc 编译器都发出了警告️，为什么会这样？
   * 尝试 STFW:
   * https://stackoverflow.com/questions/4824342/returning-a-local-variable-from-function-in-c
   */
  return &x;
}

int *int_on_heap(void) {
  /* TODO：在堆上为整数分配内存
   * 怎么堆上分配数据呢？了解一下 malloc 的用法
   * 尝试使用 man 3 malloc 阅读文档，或者阅读在线文档:
   * https://zh.cppreference.com/w/c/memory/malloc
   */
  ______ ptr_to_12 = ______;

  // TODO：将数字 12 存储在刚刚分配的内存中
  ______ = 12;

  // 返回一个指向数值 12 的指针
  return ptr_to_12;
}

int main(void) {
  int *ptr_to_stack = int_on_stack();
  int *ptr_to_heap = int_on_heap();

  printf("ptr_to_stack is the address %p\n", ptr_to_stack);
  printf("ptr_to_heap is the address %p\n", ptr_to_heap);

  /* 这是什么？
   * 尝试使用 man 3 free 阅读文档，或者阅读在线文档:
   * https://zh.cppreference.com/w/c/memory/free
   * 为什么需要 free, 如果你现在无法得出答案，请保留疑问继续参加讲座
   */
  free(ptr_to_heap);

  /* EXIT_SUCCESS 是什么？
   * 它应该表示正常的程序退出状态
   * 尝试使用 man EXIT_SUCCESS 阅读手册，或者阅读在线文档:
   * https://zh.cppreference.com/w/c/program/EXIT_status
   *
   * 使用 return 0; 当然是可以的
   * 但是显而易见 return EXIT_SUCCESS; 更能标明程序的正常退出，不是吗？
   */
  return EXIT_SUCCESS;
}
