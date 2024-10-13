#include <stdio.h>

void swap1(int x, int y) {
    int t = x;
    x = y;
    y = t;
}

void swap2(int *x, int *y) {
    int t = *x;
    *x = *y;
    *y = t;
}

int main(void) {
    int a = 1, b = 2;
    printf("a = %d, b = %d\n", a, b);
    swap1(a, b);
    printf("a = %d, b = %d after swap1\n", a, b);
    swap2(&a, &b);
    printf("a = %d, b = %d after swap2\n", a, b);
    return 0;
}
