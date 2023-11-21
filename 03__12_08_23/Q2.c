#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void insertionSort(int arr_3[], int size_3, int *comparisons_3)
{
    for (int i = 1; i < size_3; i++)
    {
        int key_3 = arr_3[i];
        int j = i - 1;

        while (j >= 0 && arr_3[j] > key_3)
        {
            arr_3[j + 1] = arr_3[j];
            j--;
            (*comparisons_3)++;
        }

        arr_3[j + 1] = key_3;
    }
}

void printArray(int arr_3[], int size_3)
{
    for (int i = 0; i < size_3; i++)
    {
        printf("%d ", arr_3[i]);
    }
    printf("\n");
}

int main()
{
    FILE *inputFile, *outputFile;
    int option_3;
    int comparisons_3 = 0;

    while (1)
    {
        printf("MAIN MENU (INSERTION SORT)\n");
        printf("1. Ascending Data\n");
        printf("2. Descending Data\n");
        printf("3. Random Data\n");
        printf("4. EXIT\n");
        printf("Enter option_3: ");
        scanf("%d", &option_3);

        if (option_3 == 4)
        {
            break;
        }

        char inputFileName_3[20], outputFileName_3[20];
        int arr_3[500], size_3;

        switch (option_3)
        {
        case 1:
            strcpy(inputFileName_3, "inAsce.txt");
            strcpy(outputFileName_3, "outInsAsce.txt");
            break;
        case 2:
            strcpy(inputFileName_3, "inDesc.txt");
            strcpy(outputFileName_3, "outInsDesc.txt");
            break;
        case 3:
            strcpy(inputFileName_3, "inRand.txt");
            strcpy(outputFileName_3, "outInsRand.txt");
            break;
        default:
            printf("Invalid option_3!\n");
            continue;
        }

        inputFile = fopen(inputFileName_3, "r");
        if (inputFile == NULL)
        {
            perror("Error opening input file");
            exit(1);
        }

        size_3 = 0;
        while (fscanf(inputFile, "%d", &arr_3[size_3]) != EOF)
        {
            size_3++;
        }

        fclose(inputFile);

        printf("Before Sorting: ");
        printArray(arr_3, size_3);

        comparisons_3 = 0;
        insertionSort(arr_3, size_3, &comparisons_3);

        outputFile = fopen(outputFileName_3, "w");
        if (outputFile == NULL)
        {
            perror("Error opening output file");
            exit(1);
        }

        for (int i = 0; i < size_3; i++)
        {
            fprintf(outputFile, "%d ", arr_3[i]);
        }

        fclose(outputFile);

        printf("After Sorting: ");
        printArray(arr_3, size_3);

        printf("Number of Comparisons: %d\n", comparisons_3);
        printf("Scenario: %s-case\n", (comparisons_3 == 0) ? "Best" : "Worst");
    }

    return 0;
}
