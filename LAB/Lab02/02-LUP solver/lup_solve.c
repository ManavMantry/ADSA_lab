#include <stdio.h>

#define MAXN 20   // Maximum matrix size

// Forward substitution: solve L*y = Pb
void forward_substitution(double L[MAXN][MAXN], double b[MAXN], double y[MAXN], int P[MAXN], int n) {
    for (int i = 0; i < n; i++) {
        y[i] = b[P[i]];
        for (int j = 0; j < i; j++) {
            y[i] -= L[i][j] * y[j];
        }
    }
}

// Backward substitution: solve U*x = y
void backward_substitution(double U[MAXN][MAXN], double y[MAXN], double x[MAXN], int n) {
    for (int i = n - 1; i >= 0; i--) {
        x[i] = y[i];
        for (int j = i + 1; j < n; j++) {
            x[i] -= U[i][j] * x[j];
        }
        x[i] /= U[i][i];
    }
}

int main(void) {
    int n;
    double L[MAXN][MAXN], U[MAXN][MAXN];
    int P[MAXN];
    double b[MAXN], y[MAXN], x[MAXN];

    printf("Enter dimension n of the system (<= %d): ", MAXN);
    if (scanf("%d", &n) != 1 || n <= 0 || n > MAXN) {
        printf("Invalid dimension.\n");
        return 1;
    }

    // Input for L
    printf("Enter the strictly lower triangular entries of L (n=%d):\n", n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i > j) {
                printf("L[%d][%d] = ", i, j);
                scanf("%lf", &L[i][j]);
            } else if (i == j) {
                L[i][j] = 1.0;   // diagonal fixed to 1
            } else {
                L[i][j] = 0.0;   // upper part is zero
            }
        }
    }

    // Input for U
    printf("Enter the upper triangular entries of U (including diagonal):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i <= j) {
                printf("U[%d][%d] = ", i, j);
                scanf("%lf", &U[i][j]);
            } else {
                U[i][j] = 0.0;   // lower part is zero
            }
        }
    }

    // Input for permutation vector
    printf("Enter permutation vector P (length %d):\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &P[i]);
    }

    // Input for right-hand side b
    printf("Enter right-hand side vector b (length %d):\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%lf", &b[i]);
    }

    // Solve
    forward_substitution(L, b, y, P, n);
    backward_substitution(U, y, x, n);

    printf("\nSolution vector x:\n");
    for (int i = 0; i < n; i++) {
        printf("%.6lf ", x[i]);
    }
    printf("\n");

    return 0;
}
