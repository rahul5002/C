/*Develop a recursive and non-recursive function FACT(num) to find the
factorial of a number, n!, defined by FACT(n) = 1, if n = 0. Otherwise, FACT(n) = n * FACT(n-1).
Using this function, write a C program to compute the binomial coefficient.
Tabulate the results for different values of n and r with suitable messages.*/
#include <stdio.h>
int FACT_recursive(int num) 
{
    if (num == 0)
        return 1;
    else
        return (num * FACT_recursive(num - 1));
}
int FACT_non_recursive(int num)
{
    int result = 1;
    for (int i = 1; i <= num; i++)
        result *= i;
    return result;
}
int main()
{
    int n, r, choice;
    printf("Choose Factorial method: 1. Recursive 2. Non-recursive: ");
    scanf("%d", &choice);
    
    printf("Enter a value for n: ");
    scanf("%d", &n);
    
    printf("Enter a value for r: ");
    scanf("%d", &r);
    
    if (r > n)
    {
        printf("Invalid values of n and r. r should not be greater than n.\n");
        return 1;
    }
    int factorial_n, factorial_r, factorial_n_r;
    if (choice == 1)
    {
        factorial_n = FACT_recursive(n);
        factorial_r = FACT_recursive(r);
        factorial_n_r = FACT_recursive(n - r);
    }
    else
    {
        factorial_n = FACT_non_recursive(n);
        factorial_r = FACT_non_recursive(r);
        factorial_n_r = FACT_non_recursive(n - r);
    }
    int binomial_coefficient = factorial_n / (factorial_r * factorial_n_r);
    printf("Factorial of n is: %d\n",factorial_n);
    printf("Factorial of r is: %d\n",factorial_r);
    printf("Factorial of (n-r) is: %d\n",factorial_n_r);
    printf("Binomial Coefficient C(%d, %d) is: %d\n", n, r, binomial_coefficient);
    return 0;
}
