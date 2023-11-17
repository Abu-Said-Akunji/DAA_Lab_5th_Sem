// Write a menu driven program to sort a list of elements in ascending
// order using Quick Sort technique. Each choice for the input data has its own disc file. A separate
// output file can be used for sorted elements. After sorting display the content of the output file
// along with number of comparisons. Based on the partitioning position for each recursive call,
// conclude the input scenario is either best-case partitioning or worst-case partitioning. in c

#include <stdio.h>
#include <stdlib.h>

long long comparisons = 0;

// Function to swap two elements.
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to partition the array and return the pivot index.
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        comparisons++;
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Function to perform Quick Sort.
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivotIndex = partition(arr, low, high);

        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

int main()
{
    int choice;
    printf("MENU:\n");
    printf("1. Sort elements from 'input1.txt'\n");
    printf("2. Sort elements from 'input2.txt'\n");
    printf("3. Sort elements from 'input3.txt'\n");
    printf("4. Exit\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice >= 1 && choice <= 3)
    {
        char inputFileName[20], outputFileName[20];
        sprintf(inputFileName, "input%d.txt", choice);
        sprintf(outputFileName, "output%d.txt", choice);

        FILE *inputFile = fopen(inputFileName, "r");
        if (!inputFile)
        {
            printf("Error: Unable to open the input file.\n");
            return 1;
        }

        int n;
        fscanf(inputFile, "%d", &n);
        int arr[n];

        for (int i = 0; i < n; i++)
        {
            fscanf(inputFile, "%d", &arr[i]);
        }

        fclose(inputFile);

        quickSort(arr, 0, n - 1);

        FILE *outputFile = fopen(outputFileName, "w");
        if (!outputFile)
        {
            printf("Error: Unable to open the output file.\n");
            return 1;
        }

        printf("Sorted elements written to %s:\n", outputFileName);
        for (int i = 0; i < n; i++)
        {
            fprintf(outputFile, "%d ", arr[i]);
            printf("%d ", arr[i]);
        }
        printf("\n");

        fclose(outputFile);

        printf("Number of comparisons: %lld\n", comparisons);

        if (comparisons == n - 1)
        {
            printf("This is the best-case partitioning.\n");
        }
        else if (comparisons == (n * (n - 1)) / 2)
        {
            printf("This is the worst-case partitioning.\n");
        }
        else
        {
            printf("This is neither the best-case nor the worst-case partitioning.\n");
        }
    }
    else if (choice == 4)
    {
        printf("Exiting the program.\n");
    }
    else
    {
        printf("Invalid choice.\n");
    }

    return 0;
}
