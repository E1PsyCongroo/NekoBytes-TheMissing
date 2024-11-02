#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 定义链表节点结构体
typedef struct Node {
  int elem;          // 节点存储的元素
  struct Node *next; // 指向下一个节点的指针
} Node;

// 创建链表，使用给定的数组和长度
Node *createList(int array[], int length) {
  // 分配头节点内存
  Node *head = malloc(sizeof(Node));
  head->elem = 0;    // 初始元素数量为0
  head->next = NULL; // 头节点的下一个指针初始化为NULL

  Node *p = NULL; // 临时节点指针
  // 遍历数组，创建链表节点
  for (int i = 0; i < length; i++) {
    p = malloc(sizeof(Node)); // 为新节点分配内存
    p->elem = array[i];       // 将数组元素赋值给新节点
    p->next = head->next; // 新节点的下一个指针指向当前链表的第一个节点
    head->next = p; // 将新节点链接到链表
    head->elem++;   // 更新头节点的元素数量
  }
  return head; // 返回头节点
}

// 获取链表中指定索引的元素
bool GetElem(Node *list, int i, int *e) {
  Node *p;        // 临时指针
  p = list->next; // 从第一个节点开始
  int j = 0;      // 当前索引
  // 遍历链表到达指定索引
  while (p && j < i) {
    p = p->next; // 移动到下一个节点
    j++;
  }
  // 如果未找到，返回false
  if (!p) {
    return false;
  }
  *e = p->elem; // 将找到的元素值赋给指针e
  return true;  // 返回成功
}

// 在链表的指定索引插入元素
bool ListInsert(Node *list, int i, int e) {
  Node *p = list; // 从头节点开始
  int j = 0;      // 当前索引
  // 遍历链表到达指定索引
  while (p && j < i) {
    p = p->next; // 移动到下一个节点
    j++;
  }
  // 如果索引超出链表长度，返回false
  if (!p) {
    return false;
  }
  // 创建新节点并赋值
  Node *r = malloc(sizeof(Node));
  r->elem = e; // 设置新节点的元素值
  r->next = p->next; // 新节点的下一个指针指向当前节点的下一个节点
  p->next = r;  // 当前节点的下一个指针指向新节点
  list->elem++; // 更新头节点的元素数量
  return true;  // 返回成功
}

// 从链表中删除指定索引的元素
bool ListDelete(Node *list, int i, int *e) {
  Node *p = list; // 从头节点开始
  int j = 0;      // 当前索引
  // 遍历链表到达指定索引的前一个节点
  while (p->next && j < i) {
    p = p->next; // 移动到下一个节点
    j++;
  }
  // 如果索引超出链表长度，返回false
  if (!(p->next)) {
    return false;
  }
  Node *r = p->next; // 要删除的节点
  p->next = r->next; // 将前一个节点的下一个指针指向要删除节点的下一个节点
  *e = r->elem; // 获取被删除节点的元素值
  free(r);      // 释放被删除节点的内存
  return true;  // 返回成功
}

// 打印链表中的所有元素
void ListPirnt(Node *list) {
  Node *p = list->next; // 从第一个节点开始
  printf("List: (");
  // 遍历链表并打印每个元素
  while (p != NULL) {
    printf(" %d", p->elem);
    p = p->next; // 移动到下一个节点
  }
  printf(" )\n");
}

// 释放链表的内存
void ListDestructs(Node *list) {
  Node *p = list; // 从头节点开始
  while (p != NULL) {
    Node *r = p->next; // 记录下一个节点
    free(p);           // 释放当前节点的内存
    p = r;             // 移动到下一个节点
  }
}

int main(void) {
  // 初始化数组
  int array[] = {1, 2, 3, 4, 5};
  // 创建链表
  Node *head = createList(array, sizeof(array) / sizeof(array[0]));

  // 打印初始链表
  ListPirnt(head);

  // 在索引2处插入元素6
  printf("Inserting element 6 at index 2:\n");
  if (ListInsert(head, 2, 6)) {
    ListPirnt(head); // 打印链表
  } else {
    printf("Insertion failed\n"); // 插入失败提示
  }

  // 获取索引3的元素
  int elem;
  printf("Getting element at index 3:\n");
  if (GetElem(head, 3, &elem)) {
    printf("Element at index 3 is: %d\n", elem); // 打印获取到的元素
  } else {
    printf("Get failed\n"); // 获取失败提示
  }

  // 删除索引1的元素
  printf("Deleting element at index 1:\n");
  if (ListDelete(head, 1, &elem)) {
    printf("Deleted element is: %d\n", elem); // 打印被删除的元素
    ListPirnt(head);                          // 打印链表
  } else {
    printf("Deletion failed\n"); // 删除失败提示
  }

  // 释放链表的内存
  ListDestructs(head);
  return 0;
}
