int f(int n) {
  if (n <= 2)
    return 1;
  return f(n - 2) + f(n - 1);
}