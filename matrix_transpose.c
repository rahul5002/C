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
    printf("Matrix is:\n");
    for (int i=0;i<m;i++)
    {
        for (int j=0;j<n;j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
   printf("Transpose matrix is:\n");
    for (int i=0;i<m;i++)
    {
        for (int j=0;j<n;j++)
        {
            printf("%d ",a[j][i]);
        }
        printf("\n");
    }
    return 0;
}