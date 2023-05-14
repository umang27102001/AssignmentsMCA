/* Enrollment no: 22/10/JC/010
   Complex matrix.
*/
#include <stdio.h>
#include <stdlib.h>
struct complex {
    int real;
    int img;
};
struct complex **create_matrix(int n) {
    int i;
    struct complex **matrix = (struct complex **) malloc(n * sizeof(struct complex *));
    for (i = 0; i < n; i++) {
        matrix[i] = (struct complex *) malloc(n * sizeof(struct complex));
    }
    return matrix;
}
void free_matrix(struct complex **matrix, int n) {
    int i;
    for (i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);
}
struct complex **multiply_matrices(struct complex **A, struct complex **B, int n) {
    int i, j, k;
    int real, img;
    int additions = 0, multiplications = 0;
    struct complex **result = create_matrix(n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            real = img = 0;
            for (k = 0; k < n; k++) {
                real += A[i][k].real * B[k][j].real - A[i][k].img * B[k][j].img;
                img += A[i][k].real * B[k][j].img + A[i][k].img * B[k][j].real;
                additions += 2;
                multiplications += 4;
            }
            result[i][j].real = real;
            result[i][j].img = img;
        }
    }
    printf("Number of additions: %d\n", additions);
    printf("Number of multiplications: %d\n", multiplications);
    return result;
}
int main() {
    int n;
    struct complex **A, **B, **C;
    printf("Enter the size of matrices: ");
    scanf("%d", &n);
    A = create_matrix(n);
    B = create_matrix(n);
    C = multiply_matrices(A, B, n); 
    free_matrix(A, n);
    free_matrix(B, n);
    free_matrix(C, n);
    return 0;
}