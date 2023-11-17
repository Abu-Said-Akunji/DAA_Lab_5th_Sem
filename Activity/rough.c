#include <stdio.h>

#include <limits.h>

int mat_chain_multiplication(int *mat, int n)

{

    int arr[n][n];

    int i, k, row, col, len;

    for (i = 1; i < n; i++)

        arr[i][i] = 0;

    for (len = 2; len < n; len++)

    {

        for (row = 1; row <= n - len + 1; row++)

        {

            col = row + len - 1;

            arr[row][col] = INT_MAX;

            for (k = row; k <= col - 1; k++)

            {

                int tmp = arr[row][k] + arr[k + 1][col] + mat[row - 1] * mat[k] * mat[col];

                if (tmp < arr[row][col])

                    arr[row][col] = tmp;
            }
        }
    }

    return arr[1][n - 1];
}

int main()

{

    int mat[6] = {20, 30, 40, 50};

    int ans = mat_chain_multiplication(mat, 4);

    printf("%d", ans);

    return 0;
}