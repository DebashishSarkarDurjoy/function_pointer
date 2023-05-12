#include <stdio.h>
#include <stdbool.h>

int add(int x, int y) {
    return x + y;
}

int subtract(int x, int y) {
    return y - x;
}

int multiply(int x, int y) {
    return x * y;
}

int (*selection(int i))(int, int) {
    if (i == 0) return add;
    if (i == 1) return subtract;
    if (i == 2) return multiply;
    return NULL;
}

int (*intermediate(int (*func_pointer(int i))(int, int)))(int, int) {
    return func_pointer(2);
}

int main(void) {
    // int (*function_pointer)(int, int) = &add;

    // int result = function_pointer(10,11);
    // printf("%d\n", result);

    // int (*array[])(int, int) = {add, subtract, multiply};
    // int acc = 0;
    // for (int i = 0; i < 3; i++) {
    //     acc += (array[i])(2,10);
    //     printf("%d\n", acc);
    // }

    int (*result)(int, int) = intermediate(selection);
    printf("%d\n", result(4,5));
   
    return 0;
}