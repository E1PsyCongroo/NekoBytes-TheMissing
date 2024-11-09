/* 分别尝试使用
 * gcc -o math math.c
 * gcc -O2 -o math math.c
 * gcc -O2 -DVOLATILE -o math math.c
 * gcc -lm -DVOLATILE -o math math.c
 * 编译程序
 */
#include <math.h>
#include <stdio.h>

int main(void) {
  double a = 2;
  printf("sqrt(a) = %f\n", sqrt(a));
  /*  */
#ifdef VOLATILE
  volatile double b = 2;
  printf("sqrt(b) = %f\n", sqrt(b));
#endif
  return 0;
}
