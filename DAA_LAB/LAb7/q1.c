#include <stdio.h>

void printOptimalParentheses(int S[100][100], int i, int j) {
    if (i == j) {
        printf("A%d", i);
    } else {
        printf("(");
        printOptimalParentheses(S, i, S[i][j]);
        printOptimalParentheses(S, S[i][j] + 1, j);
        printf(")");
    }
}

int matrixChainMultiplication(int dimensions[], int n) {
    int M[100][100];
    int S[100][100];

    for (int i = 1; i <= n; i++) {
        M[i][i] = 0;
    }

    for (int chainLen = 2; chainLen <= n; chainLen++) {
        for (int i = 1; i <= n - chainLen + 1; i++) {
            int j = i + chainLen - 1;
            M[i][j] = __INT_MAX__;

            for (int k = i; k < j; k++) {
                int cost = M[i][k] + M[k + 1][j] + dimensions[i - 1] * dimensions[k] * dimensions[j];
                if (cost < M[i][j]) {
                    M[i][j] = cost;
                    S[i][j] = k;
                }
            }
        }
    }

    printf("Optimal Parenthesization: ");
    printOptimalParentheses(S, 1, n);
    printf("\n");

    return M[1][n];
}

int main() {
    int n;
    printf("Enter the number of matrices: ");
    scanf("%d", &n);

    int dimensions[100];
    printf("Enter the dimensions of the matrices: ");
    for (int i = 0; i <= n; i++) {
        scanf("%d", &dimensions[i]);
    }

    int minScalarMultiplications = matrixChainMultiplication(dimensions, n);
    printf("Minimum scalar multiplications: %d\n", minScalarMultiplications);

    return 0;
}
