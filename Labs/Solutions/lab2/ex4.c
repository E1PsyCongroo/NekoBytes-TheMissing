#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  // TODO: 分配内存来存储字符串“hello”
  // Hint: 我们需要多少字节来存储这个字符串？
  char hello_str[6];

  // TODO: 一次存储一个字符
  // Hint: 不要忘记空终止符
  // Note: 我们对字符使用单引号
  hello_str[0] = 'h';
  hello_str[1] = 'e';
  hello_str[2] = 'l';
  hello_str[3] = 'l';
  hello_str[4] = 'o';

  // TODO: 存储空终止符
  hello_str[5]= '\n';

  // Prints hello_str
  printf("prints hello: %s\n", hello_str);

  // TODO: print the length of hello_str
  printf("length of hello: %lu\n", strlen(hello_str));

  // TODO: 分配内存来存储字符串“world”
  char world_str[6];

  // TODO: 填写类型
  // Note: 这会自动将字符串“world”存储在静态内存中
  //       但静态内存是不可变的，所以你可能需要复制它
  //       到栈或堆
  char* static_world_str = "world";

  // TODO: 使用 strcpy 和 static_world_str 将“world”存储到 world_str
  // Hint: strcpy 有两个参数:
  //       第一个是目标，然后是源
  strcpy(world_str, static_world_str);

  // Prints world_str
  printf("prints world: %s\n", world_str);

  // Prints the address of world_str
  printf("address of world_str: %p\n", world_str);

  // TODO: 使用 world_str 计算字母 r 的地址
  char* ptr_to_r = &world_str[2];
  printf("address of 'r': %p\n", ptr_to_r);

  // TODO: 分配内存来存储字符串“hello world”
  char hello_world_str[12];

  // TODO: 使用strcpy和hello_str来存储
  //       将字符串“hello”放入 hello_world_str
  strcpy(hello_world_str, hello_str);

  // TODO: 将空格字符存储在“hello world”中的正确索引处
  // Note: 空格与空终止符不同
  //       空终止符由 '\0' 表示
  hello_world_str[5] = ' ';

  // TODO: 使用strcpy、指针运算和world_str来存储
  //       将字符串“world”放入 hello_world_str
  strcpy(hello_world_str + 6, world_str);

  // Prints hello_world_str
  printf("prints hello world: %s\n", hello_world_str);

  return 0;
}