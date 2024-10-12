#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  // 创建一个值为 3 的整数
  // Note: int8_t是数值数据类型，占用1字节内存
  int8_t x = 3;

  // TODO: 分配一个大小为 4 的 int8_t 数组
  // Hint: C语法将数组表示为指向第一个元素的指针
  // Hint: 使用一次 malloc 调用为整个数组分配内存
  //       它之所以有效，是因为元素并排存储
  ______ some_array = malloc(______);
  printf("address of the start of the array: %p\n", some_array);

  // TODO: 计算索引 2 处元素的地址（索引从0开始）
  ______ ptr_to_idx_2 = ____________;
  printf("address of index 2: %p\n", ptr_to_idx_2);

  // TODO: 使用 ptr_to_idx_2 将值 9 存储在索引 2 处
  __________ = 9;

  // TODO: 打印索引 2 处的值
  // Hint: 此空白应与前一个空白相同
  //       请不要hard code 10
  printf("value at index 2: %d\n", __________);

  return 0;
}