#include<stdio.h>
int m1,m2,n1,n2;
int add();
int subtract();
int multiply();
int divide();
int inverse();
int transpose();
int determinant();
int main()
{
    int choice;
    printf("Enter the no.of rows for first matrix:");
    scanf("%d", &m1);
    printf("Enter the no.of columns for first matrix:");
    scanf("%d", &n1);
    int matrix[m1][n1];
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < m1; i++) 
    {
        for (int j = 0; j < n1; j++) 
        {
            scanf("%d", &matrix[i][j]);
        }
    }
    printf("Enter the choice of operation you want to do with the matrices:\n1. Add\n2. Subtract\n3. Multiply\n4.Divide\n5. Inverse\n6. Transpose\n7. Determinant");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        add();
        break;
    case 2:
        subtrct();
        break;
    case 3:
        multiply();
        break;
    case 4:
        divide();
        break;
    case 5:
        inverse();
        break;
    case 6:
        int matrix[m1][n1];
        transpose(m1, n1, matrix);
        break;
    case 7:
        if (m1 == n1) 
        {
            int det = determinant(m1, matrix);
            printf("The determinant of the matrix is: %d\n", det);
        } 
        else
        printf("Determinant can only be calculated for a square matrix.\n");
        break;
    default:
        printf("Invalid option, please try again.");
        break;
    }
    return 0;
}
int add()
{
    printf("Enter the no.of rows for second matrix:");
    scanf("%d", &m2);
    printf("Enter the no.of columns for second matrix:");
    scanf("%d", &n2);
}
int subtract()
{
    printf("Enter the no.of rows for second matrix:");
    scanf("%d", &m2);
    printf("Enter the no.of columns for second matrix:");
    scanf("%d", &n2);
}
int multiply()
{
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
}
int divide()
{
    printf("Enter the no.of rows for second matrix:");
    scanf("%d", &m2);
    printf("Enter the no.of columns for second matrix:");
    scanf("%d", &n2);
}
int inverse()
{

}
int transpose(int m, int n, int matrix[m][n]) 
{
    printf("Transpose matrix is:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", matrix[j][i]);
        }
        printf("\n");
    }
    return 0;
}
// Function to calculate the determinant of a matrix recursively
int determinant(int n, int matrix[n][n]) 
{
    if (n == 1) 
    {
        // Base case for a 1x1 matrix
        return matrix[0][0];
    }
    if (n == 2) 
    {
        // Base case for a 2x2 matrix
        return (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);
    }
    int det = 0;
    int temp[n - 1][n - 1]; // Submatrix for minors
    for (int p = 0; p < n; p++) 
    {
        // Form the submatrix by excluding the first row and the current column `p`
        int subi = 0; // Row index for the submatrix
        for (int i = 1; i < n; i++) 
        {
            int subj = 0; // Column index for the submatrix
            for (int j = 0; j < n; j++) 
            {
                if (j == p) continue; // Skip the current column
                temp[subi][subj] = matrix[i][j];
                subj++;
            }
            subi++;
        }
        // Calculate the cofactor and add to the determinant
        int cofactor = matrix[0][p] * determinant(n - 1, temp);
        det += (p % 2 == 0 ? cofactor : -cofactor); // Alternate signs
    }
    return det;
}