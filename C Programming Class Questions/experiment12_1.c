/*Write a program to define some constant variable in preprocessor. */
#include <stdio.h>
#define PI 3.14159
#define greeting "Hi"
int main() 
{
    printf("Message: %s, do you know:\n", greeting);
    printf("Value of PI is: %.3f\n", PI);
    double radius = 3.0;
    double area = PI * radius * radius;
    printf("Area of a circle with radius %.2f: %.2f\n", radius, area);
    return 0;
}
