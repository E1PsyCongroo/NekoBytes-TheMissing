#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/// 定义一个动态数组结构体
typedef struct {
  int *data;       // 指向整数数组的指针
  size_t size;     // 当前元素数量
  size_t capacity; // 数组的当前容量（已分配的内存大小）
} IntVector;

/// 初始化一个空的 IntVector，初始容量为 4
void initVector(IntVector *vec) {
  vec->size = 0;
  vec->capacity = 4;                               // 初始容量设为 4
  vec->data = malloc(vec->capacity * sizeof(int)); // 动态分配内存
}

/// 在 IntVector 中添加一个元素
void pushBack(IntVector *vec, int value) {
  // 检查是否需要扩容
  if (vec->size >= vec->capacity) {
    vec->capacity *= 2; // 将容量翻倍
    int *new_data =
        realloc(vec->data, vec->capacity * sizeof(int)); // 重新分配内存
    vec->data = new_data;
  }
  vec->data[vec->size] = value; // 添加新元素到数组中
  vec->size++;                  // 更新当前元素数量
}

/// 获取 IntVector 中指定索引的元素
int get(IntVector *vec, size_t index) {
  assert(index < vec->size); // 检查索引是否越界
  return vec->data[index];   // 返回指定索引的元素
}

/// 释放 IntVector 所分配的内存
void freeVector(IntVector *vec) {
  free(vec->data);  // 释放动态分配的数组
  vec->data = NULL; // 避免悬空指针
  vec->size = 0;
  vec->capacity = 0;
}

/// 打印 IntVector 的内容
void printVector(IntVector *vec) {
  printf("IntVector (size = %zu, capacity = %zu):", vec->size, vec->capacity);
  for (size_t i = 0; i < vec->size; i++) {
    printf(" %d", vec->data[i]);
  }
  printf("\n");
}

int main(void) {
  IntVector vec;
  initVector(&vec); // 初始化向量

  // 添加元素到向量
  for (int i = 0; i < 10; i++) {
    pushBack(&vec, i);
    printVector(&vec); // 打印当前向量内容
  }

  // 获取并打印第5个元素
  int value = get(&vec, 5);
  printf("第5个元素是: %d\n", value);

  freeVector(&vec); // 释放向量内存

  return 0;
}
