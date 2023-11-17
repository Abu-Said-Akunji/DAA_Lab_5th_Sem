#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

// Function to find the longest common subsequence and its length
void findLCS(char *str1, char *str2)
{
    int m = strlen(str1);
    int n = strlen(str2);

    int LCSLength[m + 1][n + 1];

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                LCSLength[i][j] = 0;
            else if (str1[i - 1] == str2[j - 1])
                LCSLength[i][j] = LCSLength[i - 1][j - 1] + 1;
            else
                LCSLength[i][j] = LCSLength[i - 1][j] > LCSLength[i][j - 1] ? LCSLength[i - 1][j] : LCSLength[i][j - 1];
        }
    }

    int index = LCSLength[m][n];
    char lcs[index + 1];
    lcs[index] = '\0';

    int i = m, j = n;
    while (i > 0 && j > 0)
    {
        if (str1[i - 1] == str2[j - 1])
        {
            lcs[index - 1] = str1[i - 1];
            i--;
            j--;
            index--;
        }
        else if (LCSLength[i - 1][j] > LCSLength[i][j - 1])
            i--;
        else
            j--;
    }

    printf("LCS: %s\n", lcs);
    printf("LCS Length: %d\n", LCSLength[m][n]);
}

int main()
{
    char str1[MAX_LENGTH], str2[MAX_LENGTH];

    printf("Enter the first string into an array: ");
    scanf("%s", str1);

    printf("Enter the second string into an array: ");
    scanf("%s", str2);

    findLCS(str1, str2);

    return 0;
}