/*WAP that reads two matrices A (m x n) and B (p x q) and computes the
product A and B. Read matrix A and matrix B in row major order respectively. 
Print both the input matrices and resultant matrix with suitable headings and
output should be in matrix format only. Program must check the compatibility
of orders of the matrices for multiplication. Report appropriate message in
case of incompatibility*/
#include<stdio.h>

int main()
{
    int m,p,n,q;
    printf("Enter the no.of rows for first matrix:");
    scanf("%d", &m);
    printf("Enter the no.of columns for first matrix:");
    scanf("%d", &n);
    printf("Enter the no.of rows for second matrix:");
    scanf("%d", &p);
    printf("Enter the no.of columns for second matrix:");
    scanf("%d", &q);
    if (p != n) 
    {
        printf("Invalid input. Matrix multiplication not possible!\n");
        return 1; 
    }

    int arr1[m][n],arr2[p][q],ans[m][p];
    for (int i=0;i<m;i++)
    {
        for (int j=0;j<n;j++)
        {
            printf("Enter the elements of first matrix:");
            scanf("%d",&arr1[i][j]);
        }
    }

    for (int i=0;i<p;i++)
    {
        for (int j=0;j<q;j++)
        {
            printf("Enter the elements of second matrix:");
            scanf("%d",&arr2[i][j]);
        }
    }
    printf("First matrix:\n");
    for (int i=0;i<m;i++)
    {
        for (int j=0;j<n;j++)
        {
            printf("%d ",arr1[i][j]);
        }printf("\n");
    }
    printf("Second matrix:\n");
    for (int i=0;i<p;i++)
    {
        for (int j=0;j<q;j++)
        {
            printf("%d ",arr2[i][j]);
        }printf("\n");
    }
        
    for (int i=0;i<m;i++)
    {
        for (int j=0;j<q;j++)
        {
            ans[i][j]=0;
        }
    }
    for (int i=0;i<m;i++)
    {
        for (int j=0;j<q;j++)
        {
            for(int k=0;k<n;k++)
            {
                ans[i][j]+=arr1[i][k]*arr2[k][j];
            }
        }
    }
    printf("Resultant matrix is:\n");
        for (int i=0;i<m;i++)
        {
            for (int j=0;j<q;j++)
            { 
                printf("%d ",ans[i][j]);
            }
            printf("\n");
        }
    return 0;
}