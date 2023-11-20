/* Write a program to read ‘n’ integers from a disc file that must contain some duplicate values
and store them into an arr_3ay. Perform the following operations on the arr_3ay.
a)Find out the total number of duplicate elements.
b)Find out the most repeating element in the arr_3ay.
*/

#include <stdio.h>

int findTotalDuplicates(int arr_3[], int n_3)
{
    int totalDuplicates_3 = 0;

    for (int i_3 = 0; i_3 < n_3; i_3++)
    {
        int count_3 = 1;
        for (int j = i_3 + 1; j < n_3; j++)
        {
            if (arr_3[i_3] == arr_3[j])
            {
                count_3++;
            }
        }
        if (count_3 > 1)
        {
            totalDuplicates_3++;
        }
    }

    return totalDuplicates_3;
}

int findMostRepeatingElement(int arr_3[], int n_3)
{
    int maxCount_3 = 0;
    int mostRepeatingElement_3 = arr_3[0];

    for (int i = 0; i < n_3; i++)
    {
        int count_3 = 1;
        for (int j = i + 1; j < n_3; j++)
        {
            if (arr_3[i] == arr_3[j])
            {
                count_3++;
            }
        }
        if (count_3 > maxCount_3)
        {
            maxCount_3 = count_3;
            mostRepeatingElement_3 = arr_3[i];
        }
    }

    return mostRepeatingElement_3;
}

int main()
{
    int n_3;

    printf("Enter how many numbers you want to read from the file: ");
    scanf("%d", &n_3);

    int arr_3[n_3];

    FILE *file_3 = fopen("q3file.txt", "r");
    if (file_3 == NULL)
    {
        printf("Error opening the file.\n");
        return 1;
    }

    printf("The content of the arr_3ay: ");
    for (int i = 0; i < n_3; i++)
    {
        fscanf(file_3, "%d", &arr_3[i]);
        printf("%d ", arr_3[i]);
    }
    printf("\n");

    fclose(file_3);

    int totalDuplicates_3 = findTotalDuplicates(arr_3, n_3);
    int mostRepeatingElement_3 = findMostRepeatingElement(arr_3, n_3);

    printf("Total number of duplicate values = %d\n", totalDuplicates_3);
    printf("The most repeating element in the arr_3ay = %d\n", mostRepeatingElement_3);

    return 0;
}