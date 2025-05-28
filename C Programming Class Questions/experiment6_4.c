/*Develop a C function ISPRIME (num) that accepts an integer argument and
returns 1 if the argument is prime, a 0 otherwise. Write a C program that
invokes this function to generate prime numbers between the given ranges.*/
#include<stdio.h>
int ISPRIME(int n) 
{
    if (n <= 1)
        return 0; 
    for (int i = 2; i <= n/2; i++) 
    {
        if (n % i == 0)
            return 0; 
    }
    return 1;
}
int main() 
{
    int beginning,ending;
    printf("Enter the beginning of the range: ");
    scanf("%d", &beginning);
    printf("Enter the ending of the range: ");
    scanf("%d", &ending);
    printf("Prime numbers between %d and %d are: ", beginning, ending);
    for (int i = beginning; i <= ending; i++) 
    {
        if (ISPRIME(i)) 
        {
            printf("%d ", i);
        }
    }
    printf("\n");
    return 0;
}
