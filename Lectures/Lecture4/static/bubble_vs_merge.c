#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#define N 10000
int arr[N];
double get_time() {
  struct timeval tv;
  gettimeofday(&tv, NULL);
  return tv.tv_sec + tv.tv_usec / 1000000.0;
}
void bubble_sort(int *arr, int n) {
  int i, j, tmp;
  for (i = 0; i < n; i++) {
    for (j = n - 1; j > i; j--) {
      if (arr[j] < arr[j - 1]) {
        tmp = arr[j - 1];
        arr[j - 1] = arr[j];
        arr[j] = tmp;
      }
    }
  }
}
void merge_sort(int *arr, int l, int r) {
  if (l >= r)
    return;
  int mid = (l + r) / 2;
  merge_sort(arr, l, mid);
  merge_sort(arr, mid + 1, r);
  int *buffer = (int *)malloc(sizeof(int) * (r - l + 1)), len = 0;
  int i = l, j = mid + 1;
  while (i <= mid && j <= r) {
    buffer[len++] = arr[i] < arr[j] ? arr[i++] : arr[j++];
  }
  while (i <= mid) {
    buffer[len++] = arr[i++];
  }
  while (j <= r) {
    buffer[len++] = arr[j++];
  }
  memcpy(arr + l, buffer, sizeof(int) * len);
  free(buffer); // REMEMBER!!!
  return;
}
void init() {
  srand(114514);
  int i;
  for (i = 0; i < N * 4; i++) {
    int x = rand() % N, y = rand() % N, tmp;
    tmp = arr[x];
    arr[x] = arr[y];
    arr[y] = tmp;
  }
  return;
}
int main() {
  double start_time = 0, end_time = 0;
  init();
  start_time = get_time();
  merge_sort(arr, 0, N - 1);
  end_time = get_time();
  printf("merge_sort cost : %.6lf second on datasize:[%d]\n",
         end_time - start_time, N);
  init();
  start_time = get_time();
  bubble_sort(arr, N);
  end_time = get_time();
  printf("bubble_sort cost : %.6lf second on datasize:[%d]\n",
         end_time - start_time, N);
  return 0;
}