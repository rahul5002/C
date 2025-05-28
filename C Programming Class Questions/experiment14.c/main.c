#include <stdio.h>
#include "arithmetic.h"
int main() 
{
    int a = 20, b = 10;
    printf("Addition: %d + %d = %d\n", a, b, add(a, b));
    printf("Subtraction: %d - %d = %d\n", a, b, subtract(a, b));
    printf("Multiplication: %d * %d = %d\n", a, b, multiply(a, b));
    if (b != 0)
        printf("Division: %d / %d = %d\n", a, b, divide(a, b));
    else
        printf("Division by zero is not allowed.\n");

    return 0;
}
