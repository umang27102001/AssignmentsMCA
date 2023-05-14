/* Enrollment no: 22/10/JC/010
   Upload your implementation using C ( .c file ) to perform the subtraction of 2 matrices using 2D arrays (where the dimensions of the matrices and the values of the elements of the matrices are taken as input from the user). The implementation should also be able to notify the user if subtraction is not possible.
*/
#include <stdio.h>
int main() {
  int rA, cA,rB, cB, a[100][100], b[100][100], sub[100][100], i, j;
  printf("Enter the number of rows in A: ");
  scanf("%d", &rA);
  printf("Enter the number of columns in A: ");
  scanf("%d", &cA);
  printf("Enter the number of rows in B: ");
  scanf("%d", &rB);
  printf("Enter the number of columns in B: ");
  scanf("%d", &cB);
    if (rA!=rB || cA!=cB)
    {
    printf("Subtraction not possible\n");
    return 0;
    }
    
  printf("\nEnter elements of 1st matrix:\n");
  for (i = 0; i < rA; ++i)
    for (j = 0; j < cA; ++j) {
      printf("Enter element a%d%d: ", i + 1, j + 1);
      scanf("%d", &a[i][j]);
    }

  printf("Enter elements of 2nd matrix:\n");
  for (i = 0; i < rB; ++i)
    for (j = 0; j < cB; ++j) {
      printf("Enter element b%d%d: ", i + 1, j + 1);
      scanf("%d", &b[i][j]);
    }

  // subtracting two matrices
  for (i = 0; i < rA; ++i)
    for (j = 0; j < cA; ++j) {
      sub[i][j] = a[i][j] - b[i][j];
    }

  // printing the result
  printf("\subtraction of two matrices: \n");
  for (i = 0; i < rA; ++i)
    for (j = 0; j < cA; ++j) {
      printf("%d   ", sub[i][j]);
      if (j == cA - 1) {
        printf("\n\n");
      }
    }

  return 0;
}
