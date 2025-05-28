#include<stdio.h>

int main()
{
    int n,i;
    printf("Enter a number(for better pattern representation enter odd number):");
    scanf("%d",&n);
    for (i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++)
        {
            if ((i==j)||(i+j==n+1))
                printf("*");
            else
                printf(" ");
        }printf("\n");
    }
    return 0;
}