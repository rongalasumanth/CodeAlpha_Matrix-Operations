#include <stdio.h>

#define MAX 10

// Function to input a matrix
void inputMatrix(int matrix[MAX][MAX], int rows, int cols)
{
    int i, j;

    printf("Enter elements of the matrix:\n");
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to display a matrix
void displayMatrix(int matrix[MAX][MAX], int rows, int cols)
{
    int i, j;

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

// Matrix Addition
void addMatrix(int A[MAX][MAX], int B[MAX][MAX],
               int C[MAX][MAX], int rows, int cols)
{
    int i, j;

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

// Matrix Multiplication
void multiplyMatrix(int A[MAX][MAX], int B[MAX][MAX],
                    int C[MAX][MAX],
                    int r1, int c1, int c2)
{
    int i, j, k;

    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c2; j++)
        {
            C[i][j] = 0;

            for (k = 0; k < c1; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// Matrix Transpose
void transposeMatrix(int A[MAX][MAX], int T[MAX][MAX],
                     int rows, int cols)
{
    int i, j;

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            T[j][i] = A[i][j];
        }
    }
}

int main()
{
    int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];
    int T[MAX][MAX];
    int choice;
    int r1, c1, r2, c2;

    do
    {
        printf("\n===== MATRIX OPERATIONS =====\n");
        printf("1. Matrix Addition\n");
        printf("2. Matrix Multiplication\n");
        printf("3. Matrix Transpose\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("\nEnter rows and columns: ");
                scanf("%d %d", &r1, &c1);

                printf("\nEnter Matrix A:\n");
                inputMatrix(A, r1, c1);

                printf("\nEnter Matrix B:\n");
                inputMatrix(B, r1, c1);

                addMatrix(A, B, C, r1, c1);

                printf("\nResult of Matrix Addition:\n");
                displayMatrix(C, r1, c1);
                break;

            case 2:
                printf("\nEnter rows and columns of Matrix A: ");
                scanf("%d %d", &r1, &c1);

                printf("Enter rows and columns of Matrix B: ");
                scanf("%d %d", &r2, &c2);

                if (c1 != r2)
                {
                    printf("\nMatrix multiplication is not possible!\n");
                }
                else
                {
                    printf("\nEnter Matrix A:\n");
                    inputMatrix(A, r1, c1);

                    printf("\nEnter Matrix B:\n");
                    inputMatrix(B, r2, c2);

                    multiplyMatrix(A, B, C, r1, c1, c2);

                    printf("\nResult of Matrix Multiplication:\n");
                    displayMatrix(C, r1, c2);
                }
                break;

            case 3:
                printf("\nEnter rows and columns: ");
                scanf("%d %d", &r1, &c1);

                printf("\nEnter Matrix:\n");
                inputMatrix(A, r1, c1);

                transposeMatrix(A, T, r1, c1);

                printf("\nTranspose of Matrix:\n");
                displayMatrix(T, c1, r1);
                break;

            case 4:
                printf("\nProgram exited.\n");
                break;

            default:
                printf("\nInvalid choice!\n");
        }

    } while (choice != 4);

    return 0;
}