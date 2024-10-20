#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int x = 1;
    void *y = malloc(sizeof(int));
    printf("stack: %p\n", (void *)&x);
    printf("heap : %p\n", y);
    free(y);
    return 0;
}
