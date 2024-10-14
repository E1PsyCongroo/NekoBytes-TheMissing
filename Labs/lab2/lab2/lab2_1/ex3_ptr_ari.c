#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  // 创建一个值为 8 的整数
  // Note: int16_t 是一种数值数据类型，占用 2 个字节的内存
  int16_t x = 8;

  // Hint: 在这里将 4 个 int16_t 元素的数组分配到堆上
  // Hint: C 语法将数组表示为指向第一个元素的指针
  int16_t *some_array = malloc(sizeof(int16_t) * 4);
  printf("address of the start of the array: %p\n", some_array);

  // TODO: 计算索引 2 处元素的地址（索引从0开始）
  ______ ptr_to_idx_2 = ____________;
  printf("address of index 2: %p\n", ptr_to_idx_2);

  // TODO: 使用 ptr_to_idx_2 将值 9 存储在索引 2 处
  __________ = 9;

  // TODO: 打印索引 2 处的值
  // Hint: 此空白应与前一个空白相同
  //       请不要 hard code 10
  printf("value at index 2: %d\n", __________);

  assert(some_array[2] == 9);
  free(some_array);
  return EXIT_SUCCESS;
}
