#include <stdio.h>

int main() {
  int rows, columns;

  printf("Enter the number of rows: ");
  scanf("%d", &rows);

  printf("Enter the number of columns: ");
  scanf("%d", &columns);

  int A[rows][columns];
  int B[rows][columns];
  int C[rows][columns];

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      printf("Enter element A[%d][%d]: ", i + 1, j + 1);
      scanf("%d", &A[i][j]);
    }
  }

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      printf("Enter element B[%d][%d]: ", i + 1, j + 1);
      scanf("%d", &B[i][j]);
    }
  }

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      C[i][j] = (A[i][j] > B[i][j]) ? A[i][j] : B[i][j];
    }
  }

  printf("Matrix A: \n");
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      printf("%d ", A[i][j]);
    }
    printf("\n");
  }

  printf("Matrix B: \n");
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      printf("%d ", B[i][j]);
    }
    printf("\n");
  }

  printf("Matrix C: \n");
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      printf("%d ", C[i][j]);
    }
    printf("\n");
  }

  return 0;
}
