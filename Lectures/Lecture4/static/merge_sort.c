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