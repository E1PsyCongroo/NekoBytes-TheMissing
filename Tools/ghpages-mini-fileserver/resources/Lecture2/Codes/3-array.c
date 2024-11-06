#include <stdio.h>
#include <stdlib.h>

int main(void) {
  //  定义
  unsigned char temp[10] = {0x11, 0x15, 0x22};

  //  数组的地址
  printf("temp address: %p\n", temp);

  //  更改
  temp[3] = 0xa8;

  //  使用
  for (size_t i = 0; i < 10; i++) {
    printf("%02x ", temp[i]);
  }
  printf("\n");
  return EXIT_SUCCESS;
}
