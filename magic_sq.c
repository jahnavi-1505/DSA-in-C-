#include <stdio.h>

// Function to read a matrix
void readMatrix(int mat[][100], int rows, int cols) {
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
}

// Function to multiply two matrices
void multiplyMatrices(int matA[][100], int matB[][100], int result[][100], int rowsA, int colsA, int colsB) {
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            result[i][j] = 0;
            for (int k = 0; k < colsA; k++) {
                result[i][j] += matA[i][k] * matB[k][j];
            }
        }
    }
}

// Function to add two matrices
void addMatrices(int matA[][100], int matB[][100], int result[][100], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matA[i][j] + matB[i][j];
        }
    }
}

// Function to check if a square matrix is a magic square
int isMagicSquare(int mat[][100], int n) {
    int sum = 0;

    // Calculate the sum of the first row
    for (int j = 0; j < n; j++) {
        sum += mat[0][j];
    }

    // Check the sum of each row, column, and diagonal
    for (int i = 0; i < n; i++) {
        int rowSum = 0, colSum = 0;
        for (int j = 0; j < n; j++) {
            rowSum += mat[i][j];
            colSum += mat[j][i];
        }
        if (rowSum != sum || colSum != sum) {
            return 0; // Not a magic square
        }
    }

    return 1; // It's a magic square
}

int main() {
    int matA[100][100], matB[100][100], result[100][100];
    int rowsA, colsA, rowsB, colsB;

    // Read dimensions of matrices A and B
    printf("Enter the number of rows and columns of matrix A: ");
    scanf("%d %d", &rowsA, &colsA);

    printf("Enter the number of rows and columns of matrix B: ");
    scanf("%d %d", &rowsB, &colsB);

    if (colsA != rowsB) {
        printf("Matrix multiplication is not possible.\n");
        return 1;
    }

    // Read matrices A and B
    readMatrix(matA, rowsA, colsA);
    readMatrix(matB, rowsB, colsB);

    // Perform matrix multiplication and addition
    multiplyMatrices(matA, matB, result, rowsA, colsA, colsB);
    addMatrices(matA, matB, result, rowsA, colsA);

    // Display the results
    printf("Matrix A:\n");
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsA; j++) {
            printf("%d ", matA[i][j]);
        }
        printf("\n");
    }

    printf("Matrix B:\n");
    for (int i = 0; i < rowsB; i++) {
        for (int j = 0; j < colsB; j++) {
            printf("%d ", matB[i][j]);
        }
        printf("\n");
    }

    printf("Matrix Multiplication:\n");
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    // Check if the matrix is a magic square
    int n;
    printf("Enter the size of the square matrix: ");
    scanf("%d", &n);

    int magicSquare[100][100];
    readMatrix(magicSquare, n, n);

    if (isMagicSquare(magicSquare, n)) {
        printf("The entered matrix is a magic square.\n");
    } else {
        printf("The entered matrix is not a magic square.\n");
    }

    return 0;
}
