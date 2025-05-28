#include<stdio.h>

int main()
{
    int m,n;
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
            if (a[i][j]>a[j][i])
                printf("%d",a[i][j]);
            else
                printf("%d",a[j][i]);
        }
    }
    return 0;
}