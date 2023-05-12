#include <stdio.h>
#include <stdbool.h>

void function(int x) {
    printf("x: %d\n", x);
}

double add(double x, double y) {
    return x + y;
}

int subtract(int x, int y) {
    return y - x;
}

int multiply(int x, int y) {
    return x * y;
}

int divide(int x, int y) {
    return y / x;
}

int (*select_operation())(int, int) {
    int option = 0;
    printf("Select option: \n");
    printf("1. subtract\n");
    printf("2. multiply\n");
    printf("3. divide\n");

    scanf("%d", &option);

    if (option == 1) return subtract;
    if (option == 2) return multiply;
    if (option == 3) return divide;
    else return NULL;
}

bool freeze_F(int temp) {
    if (temp <= 32) return true;
    else return false;
}

bool freeze_C(int temp) {
    if (temp <= 0) return true;
    else return false;
}

void is_freezing( bool (*freeze_check)(int) ) {
    int temp = 0;
    printf("Enter temperature: ");
    scanf("%d", &temp);

    if (freeze_check(temp)) printf("Freezing...\n");
    else printf("Not freezing...\n");
}

int main(void) {
    void (*function_pointer)(int);
    function_pointer = &function;
    (*function_pointer)(4);

    double (*add_pointer)(double, double);
    add_pointer = &add;
    double result = add_pointer(10, 10);
    printf("result: %f\n", result);

    int (*array[])(int, int) = {subtract, multiply, divide};
    printf("%d\n", array[1](100,2));


    // int (*operation)(int, int) = select_operation();
    // printf("%d\n", operation(20,20));

    is_freezing(freeze_F);

    return 0;
}