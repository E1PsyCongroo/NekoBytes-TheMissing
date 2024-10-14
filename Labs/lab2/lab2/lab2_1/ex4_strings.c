#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  // TODO: 分配内存来存储字符串“hello”
  // Hint: 我们需要多少字节来存储这个字符串？
  ______ hello_str[______];

  // TODO: 一次存储一个字符
  // Hint: 不要忘记空终止符
  // Note: 我们对字符使用单引号
  ______ = 'h';
  ______ = 'e';
  ______ = 'l';
  ______ = 'l';
  ______ = 'o';

  // TODO: 存储空终止符
  ______ = ______;

  /* Prints hello_str
   * printf 使用 %s 打印以'\0'为终结符的字符串
   * Optional: RTFM about strcmp
   */
  assert(!strcmp("hello", hello_str));
  printf("prints hello: %s\n", hello_str);

  // TODO: 打印 hello_str 的长度
  printf("length of hello: %lu\n", ______(hello_str));

  // TODO: 分配内存来存储字符串“world”
  ______ world_str[______];

  // TODO: 填写类型
  // Note: 这会自动将字符串“world”存储在静态内存中
  //       但静态内存是"不可变"的，所以你可能需要复制它
  //       到栈或堆
  // Hint: 还记得数组可以和指针隐式转换吗？不可变是以什么标识的？
  ______ static_world_str = "world";

  /* TODO: 使用 strcpy 和 static_world_str 将“world”存储到 world_str
   * STFM: man 3 strcpy, https://zh.cppreference.com/w/c/string/byte/strcpy
   * Hint: strcpy 有两个参数:
   *       第一个是目标，然后是源
   */
  ______(______, ______);

  // Prints world_str
  assert(!strcmp("world", world_str));
  printf("prints world: %s\n", world_str);

  // Prints the address of world_str
  printf("address of world_str: %p\n", world_str);

  // TODO: 使用 world_str 计算字母 r 的地址
  // Hint: 字母 r 所在的索引是？
  ______ ptr_to_r = ____________;
  printf("address of 'r': %p\n", ptr_to_r);

  // TODO: 分配内存来存储字符串“hello world”
  ______ hello_world_str[______];

  // TODO: 使用strcpy和hello_str来存储
  //       将字符串“hello”放入 hello_world_str
  ______(______, ______);

  // TODO: 将空格字符存储在“hello world”中的正确索引处
  // Note: 空格与空终止符不同
  //       空终止符由 '\0' 表示
  ______ = ' ';

  // TODO: 使用strcpy、指针运算和world_str来存储
  //       将字符串“world”放入 hello_world_str
  ______(______ + ______, ______);

  // Prints hello_world_str
  assert(!strcmp("hello world", hello_world_str));
  printf("prints hello world: %s\n", hello_world_str);

  return EXIT_SUCCESS;
}
