#include <stdio.h>
#include <string.h>

// Function to find the Longest Common Subsequence
void findLCS(char *X_3, char *Y_3, int m, int n)
{
    int L_3[m + 1][n + 1];

    // Build the LCS table
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
            {
                L_3[i][j] = 0;
            }
            else if (X_3[i - 1] == Y_3[j - 1])
            {
                L_3[i][j] = L_3[i - 1][j - 1] + 1;
            }
            else
            {
                L_3[i][j] = (L_3[i - 1][j] > L_3[i][j - 1]) ? L_3[i - 1][j] : L_3[i][j - 1];
            }
        }
    }

    // Length of LCS
    int lcsLength_3 = L_3[m][n];
    printf("Length of Longest Common Subsequence: %d\n", lcsLength_3);

    // Print the LCS
    char lcs_3[lcsLength_3 + 1];
    lcs_3[lcsLength_3] = '\0';

    int i = m, j = n;
    while (i > 0 && j > 0)
    {
        if (X_3[i - 1] == Y_3[j - 1])
        {
            lcs_3[lcsLength_3 - 1] = X_3[i - 1];
            i--;
            j--;
            lcsLength_3--;
        }
        else if (L_3[i - 1][j] > L_3[i][j - 1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }

    printf("Longest Common Subsequence: %s\n", lcs_3);
}

int main()
{
    char X_3[100], Y_3[100];
    printf("Enter the first string: ");
    gets(X_3);
    printf("Enter the second string: ");
    gets(Y_3);

    int m = strlen(X_3);
    int n = strlen(Y_3);

    findLCS(X_3, Y_3, m, n);

    return 0;
}
