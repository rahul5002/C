#include<stdio.h>

int main()
{
    int m,n,temp=0;
    printf("Enter the no.of rows:");
    scanf("%d", &m);
    printf("Enter the no.of columns:");
    scanf("%d", &n);
    int a[m][n];
    for (int i=0;i<m;i++)
    {
        for (int j=0;j<n;j++)
        {
            printf("Enter the elements:");
            scanf("%d", &a[i][j]);
        }
    }
    printf("Matrix is:\n");
    for (int i=0;i<m;i++)
    {
        for (int j=0;j<n;j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    for (int i=0;i<m;i++)
    {
        for (int j=0;j<n;j++)
        {
            if (a[i][j]>temp)
                temp=a[i][j];
        }
    }
    printf("Maximum number is:%d\n",temp);
    for (int i=0;i<m;i++)
    {
        for (int j=0;j<n;j++)
        {
            if (a[i][j]<temp)
                temp=a[i][j];
        }
    }
    printf("Minimum number is:%d",temp);
    return 0;
}