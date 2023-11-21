#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void merge(int arr[], int left, int mid, int right, int *comparisonCount) {
    int n1 = mid - left + 1;
    int n2 = right - mid;


    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;


    while (i < n1 && j < n2) {
        (*comparisonCount)++;
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1) {
        arr[k++] = L[i++];
    }

    while (j < n2) {
        arr[k++] = R[j++];
    }
}


void mergeSort(int arr[], int left, int right, int *comparisonCount) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid, comparisonCount);
        mergeSort(arr, mid + 1, right, comparisonCount);

        merge(arr, left, mid, right, comparisonCount);
    }
}


int main() {
    clock_t start_time;
    clock_t end_time;
    int choice, n, *arr;
    int comparisonCount = 0;
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


           mergeSort(arr, 0, n - 1, &comparisonCount);


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

            start_time=clock();
            mergeSort(arr, 0, n - 1, &comparisonCount);
            end_time=clock();

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

           mergeSort(arr, 0, n - 1, &comparisonCount);


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

    printf("Sorted elements:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Number of comparisons: %d\n", comparisonCount);
   double exe=(end_time-start_time)/CLOCKS_PER_SEC;
  printf("Execution time:%f",exe);
    return 0;
}
