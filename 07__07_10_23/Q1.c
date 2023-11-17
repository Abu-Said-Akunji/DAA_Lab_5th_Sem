#include <stdio.h>
#include <limits.h>

void printOptimalParenthesization(int i, int j, int **S) {
    if (i == j) {
        printf("A%d", i);
    } else {
        printf("(");
        printOptimalParenthesization(i, S[i][j], S);
        printOptimalParenthesization(S[i][j] + 1, j, S);
        printf(")");
    }
}

int matrixChainOrder(int dims[], int n) {
    int M[n][n]; // M-table
    int S[n][n]; // S-table
    int i, j, k, L, q;

    for (i = 1; i < n; i++) {
        M[i][i] = 0;
    }

    for (L = 2; L < n; L++) {
        for (i = 1; i < n - L + 1; i++) {
            j = i + L - 1;
            M[i][j] = INT_MAX;
            for (k = i; k <= j - 1; k++) {
                q = M[i][k] + M[k + 1][j] + dims[i - 1] * dims[k] * dims[j];
                if (q < M[i][j]) {
                    M[i][j] = q;
                    S[i][j] = k;
                }
            }
        }
    }

    printf("Number of scalar multiplications: %d\n", M[1][n - 1]);
    printf("Optimal Parenthesization: ");
    printOptimalParenthesization(1, n - 1, S);
    printf("\n");

    return M[1][n - 1];
}

int main() {
    int n;
    printf("Enter number of matrices: ");
    scanf("%d", &n);
    int dims[n + 1]; // Dimensions of the matrices

    for (int i = 0; i < n; i++) {
        printf("Enter row and col size of A%d: ", i + 1);
        scanf("%d %d", &dims[i], &dims[i + 1]);
    }

    int minScalarMult = matrixChainOrder(dims, n + 1);

    return 0;
}
