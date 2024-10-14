#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void add_one(int input) { input += 1; }

/* TODO: 创建一个指向输入的指针
 * Hint: C 语言的函数参数是按值传输的
 *       这意味着在"函数参数"与函数调用"传递的参数"表示的内存区域不是同一块
 *       我们是如何获取内存区域的地址的？又是用什么类型存储它的呢？
 */
void add_one_pointer(______ input) {
  // TODO: input指向的整数加一
  ________ += 1;
}

int main(void) {
  // 将 x（整数）赋值为 5
  int x = 5;

  // 在 x 上调用 add_one
  add_one(x);

  // 这一行应该打印 5
  // 这是为什么？
  printf("add_one: %d\n", x);

  // 让我们尝试使用 add_one_pointer

  // TODO: 使用 add_one_pointer 来增加 x
  // Hint: 将 x 的类型与参数的类型进行比较
  //       对于 add_one_pointer
  add_one_pointer(______);

  // 这一行应该打印 6
  assert(x == 6);
  printf("add_one_pointer: %d\n", x);

  return EXIT_SUCCESS;
}
