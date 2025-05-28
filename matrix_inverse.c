#include <stdio.h>

int determinant(int n, int matrix[n][n]);
void getCofactor(int n, int matrix[n][n], int temp[n][n], int row, int col);
void adjugateMatrix(int n, int matrix[n][n], int adj[n][n]);
void inverseMatrix(int n, int matrix[n][n]);

int main() 
{
    int m, n;
    printf("Enter the number of rows: ");
    scanf("%d", &m);
    printf("Enter the number of columns: ");
    scanf("%d", &n);

    if (m != n) 
    {
        printf("Determinant and inverse can only be calculated for a square matrix.\n");
        return 0;
    }

    int matrix[m][n];
    for (int i = 0; i < m; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            printf("Enter the element at [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("Matrix is:\n");
    for (int i = 0; i < m; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    int det = determinant(m, matrix);
    printf("The determinant of the matrix is: %d\n", det);

    if (det == 0) 
    {
        printf("Matrix does not have an inverse.\n");
    } else 
    {
        inverseMatrix(m, matrix);
    }
    return 0;
}

int determinant(int n, int matrix[n][n]) 
{
    if (n == 1) 
    {
        return matrix[0][0];
    }
    if (n == 2) 
    {
        return (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);
    }

    int det = 0;
    int temp[n - 1][n - 1]; // Submatrix for minors
    for (int p = 0; p < n; p++) 
    {
        int subi = 0;
        for (int i = 1; i < n; i++) 
        {
            int subj = 0;
            for (int j = 0; j < n; j++) 
            {
                if (j == p) continue;
                temp[subi][subj] = matrix[i][j];
                subj++;
            }
            subi++;
        }
        int cofactor = matrix[0][p] * determinant(n - 1, temp);
        det += (p % 2 == 0 ? cofactor : -cofactor);
    }
    return det;
}

void getCofactor(int n, int matrix[n][n], int temp[n][n], int row, int col) 
{
    int subi = 0;
    for (int i = 0; i < n; i++) 
    {
        if (i == row) continue;
        int subj = 0;
        for (int j = 0; j < n; j++) 
        {
            if (j == col) continue;
            temp[subi][subj] = matrix[i][j];
            subj++;
        }
        subi++;
    }
}

void adjugateMatrix(int n, int matrix[n][n], int adj[n][n]) 
{
    int temp[n][n];
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            getCofactor(n, matrix, temp, i, j);
            int cofactor = determinant(n - 1, temp);
            adj[j][i] = ((i + j) % 2 == 0 ? cofactor : -cofactor);
        }
    }
}

void inverseMatrix(int n, int matrix[n][n]) 
{
    int det = determinant(n, matrix);
    int adj[n][n];
    adjugateMatrix(n, matrix, adj);

    printf("Inverse of the matrix is:\n");
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            printf("%.2f ", (float)adj[i][j] / det);
        }
        printf("\n");
    }
}
