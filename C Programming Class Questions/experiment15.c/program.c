#include <stdio.h>
#include "arithmetic.h"

int main() 
{
    int x = 10, y = 5;
    printf("Using the Shared Library:\n");
    printf("Addition: %d + %d = %d\n", x, y, add(x, y));
    printf("Subtraction: %d - %d = %d\n", x, y, subtract(x, y));
    printf("Multiplication: %d * %d = %d\n", x, y, multiply(x, y));
    if (y != 0) 
        printf("Division: %d / %d = %d\n", x, y, divide(x, y));
    else 
        printf("Division by zero is not allowed.\n");
    
    return 0;
}
