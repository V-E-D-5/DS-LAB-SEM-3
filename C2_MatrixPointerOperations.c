#include <stdio.h>
#include <stdlib.h>

int main() {
    int r1, c1, r2, c2;
    int i, j, k;

    // Read dimensions
    printf("Enter rows and columns of first matrix: ");
    scanf("%d %d", &r1, &c1);
    printf("Enter rows and columns of second matrix: ");
    scanf("%d %d", &r2, &c2);

    // Allocate memory dynamically for Matrix A
    int **A = (int **)malloc(r1 * sizeof(int *));
    for (i = 0; i < r1; i++)
        A[i] = (int *)malloc(c1 * sizeof(int));

    // Allocate memory dynamically for Matrix B
    int **B = (int **)malloc(r2 * sizeof(int *));
    for (i = 0; i < r2; i++)
        B[i] = (int *)malloc(c2 * sizeof(int));

    // Read matrix A
    printf("\nEnter elements of first matrix:\n");
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c1; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    // Read matrix B
    printf("\nEnter elements of second matrix:\n");
    for (i = 0; i < r2; i++) {
        for (j = 0; j < c2; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    // Addition
    if (r1 == r2 && c1 == c2) {
        printf("\nAddition of matrices:\n");
        for (i = 0; i < r1; i++) {
            for (j = 0; j < c1; j++) {
                printf("%d ", A[i][j] + B[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("\nAddition not possible (dimensions mismatch)\n");
    }

    // Multiplication
    if (c1 == r2) {
        int **C = (int **)malloc(r1 * sizeof(int *));
        for (i = 0; i < r1; i++)
            C[i] = (int *)malloc(c2 * sizeof(int));

        printf("\nMultiplication of matrices:\n");
        for (i = 0; i < r1; i++) {
            for (j = 0; j < c2; j++) {
                C[i][j] = 0;
                for (k = 0; k < c1; k++) {
                    C[i][j] += A[i][k] * B[k][j];
                }
                printf("%d ", C[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("\nMultiplication not possible (c1 != r2)\n");
    }

    return 0;
}