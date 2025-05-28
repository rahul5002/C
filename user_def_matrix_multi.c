#include<stdio.h>

int main()
{
    int m1,m2,n1,n2;
    printf("Enter the no.of rows for first matrix:");
    scanf("%d", &m1);
    printf("Enter the no.of columns for first matrix:");
    scanf("%d", &n1);
    printf("Enter the no.of rows for second matrix:");
    scanf("%d", &m2);
    printf("Enter the no.of columns for second matrix:");
    scanf("%d", &n2);
    if (m2 != n1) 
    {
        printf("Invalid input. Matrix multiplication not possible!\n");
        return 1; 
    }

    int arr1[m1][n1],arr2[m2][n2],ans[m1][n2];
    for (int i=0;i<m1;i++)
    {
        for (int j=0;j<n1;j++)
        {
            printf("Enter the elements of first matrix:");
            scanf("%d",&arr1[i][j]);
        }
    }

    for (int i=0;i<m2;i++)
    {
        for (int j=0;j<n2;j++)
        {
            printf("Enter the elements of second matrix:");
            scanf("%d",&arr2[i][j]);
        }
    }
    printf("First matrix:\n");
    for (int i=0;i<m1;i++)
    {
        for (int j=0;j<n1;j++)
        {
            printf("%d ",arr1[i][j]);
        }printf("\n");
    }
    printf("Second matrix:\n");
    for (int i=0;i<m2;i++)
    {
        for (int j=0;j<n2;j++)
        {
            printf("%d ",arr2[i][j]);
        }printf("\n");
    }
        
    for (int i=0;i<m1;i++)
    {
        for (int j=0;j<n2;j++)
        {
            ans[i][j]=0;
        }
    }
    for (int i=0;i<m1;i++)
    {
        for (int j=0;j<n2;j++)
        {
            for(int k=0;k<n1;k++)
            {
                ans[i][j]+=arr1[i][k]*arr2[k][j];
            }
        }
    }
    printf("Resultant matrix is:\n");
        for (int i=0;i<m1;i++)
        {
            for (int j=0;j<n2;j++)
            { 
                printf("%d ",ans[i][j]);
            }
            printf("\n");
        }
    return 0;
}