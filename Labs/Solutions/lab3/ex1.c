#include <stdio.h>
#include <stdlib.h>

int* int_on_stack() {
  // 在堆栈上为整数分配内存
  int x = 12;

  // 返回一个指向数字 12 的指针
  return &x;
}

int* int_on_heap() {
  // TODO：在堆上为整数分配内存
  int* ptr_to_12 ;

  // TODO：将数字 12 存储在您刚刚分配的内存中
  *ptr_to_12 = 12;

  // 返回一个指向数字 12 的指针
  return ptr_to_12;
}

int main() {
  int* ptr_to_stack = int_on_stack();
  int* ptr_to_heap = int_on_heap();

  printf("ptr_to_stack is the address %p\n", ptr_to_stack);
  printf("ptr_to_heap is the address %p\n", ptr_to_heap);

  return 0;
}
