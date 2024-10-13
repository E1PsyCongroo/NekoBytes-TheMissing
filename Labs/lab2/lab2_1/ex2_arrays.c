#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  /* 创建一个值为 3 的整数变量
   * Note: int8_t是数值数据类型，占用 1 字节 = 8 位 内存大小
   * Optional: 阅读 man stdint.h 查看其他的数值数据类型，或者阅读在线文档:
   * https://zh.cppreference.com/w/c/types/integer
   * 考虑问题: 为什么我们需要固定字节的数据类型？
   */
  int8_t x = 3;

  /* TODO: 分配一个 4 个 int8_t 元素的数组
   * Note: C 语言将数组表示为指向第一个元素的指针
   *       它之所以有效，是因为元素并排存储
   */
  ______ some_array[] = {1, 2, 3, 4};
  /*
   * printf 使用 %p 来打印指针的值（地址）
   * some_array 前的取地址符号‘&’时候可以省略？为什么？
   */
  printf("address of the start of the array: %p\n", &some_array);

  // TODO: 计算索引 2 处元素的地址（索引从0开始）
  ______ ptr_to_idx_2 = ____________;
  printf("address of index 2: %p\n", ptr_to_idx_2);

  // TODO: 使用 ptr_to_idx_2 将值 9 存储在索引 2 处
  __________ = 9;

  // TODO: 打印索引 2 处的值
  // Hint: 此空白可以与前一个空白相同
  //       但请不要进行硬编码: printf("%d", 9);
  printf("value at index 2: %d\n", __________);

  // Optional: assert 是什么？
  // 这里不做要求，但是好学的你应该已经学会 STFM 了吧
  assert(some_array[0] == 1);
  assert(some_array[1] == 2);
  assert(some_array[2] == 9);
  assert(some_array[3] == 4);
  return EXIT_SUCCESS;
}
