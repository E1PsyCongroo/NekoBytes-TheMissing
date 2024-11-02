#include <stdio.h>

int main(void) {
  int int_num = -1;
  float float_num = 1.0;
  printf("sizeof int_num: %zu, value: %#x\nsizeof float_num: %zu, value: %#x\n",
         sizeof int_num, int_num, sizeof float_num, *(int *)&float_num);
  printf("addr of int_num: %p, addr of float_num: %p\n", &int_num, &float_num);
  return 0;
}
