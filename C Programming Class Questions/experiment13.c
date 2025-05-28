/*Write a program to define multiple macro to perform arithmetic functions.*/
#include <stdio.h>
#define ADD(x, y) ((x) + (y))
#define SUBTRACT(x, y) ((x) - (y))
#define MULTIPLY(x, y) ((x) * (y))
#define DIVIDE(x, y) ((x) / (y))
int main() 
{
    int a = 10, b = 2;
    printf("Addition of %d and %d: %d\n", a, b, ADD(a, b));
    printf("Subtraction of %d and %d: %d\n", a, b, SUBTRACT(a, b));
    printf("Multiplication of %d and %d: %d\n", a, b, MULTIPLY(a, b));
    if (b != 0) 
        printf("Division of %d by %d: %d\n", a, b, DIVIDE(a, b));
    else
        printf("Division by zero is not allowed.\n");
    return 0;
}
