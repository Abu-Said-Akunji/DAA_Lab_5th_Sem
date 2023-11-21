#include <stdio.h>
#include <string.h>

// Function to find the Longest Common Subsequence
void findLCS(char* X, char* Y, int m, int n) {
    int L[m + 1][n + 1];

    // Build the LCS table
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                L[i][j] = 0;
            } else if (X[i - 1] == Y[j - 1]) {
                L[i][j] = L[i - 1][j - 1] + 1;
            } else {
                L[i][j] = (L[i - 1][j] > L[i][j - 1]) ? L[i - 1][j] : L[i][j - 1];
            }
        }
    }

    // Length of LCS
    int lcsLength = L[m][n];
    printf("Length of Longest Common Subsequence: %d\n", lcsLength);

    // Print the LCS
    char lcs[lcsLength + 1];
    lcs[lcsLength] = '\0';

    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcs[lcsLength - 1] = X[i - 1];
            i--;
            j--;
            lcsLength--;
        } else if (L[i - 1][j] > L[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    printf("Longest Common Subsequence: %s\n", lcs);
}

int main() {
    char X[100], Y[100];
    printf("Enter the first string: ");
    gets(X);
    printf("Enter the second string: ");
    gets(Y);

    int m = strlen(X);
    int n = strlen(Y);

    findLCS(X, Y, m, n);

    return 0;
}

