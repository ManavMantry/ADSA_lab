#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXM 10  // Maximum number of constraints
#define MAXN 10  // Maximum number of variables
#define EPS 1e-9 // Tolerance for floating-point comparison

// Function prototypes
void simplex(int m, int n, double A[MAXM][MAXN], double b[MAXM], double c[MAXN]);
void pivot(int m, int n, double tableau[MAXM + 1][MAXN + MAXM + 1], int row, int col);
void printTableau(int m, int n, double tableau[MAXM + 1][MAXN + MAXM + 1], int basic[MAXM], int iter);

int main() {
    int m, n; // m = number of constraints, n = number of variables
    double A[MAXM][MAXN], b[MAXM], c[MAXN];

    printf("Enter number of constraints (m): ");
    scanf("%d", &m);
    printf("Enter number of variables (n): ");
    scanf("%d", &n);

    printf("Enter coefficients of constraints (A matrix):\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lf", &A[i][j]);
        }
    }

    printf("Enter RHS values (b vector):\n");
    for (int i = 0; i < m; i++) {
        scanf("%lf", &b[i]);
    }

    printf("Enter objective function coefficients (c vector):\n");
    for (int j = 0; j < n; j++) {
        scanf("%lf", &c[j]);
    }

    simplex(m, n, A, b, c);
    return 0;
}

// ---------------- SIMPLEX IMPLEMENTATION ------------------

void simplex(int m, int n, double A[MAXM][MAXN], double b[MAXM], double c[MAXN]) {
    double tableau[MAXM + 1][MAXN + MAXM + 1];
    int basic[MAXM];
    int rows = m + 1;
    int cols = n + m + 1;
    int iter = 0;

    // Build initial tableau
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            tableau[i][j] = A[i][j];
        for (int j = n; j < n + m; j++)
            tableau[i][j] = (i == j - n) ? 1.0 : 0.0; // Slack variables
        tableau[i][cols - 1] = b[i];
        basic[i] = n + i; // Slack variables start as basic
    }

    // Objective function row
    for (int j = 0; j < n; j++)
        tableau[m][j] = -c[j];
    for (int j = n; j < cols; j++)
        tableau[m][j] = 0.0;

    printf("\nInitial Tableau:\n");
    printTableau(m, n, tableau, basic, iter);

    // Simplex iterations
    while (1) {
        iter++;

        // Step 1: Find entering variable (most negative value in last row)
        int pivot_col = -1;
        double min_val = -EPS;
        for (int j = 0; j < cols - 1; j++) {
            if (tableau[m][j] < min_val) {
                min_val = tableau[m][j];
                pivot_col = j;
            }
        }

        if (pivot_col == -1)
            break; // Optimal solution reached

        // Step 2: Find leaving variable (minimum ratio test)
        int pivot_row = -1;
        double min_ratio = 1e9;
        for (int i = 0; i < m; i++) {
            double aij = tableau[i][pivot_col];
            if (aij > EPS) {
                double ratio = tableau[i][cols - 1] / aij;
                if (ratio < min_ratio) {
                    min_ratio = ratio;
                    pivot_row = i;
                }
            }
        }

        if (pivot_row == -1) {
            printf("\nUnbounded solution!\n");
            return;
        }

        printf("\nIteration %d: Pivot on row %d, column %d\n", iter, pivot_row + 1, pivot_col + 1);

        // Step 3: Pivot operation
        pivot(m, n, tableau, pivot_row, pivot_col);
        basic[pivot_row] = pivot_col;

        printTableau(m, n, tableau, basic, iter);
    }

    // Print optimal solution
    double x[MAXN + MAXM] = {0};
    for (int i = 0; i < m; i++) {
        if (basic[i] < n + m)
            x[basic[i]] = tableau[i][cols - 1];
    }

    printf("\n✅ Optimal solution found:\n");
    for (int j = 0; j < n; j++) {
        printf("x%d = %.3lf\n", j + 1, x[j]);
    }
    printf("Maximum Z = %.3lf\n", tableau[m][cols - 1]);
}

// Perform pivot operation to make pivot element = 1 and others = 0 in pivot column
void pivot(int m, int n, double tableau[MAXM + 1][MAXN + MAXM + 1], int row, int col) {
    int rows = m + 1;
    int cols = n + m + 1;
    double pivot_val = tableau[row][col];

    // Normalize pivot row
    for (int j = 0; j < cols; j++)
        tableau[row][j] /= pivot_val;

    // Eliminate pivot column entries in other rows
    for (int i = 0; i < rows; i++) {
        if (i == row) continue;
        double factor = tableau[i][col];
        for (int j = 0; j < cols; j++)
            tableau[i][j] -= factor * tableau[row][j];
    }
}

// Print the current tableau
void printTableau(int m, int n, double tableau[MAXM + 1][MAXN + MAXM + 1], int basic[MAXM], int iter) {
    int rows = m + 1;
    int cols = n + m + 1;

    printf("\n---------------- Tableau (Iteration %d) ----------------\n", iter);
    printf("Basic\t| ");
    for (int j = 0; j < n + m; j++)
        printf("x%-3d ", j + 1);
    printf("| RHS\n");
    printf("--------------------------------------------------------\n");

    for (int i = 0; i < m; i++) {
        printf("x%-3d\t| ", basic[i] + 1);
        for (int j = 0; j < cols; j++) {
            printf("%7.2lf ", tableau[i][j]);
        }
        printf("\n");
    }

    printf("--------------------------------------------------------\n");
    printf("Z\t| ");
    for (int j = 0; j < cols; j++) {
        printf("%7.2lf ", tableau[m][j]);
    }
    printf("\n--------------------------------------------------------\n");
}