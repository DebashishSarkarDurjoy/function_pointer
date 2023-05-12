#include <stdio.h>
#include <stdbool.h>

int silly(int x) {
    return x * x;
}

int another(int (*ptr)(int)) {
    return ptr(20);
}

int (*other(int (*temp)(int)))(int) {
    return temp;
}

int main(void) {
    // int (*func_ptr)(int) = silly;
    // printf("%d\n", func_ptr(10));
    int (*ptr)(int) = other(silly);
    printf("%d\n", ptr(12));

    return 0;
}