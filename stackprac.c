#include <stdio.h>
#include <stdlib.h>

// Define a structure to represent a non-zero element
struct element {
  int row; // Row index of the element
  int col; // Column index of the element
  int val; // Value of the element
};

// Define a structure to represent a sparse matrix
struct sparse {
  int m; // Number of rows in the matrix
  int n; // Number of columns in the matrix
  int num; // Number of non-zero elements in the matrix
  struct element *e; // Array of non-zero elements
};

// Function to create a sparse matrix from user input
struct sparse * create() {
  struct sparse *s;
  int i, m, n, num;
  printf("Enter the dimensions of the matrix: ");
  scanf("%d%d", &m, &n);
  printf("Enter the number of non-zero elements: ");
  scanf("%d", &num);

  // Allocate memory for the sparse matrix
  s = (struct sparse *)malloc(sizeof(struct sparse));
  s->m = m;
  s->n = n;
  s->num = num;
  s->e = (struct element *)malloc(num * sizeof(struct element));

  // Read the non-zero elements from the user
  printf("Enter the non-zero elements in row, column, value format:\n");
  for (i = 0; i < num; i++) {
    scanf("%d%d%d", &s->e[i].row, &s->e[i].col, &s->e[i].val);
  }
  return s;
}

// Function to display a sparse matrix
void display(struct sparse *s) {
  int i, j, k;
  k = 0; // Index for the array of non-zero elements
  for (i = 0; i < s->m; i++) {
    for (j = 0; j < s->n; j++) {
      if (k < s->num && i == s->e[k].row && j == s->e[k].col) {
        // Print the non-zero element at the current position
        printf("%d ", s->e[k++].val);
      } else {
        // Print zero for the empty position
        printf("0 ");
      }
    }
    printf("\n");
  }
}

// Function to find the fast transpose of a sparse matrix
struct sparse * fast_transpose(struct sparse *s) {
  struct sparse *t;
  int *row_terms, *start_pos;
  int i, j;

  // Allocate memory for the transpose matrix
  t = (struct sparse *)malloc(sizeof(struct sparse));
  t->m = s->n;
  t->n = s->m;
  t->num = s->num;
  t->e = (struct element *)malloc(t->num * sizeof(struct element));

  // Allocate memory for the arrays to store row terms and start positions
  row_terms = (int *)malloc(t->m * sizeof(int));
  start_pos = (int *)malloc(t->m * sizeof(int));

  // Initialize the row terms array to zero
  for (i = 0; i < t->m; i++) {
    row_terms[i] = 0;

// Count the number of non-zero elements in each row of the transpose matrix
for (i = 0; i < s->num; i++) {
    row_terms[s->e[i].col]++;
}

// Calculate the start positions of each row in the transpose matrix
start_pos[0] = 0;
for (i = 1; i < t->m; i++) {
    start_pos[i] = start_pos[i -1] + row_terms[i -1];
}

// Copy the non-zero elements from the original matrix to the transpose matrix
for (i = 0; i < s->num; i++) {
    j = start_pos[s->e[i].col]++;
    t->e[j].row = s->e[i].col;
    t->e[j].col = s->e[i].row;
    t->e[j].val = s->e[i].val;
}

// Free the memory allocated for the arrays
free(row_terms);
free(start_pos);

return t;
}

// Main function to test the program
int main() {
    struct sparse *s, *t;

    // Create a sparse matrix from user input
    printf("Enter the original matrix:\n");
    s = create();

    // Display the original matrix
    printf("The original matrix is:\n");
    display(s);

    // Find and display the fast transpose of the matrix
    printf("The fast transpose of the matrix is:\n");
    t = fast_transpose(s);
    display(t);

    // Free the memory allocated for the matrices
    free(s->e);
    free(s);
    free(t->e);
    free(t);

    return 0;
}}
