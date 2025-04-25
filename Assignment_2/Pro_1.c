/*  Write a C program to multiply two matrices using dynamic memory allocation. Each
    two-dimensional array should be processed as array of pointers to a set of 1-
    dimensional integer arrays. Read, access and display the matrix elements using pointers
    instead of subscript notation. Use three functions
    i) To read input matrix 
    ii) To compute the product and 
    iii) To display the resultant matrix.   */

#include<stdio.h>
#include<stdlib.h>

void entering_values(int** m, int row, int col) {
    printf("Enter values in matrix:\n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            scanf("%d", &m[i][j]);
        }
    }
}

void display(int** m, int row, int col) {
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}

int** multiplication_of_matrix(int** m1, int** m2, int row1, int common, int col2) {
    int** m = (int**)malloc(sizeof(int*)*row1);
    for (int i = 0; i < row1; i++) m[i] = (int*)malloc(sizeof(int)*col2);

    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col2; j++)
        {
            for (int k = 0; k < common; k++)
            {
                m[i][j] += m1[i][k]*m2[k][j];
            }
        }
    }
    return m;
}

int main() {
    int row1, row2, col1, col2;
    printf("Enter the value of row1, col1, row2 and col2 respectively: ");
    scanf("%d %d %d %d", &row1, &col1, &row2, &col2);

    // checking multiplication possible or not
    if (col1!=row2)
    {
        printf("Multiplication is not possible\n");
        exit(0);
    }

    // Creating Matrix
    int** m1 = (int**)malloc(sizeof(int*)*row1);
    int** m2 = (int**)malloc(sizeof(int*)*row2);
    for (int i = 0; i < row1; i++) m1[i] = (int*)malloc(sizeof(int)*col1);
    for (int i = 0; i < row2; i++) m2[i] = (int*)malloc(sizeof(int)*col2);

    // Taking values to matrix
    entering_values(m1, row1, col1);
    printf("\n");
    entering_values(m2, row2, col2);
    printf("\n");

    int** m = multiplication_of_matrix(m1, m2, row1, col1, col2);
    display(m, row1, col2);

    

    return 0;
}    