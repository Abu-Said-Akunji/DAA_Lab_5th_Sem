#include <stdio.h>
#include <limits.h>

void printOptimalParentheses(int S_3[100][100], int i, int j)
{
    if (i == j)
    {
        printf("A%d", i);
    }
    else
    {
        printf("(");
        printOptimalParentheses(S_3, i, S_3[i][j]);
        printOptimalParentheses(S_3, S_3[i][j] + 1, j);
        printf(")");
    }
}

int matrixChainMultiplication(int dimensions_3[], int n, int M_3[100][100], int S_3[100][100])
{
    for (int i = 1; i <= n; i++)
    {
        M_3[i][i] = 0;
    }

    for (int chainLen_3 = 2; chainLen_3 <= n; chainLen_3++)
    {
        for (int i = 1; i <= n - chainLen_3 + 1; i++)
        {
            int j = i + chainLen_3 - 1;
            M_3[i][j] = INT_MAX;

            for (int k = i; k < j; k++)
            {
                int cost_3 = M_3[i][k] + M_3[k + 1][j] + dimensions_3[i - 1] * dimensions_3[k] * dimensions_3[j];
                if (cost_3 < M_3[i][j])
                {
                    M_3[i][j] = cost_3;
                    S_3[i][j] = k;
                }
            }
        }
    }

    return M_3[1][n];
}

void printTable(int table_3[100][100], int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            printf("%d\t", table_3[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main()
{
    int n;
    printf("Enter the number of matrices: ");
    scanf("%d", &n);

    int dimensions_3[100];
    for (int i = 0; i < n; i++)
    {
        printf("Enter the row and col size of A%d: ", i + 1);
        scanf("%d %d", &dimensions_3[i], &dimensions_3[i + 1]);
    }

    int M_3[100][100];
    int S_3[100][100];

    int minScalarMultiplications_3 = matrixChainMultiplication(dimensions_3, n, M_3, S_3);

    printf("Table M:\n");
    printTable(M_3, n);

    printf("Table S:\n");
    printTable(S_3, n);

    printf("Optimal Parenthesization: ");
    printOptimalParentheses(S_3, 1, n);
    printf("\n");
    printf("Minimum scalar multiplications: %d\n\n", minScalarMultiplications_3);
    return 0;
}
