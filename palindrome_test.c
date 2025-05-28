#include<stdio.h>

int main()
{
    int n,a=0;
    printf("Enter a number:");
    scanf("%d",&n);
    int original=n,i=n;
    while(i!=0)
    {
        a=(a*10)+(i%10);
        i/=10;
    }
    if (a==original)
        printf("%d is a palindrome.",original);
    else
        printf("%d is not a palindrome.",original);
    return 0;
}