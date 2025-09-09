#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define AIDX(A,n,i,j) (A[(i)*(n) + (j)])
#define EPS 1e-12

// Swap two rows of matrix A
static void swap_rows(double *A, int n, int r1, int r2) {
    for (int j = 0; j < n; ++j) {
        double tmp = AIDX(A,n,r1,j);
        AIDX(A,n,r1,j) = AIDX(A,n,r2,j);
        AIDX(A,n,r2,j) = tmp;
    }
}

// Perform LUP decomposition: P*A = L*U
int lup_decompose(double *A, int n, int *P) {
    for (int i = 0; i < n; ++i) P[i] = i;

    for (int k = 0; k < n; ++k) {
        // Find pivot
        int piv = k;
        double piv_val = fabs(AIDX(A,n,k,k));
        for (int i = k + 1; i < n; ++i) {
            double val = fabs(AIDX(A,n,i,k));
            if (val > piv_val) { piv = i; piv_val = val; }
        }
        if (piv_val < EPS) return 0;  // singular matrix

        // Swap rows if needed
        if (piv != k) {
            swap_rows(A, n, piv, k);
            int t = P[piv]; P[piv] = P[k]; P[k] = t;
        }

        // Elimination
        for (int i = k + 1; i < n; ++i) {
            AIDX(A,n,i,k) /= AIDX(A,n,k,k);
            for (int j = k + 1; j < n; ++j) {
                AIDX(A,n,i,j) -= AIDX(A,n,i,k) * AIDX(A,n,k,j);
            }
        }
    }
    return 1;
}

int main(void) {
    int n;
    printf("Enter the dimension n of the square matrix A: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        fprintf(stderr, "Invalid dimension.\n");
        return 1;
    }

    double *A = malloc(n * n * sizeof(double));
    int *P = malloc(n * sizeof(int));
    if (!A || !P) {
        fprintf(stderr, "Memory allocation failed.\n");
        return 1;
    }

    printf("Enter the %d x %d matrix A row by row:\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (scanf("%lf", &AIDX(A,n,i,j)) != 1) {
                fprintf(stderr, "Invalid matrix entry.\n");
                free(A); free(P);
                return 1;
            }
        }
    }

    printf("\nPerforming LUP decomposition...\n");
    if (!lup_decompose(A, n, P)) {
        printf("Matrix is singular or ill-conditioned.\n");
        free(A); free(P);
        return 1;
    }

    // Print L
    printf("\nL matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i > j) printf("%.6lf ", AIDX(A,n,i,j));
            else if (i == j) printf("1.000000 ");
            else printf("0.000000 ");
        }
        printf("\n");
    }

    // Print U
    printf("\nU matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i <= j) printf("%.6lf ", AIDX(A,n,i,j));
            else printf("0.000000 ");
        }
        printf("\n");
    }

    // Print P
    printf("\nPermutation vector P:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", P[i]);
    }
    printf("\n");

    free(A);
    free(P);
    return 0;
}
