#include <stdio.h>
#include <stdlib.h>

void insertionSort(int arr[], int n, int *comparisons) {
    int i, j, key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
            (*comparisons)++;
        }

        arr[j + 1] = key;
    }
}

void displayArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
        printf("\n");
    }

}

int main() {
    int choice, n, *arr;
    int comparisons = 0;
    FILE *inputFile, *outputFile;
    printf("Enter the number of elements: ");
            scanf("%d", &n);
    arr = (int *)malloc(n * sizeof(int));
    printf("Menu:\n");
    printf("1. Ascending order\n");
    printf("2. Descending order\n");
    printf("3. Random Input\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            inputFile = fopen("inAsc.txt", "r");
            if (inputFile == NULL) {
                printf("Error opening file.\n");

            }
            for (int i = 0; i < n; i++) {
                fscanf(inputFile, "%d", &arr[i]);
            }
            fclose(inputFile);

           insertionSort(arr, n, &comparisons);

            outputFile = fopen("outASC.txt", "w");
             if (outputFile == NULL) {
             printf("Error creating output file.\n");
             }
            for (int i = 0; i < n; i++) {
            fprintf(outputFile, "%d ", arr[i]);
            }
            fclose(outputFile);

            break;




        case 2:
            inputFile = fopen("inDes.txt", "r");
            if (inputFile == NULL) {
                printf("Error opening file.\n");
            }
            for (int i = 0; i < n; i++) {
            fscanf(inputFile, "%d", &arr[i]);
            }
            fclose(inputFile);

           insertionSort(arr, n, &comparisons);

            outputFile = fopen("outDes.txt", "w");
             if (outputFile == NULL) {
             printf("Error creating output file.\n");

              }
             for (int i = 0; i < n; i++) {
              fprintf(outputFile, "%d ", arr[i]);
           }
             fclose(outputFile);
              break;



        case 3:
            inputFile = fopen("inRand.txt", "r");
            if (inputFile == NULL) {
                printf("Error opening file.\n");

            }
            for (int i = 0; i < n; i++) {
                fscanf(inputFile, "%d", &arr[i]);
            }
            fclose(inputFile);

           insertionSort(arr, n, &comparisons);

            outputFile = fopen("outRand.txt", "w");
             if (outputFile == NULL) {
             printf("Error creating output file.\n");
             }
            for (int i = 0; i < n; i++) {
            fprintf(outputFile, "%d ", arr[i]);
            }
            fclose(outputFile);

            break;
        default:
            printf("Invalid choice.\n");

    }


    printf("Sorted array: \n");
    displayArray(arr, n);
    printf("Number of comparisons: %d\n", comparisons);

    if (comparisons == (n * (n - 1)) / 2) {
        printf("Input scenario is Best Case.\n");
    } else if (comparisons == n - 1) {
        printf("Input scenario is Worst Case.\n");
    } else {
        printf("Input scenario is Average Case.\n");
    }

    free(arr);
    return 0;
}
