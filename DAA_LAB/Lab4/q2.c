#include <stdio.h>
#include <stdlib.h>

int partition(int arr[], int low, int high, int *comparisonCount) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        (*comparisonCount)++;
        if (arr[j] <= pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

void quickSort(int arr[], int low, int high, int *comparisonCount) {
    if (low < high) {
        int partitionIndex = partition(arr, low, high, comparisonCount);
        quickSort(arr, low, partitionIndex - 1, comparisonCount);
        quickSort(arr, partitionIndex + 1, high, comparisonCount);
    }
}

void readDataFromFile( char *fileName, int arr[], int n) {
    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", fileName);
        exit(1);
    }

    for (int i = 0; i < n; i++) {
        fscanf(file, "%d", &arr[i]);
    }

    fclose(file);
}

void writeDataToFile(char *fileName, int arr[], int n) {
    FILE *file = fopen(fileName, "w");
    if (file == NULL) {
        printf("Error opening file %s\n", fileName);
        exit(1);
    }

    for (int i = 0; i < n; i++) {
        fprintf(file, "%d ", arr[i]);
    }

    fclose(file);
}

int main() {
    int choice;
    int n = 0;

    printf("Menu:\n");
    printf("1. Ascending order\n");
    printf("2. Descending order\n");
    printf("3. Random order\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    char *inputFile, *outputFile;
    if (choice == 1) {
        inputFile = "inAsc.txt";
        outputFile = "outAsc.txt";
        n = 10;
    } else if (choice == 2) {
        inputFile = "inDes.txt";
        outputFile = "outDes.txt";
        n = 10;
    } else if (choice == 3) {
        inputFile = "inRan.txt";
        outputFile = "outRan.txt";
        n = 10;
    } else {
        printf("Invalid choice.\n");
        return 1;
    }

    int arr[n];
    int comparisonCount = 0;

    readDataFromFile(inputFile, arr, n);

    quickSort(arr, 0, n - 1, &comparisonCount);

    writeDataToFile(outputFile, arr, n);

    printf("Sorted elements:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Number of comparisons: %d\n", comparisonCount);

    if (comparisonCount == n - 1) {
        printf("This scenario represents best-case partitioning.\n");
    } else if (comparisonCount == (n * (n - 1)) / 2) {
        printf("This scenario represents worst-case partitioning.\n");
    }

    return 0;
}
