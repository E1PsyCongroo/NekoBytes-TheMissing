struct Array {
  int len;
  int *a;
};
typedef struct Array array;
array split_number(int x) {
  if (x == 0) {
    int *a = (int *)malloc(sizeof(int));
    a[0] = 0;
    return (array){1, a};
  }
  int tmp = 1, len = 0;
  while (tmp <= x) {
    tmp *= 10;
    len++;
  }
  int *a = malloc(sizeof(int) * len), cnt = 0;
  while (x) {
    a[cnt++] = x % 10;
    x /= 10;
  }
  return (array){len, a};
}
void mutiply(array x, array y) {
  array z;
  z = (array){x.len + y.len, (int *)malloc(sizeof(int) * (x.len + y.len))};
  memset(z.a, 0, sizeof(int) * z.len);
  iny i, j;
  for (i = 0; i < x.len; i++) {
    for (j = 0; j < y.len; j++) {
      z.a[i + j] += x.a[i] * y.a[j];
    }
  }
  for (i = 0; i < z.len - 1; i++) {
    z.a[i + 1] += z.a[i] / 10;
    z.a[i] %= 10;
  }
  while (z.a[z.len - 1] == 0)
    z.len--;
  for (i = z.len - 1; i >= 0; i--) {
    printf("%d", z.a[i]);
  }
  printf("\n");
  free(z.a); // 哦老天，想想这是为什么
  return;
}