/*Develop a recursive function GCD (num1, num2) that accepts two integer
arguments. Write a C program that invokes this function to find the greatest
common divisor of two given integers*/
#include<stdio.h>
int GCD(int num1, int num2) 
{
    if (num2 == 0)
    {
        return num1;
    }
    return GCD(num2, num1 % num2);
}
int main() 
{
    int num1, num2;
    printf("Enter the first number: ");
    scanf("%d", &num1);
    printf("Enter the second number: ");
    scanf("%d", &num2);
    printf("The GCD of %d and %d is: %d\n", num1, num2, GCD(num1, num2));
    return 0;
}
