#include<stdio.h>
int main()
{
    for(int i=1;i<=5;i++)
    {
        for(int k=1;k<=5-i;k++)
        {
            printf(" ");
        }
        for(int m=1;m<=2*i-1;m++)
        {
            printf("*");
        }
        printf("\n"); 
    }
    for(int i=1;i<=4;i++)
    {
        for(int k=1;k<=1+i;k++)
        {
            printf(" ");
        }
        for(int m=5;m>=2*i-1;m--)
        {
            printf("*");
        }
        printf("\n"); 
    }
        
    return 0;
}