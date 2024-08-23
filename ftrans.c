#include<stdio.h>
#include<stdlib.h>

struct SparseMatrix{
    int rows,cols,nz;
    int* values;
    int* colPtr;
    int* rowIdx;
};

void fastTranspose(struct SparseMatrix* A, struct SparseMatrix* B){
    int numCols=A->cols;
    int numTerms=A->nz;

    int countCols[numCols];
    for(int i=0;i<numCols;i++)
    {
        countCols[i]=0;
    }
    for(int i=0;i<numTerms;i++)
    {
        countCols[A->colPtr[i]]++;
    }
    int startingPos[numCols];
    startingPos[0]=0;
    for(int i=1;i<numCols;i++)
    {
        startingPos[i]=startingPos[i-1]+countCols[i-1];
    }
    // Performing the fast transpose.
for (int i=0; i < numTerms; i++) {
int col = A->colPtr[i];
int newRow = startingPos[col];
B->rowIdx[newRow] = A->rowIdx[i];
B->values[newRow] = A->values[i];
startingPos[col]++;}
}

int main()
{
    struct SparseMatrix A;
A.rows = 4; A.cols = 4; A.nz = 5;

A.values = (int*)malloc(A.nz * sizeof(int));
A.colPtr = (int*)malloc(A.nz * sizeof(int));
A.rowIdx = (int*)malloc(A.nz * sizeof(int));
A.values[3] = 4;
A.values[2] = 3;
A.values[1] = 2;
A.values[0] = 1;
A.colPtr[3] = 3;
A.colPtr[2] = 1;
A.colPtr[1] = 1;
A.colPtr[0] = 0;
A.rowIdx[3] = 2;
A.rowIdx[2] = 2;
A.rowIdx[1] = 1;
A.rowIdx[0] = 0;

// Create a structure for the transposed matrix
struct SparseMatrix B;

B.nz = A.nz;
B.cols = A.rows;
B.rows = A.cols;

B.values = (int*)malloc(B.nz * sizeof(int));
B.colPtr = (int*)malloc(B.cols * sizeof(int));
B.rowIdx = (int*)malloc(B.nz * sizeof(int));

fastTranspose(&A, &B);

printf("Original Matrix A (%dx%d):\n", A.rows, A.cols);
for (int i = 0; i < A.nz; i++) {
printf(" (%d, %d, %d)\n", A.rowIdx[i], A.colPtr[i], A.values[i]);
}

printf("Fast Transposed Matrix B (%d x %d):\n", B.rows, B.cols);
for (int i = 0; i < B.nz; i++) {
printf(" (%d, %d, %d)\n", B.rowIdx[i], B.colPtr[i], B.values[i]);
}

}
