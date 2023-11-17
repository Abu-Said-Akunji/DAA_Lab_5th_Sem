// Write a menu driven program to sort a list of elements in ascending
// order using Insertion Sort technique. The nature of the input data is choice based and a distinct
// file is considered for each choice. The sorted elements can be stored in a separate output file.
// After sorting display the content of the output file along with number of comparisons. Based on
// the number of comparisons, conclude the input scenario is either best or worst case.

#include <stdio.h>
#include <string.h>
// Function to perform Insertion Sort and count comparisons
int insertionSort(int arr[], int n)
{
    int comparisons = 0;
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
            comparisons++;
        }
        arr[j + 1] = key;
    }
    return comparisons;
}

// Function to read elements from file and return the number of elements read
int readFromFile(char fileName[], int arr[])
{
    FILE *file = fopen(fileName, "r");
    if (file == NULL)
    {
        printf("Unable to open file '%s'.\n", fileName);
        return 0;
    }

    int n;
    fscanf(file, "%d", &n);
    for (int i = 0; i < n; i++)
    {
        fscanf(file, "%d", &arr[i]);
    }

    fclose(file);
    return n;
}

// Function to write elements to file
void writeToFile(char fileName[], int arr[], int n)
{
    FILE *file = fopen(fileName, "w");
    if (file == NULL)
    {
        printf("Unable to open file '%s'.\n", fileName);
        return;
    }

    fprintf(file, "%d\n", n);
    for (int i = 0; i < n; i++)
    {
        fprintf(file, "%d ", arr[i]);
    }

    fclose(file);
}

int main()
{
    int choice;
    printf("MAIN MENU (INSERTION SORT)\n");
    printf("1. Ascending Data\n");
    printf("2. Descending Data\n");
    printf("3. EXIT\n");
    printf("Enter option: ");
    scanf("%d", &choice);

    int arr[500]; // Assuming maximum number of elements in the input file is 500
    int n = 0;    // Number of elements read from the file

    char inputFile[20];
    char outputFile[20];

    switch (choice)
    {
    case 1:
        strcpy(inputFile, "input.dat");
        strcpy(outputFile, "output.dat");
        break;
    case 2:
        strcpy(inputFile, "input.dat");
        strcpy(outputFile, "output.dat");
        break;
    case 3:
        printf("Exiting the program.\n");
        return 0;
    default:
        printf("Invalid option. Exiting the program.\n");
        return 1;
    }

    n = readFromFile(inputFile, arr);

    if (n == 0)
    {
        printf("No data read from the input file.\n");
        return 1;
    }

    int comparisons = insertionSort(arr, n);
    writeToFile(outputFile, arr, n);

    printf("Before Sorting: Content of the input file\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\nAfter Sorting: Content of the output file\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\nNumber of Comparisons: %d\n", comparisons);

    // Determine the actual scenario based on the number of comparisons
    if (comparisons == (n - 1) * n / 2)
    {
        printf("Actual Scenario: Best-case\n");
    }
    else if (comparisons == (n - 1) * n)
    {
        printf("Actual Scenario: Worst-case\n");
    }
    else
    {
        printf("Actual Scenario: Neither best nor worst-case\n");
    }

    return 0;
}
