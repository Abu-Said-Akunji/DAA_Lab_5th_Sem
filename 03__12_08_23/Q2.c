#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void insertionSort(int arr[], int size, int *comparisons)
{
    for (int i = 1; i < size; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
            (*comparisons)++;
        }

        arr[j + 1] = key;
    }
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    FILE *inputFile, *outputFile;
    int option;
    int comparisons = 0;

    while (1)
    {
        printf("MAIN MENU (INSERTION SORT)\n");
        printf("1. Ascending Data\n");
        printf("2. Descending Data\n");
        printf("3. Random Data\n");
        printf("4. EXIT\n");
        printf("Enter option: ");
        scanf("%d", &option);

        if (option == 4)
        {
            break;
        }

        char inputFileName[20], outputFileName[20];
        int arr[500], size;

        switch (option)
        {
        case 1:
            strcpy(inputFileName, "inAsce.txt");
            strcpy(outputFileName, "outInsAsce.txt");
            break;
        case 2:
            strcpy(inputFileName, "inDesc.txt");
            strcpy(outputFileName, "outInsDesc.txt");
            break;
        case 3:
            strcpy(inputFileName, "inRand.txt");
            strcpy(outputFileName, "outInsRand.txt");
            break;
        default:
            printf("Invalid option!\n");
            continue;
        }

        inputFile = fopen(inputFileName, "r");
        if (inputFile == NULL)
        {
            perror("Error opening input file");
            exit(1);
        }

        size = 0;
        while (fscanf(inputFile, "%d", &arr[size]) != EOF)
        {
            size++;
        }

        fclose(inputFile);

        printf("Before Sorting: ");
        printArray(arr, size);

        comparisons = 0;
        insertionSort(arr, size, &comparisons);

        outputFile = fopen(outputFileName, "w");
        if (outputFile == NULL)
        {
            perror("Error opening output file");
            exit(1);
        }

        for (int i = 0; i < size; i++)
        {
            fprintf(outputFile, "%d ", arr[i]);
        }

        fclose(outputFile);

        printf("After Sorting: ");
        printArray(arr, size);

        printf("Number of Comparisons: %d\n", comparisons);
        printf("Scenario: %s-case\n", (comparisons == 0) ? "Best" : "Worst");
    }

    return 0;
}
