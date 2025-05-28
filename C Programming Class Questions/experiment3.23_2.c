#include<stdio.h>

int main()
{
    int n;
    printf("Enter the number of rows you want to be printed:");
    scanf("%d",&n);
    for(int i=0;i<=n;i++)
    {
            for(int k=1;k<=n-i;k++)
                {
                        printf("\t ");
                }
            int x=1;
            for (int j=0;j<=i;j++)
                {
                        printf("\t%d\t",x);
                        x=x*(i-j)/(j+1);
                }
        printf("\n");
    }
    return 0;

}