#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Array {
  int len;
  int *a;
} Array;

Array split_number(int x) {
  if (x == 0) {
    int *a = (int *)malloc(sizeof(int)); // 把 a 理解为 int a[1];
    a[0] = 0;
    return (Array){1, a};
  }

  int *a = malloc(sizeof(int) * 10), cnt = 0; // 把 a 理解为 int a[10];
  while (x) {
    a[cnt++] = x % 10;
    x /= 10;
  }
  return (Array){cnt, a};
}

void mutiply(Array x, Array y) {
  Array z = {
    .len = x.len + y.len,
    .a = malloc(sizeof(int) * (x.len + y.len))  // 把 z.a 理解为 int z.a[x.len + y.len]
  };
  memset(z.a, 0, sizeof(int) * z.len);
  int i, j;
  for (i = 0; i < x.len; i++) {
    for (j = 0; j < y.len; j++) {
      z.a[i + j] += x.a[i] * y.a[j];
    }
  }
  for (i = 0; i < z.len - 1; i++) {
    z.a[i + 1] += z.a[i] / 10;
    z.a[i] %= 10;
  }
  while (z.a[z.len - 1] == 0) {
    z.len--;
  }
  for (i = z.len - 1; i >= 0; i--) {
    printf("%d", z.a[i]);
  }
  printf("\n");
  free(z.a);
  return;
}

int main(void) {
  Array x = split_number(INT_MAX); // INT_MAX = 2147483647, int 可表示的最大正数
  Array y = split_number(INT_MAX);
  mutiply(x, y);
  free(x.a);
  free(y.a);
  return 0;
}
