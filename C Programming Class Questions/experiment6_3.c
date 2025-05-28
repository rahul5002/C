/*Develop a recursive function FIBO (num) that accepts an integer argument. 
Write a C program that invokes this function to generate the Fibonacci sequence up to num.*/
#include<stdio.h>

int FIBO(int n) 
{
    if (n <= 1)
        return n;
    return FIBO(n-1) + FIBO(n-2);
}
int main() 
{
    int num, i;
    printf("Enter the number of terms for the Fibonacci series: ");
    scanf("%d", &num);
    printf("Fibonacci sequence up to %d terms:\n", num);
    printf("%d", FIBO(0));
    for (i = 1; i < num; i++) 
    {
        printf("+%d", FIBO(i));
    }
    printf("\n");
    return 0;
}
