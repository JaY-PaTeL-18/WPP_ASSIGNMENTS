#include <stdio.h>

#define ROWS 100
#define COLS 100
int cheack_equal_matrix(int rows, int cols, int matrix1[ROWS][COLS], int matrix2[ROWS][COLS])
{
    // Compare corresponding elements of the matrices
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix1[i][j] != matrix2[i][j])
            {
                return 0; // Return false if matrices are not equal
            }
        }
    }
    return 1; // Return true if matrices are equal
}

int main()
{
    int rows, cols;

    printf("Enter rows and columns : \n");
    scanf("%d %d", &rows, &cols);

    int matrix1[ROWS][COLS], matrix2[ROWS][COLS];

    // for enter 1st metrix's element
    printf("Enter first metrix element : \n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            scanf("%d", &matrix1[i][j]);
        }
    }

    // for enter 2nd matrix's element
    printf("Enter second metrix element : \n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            scanf("%d", &matrix2[i][j]);
        }
    }

    if (cheack_equal_matrix(rows,cols,matrix1,matrix2))
    {
        printf("This matrix are equal");
    }
    else
    {
        printf("This both matrix are not equal");
    }

    return 0;
}