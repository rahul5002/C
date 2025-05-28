#include<stdio.h>
int main()
{
    int n,x,k,j;
    printf("Enter the number of rows you want to be printed:");
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        for(int m=1;m<=5-i;m++)
        {
            printf(" ");
        }
             for (k=i;k>1;k--)
            {
                printf("%d",k);
            }
            for (j=1;j<=i;j++)
            {
                printf("%d",j);
            }
            
        printf("\n");
    }
    return 0;
}