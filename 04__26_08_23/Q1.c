#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int comparisions = 0;

void generateAscending(const char *filename)
{
    FILE *file = fopen(filename, "w");
    if (file == NULL)
    {
        printf("Error opening file %s\n", filename);
        return;
    }

    for (int i = 1; i <= 400; i++)
    {
        fprintf(file, "%d\n", i);
    }

    fclose(file);
}

void generateDescending(const char *filename)
{
    FILE *file = fopen(filename, "w");
    if (file == NULL)
    {
        printf("Error opening file %s\n", filename);
        return;
    }

    for (int i = 400; i >= 1; i--)
    {
        fprintf(file, "%d\n", i);
    }

    fclose(file);
}

void generateRandom(const char *filename)
{
    FILE *file = fopen(filename, "w");
    if (file == NULL)
    {
        printf("Error opening file %s\n", filename);
        return;
    }

    srand(time(NULL));
    for (int i = 0; i < 400; i++)
    {
        fprintf(file, "%d\n", rand() % 1000);
    }

    fclose(file);
}

void merge(int arr[], int left, int right, int mid)
{
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
    {
        L[i] = arr[left + i];
    }
    for (j = 0; j < n2; j++)
    {
        R[j] = arr[mid + 1 + j];
    }
    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2)
    {
        comparisions++;
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, right, mid);
    }
}

int main()
{
    int option;
    int arr[400];
    int left = 0;
    int right = 399;
    clock_t start_time, end_time;
    double elapsed_time;

    generateAscending("inAsce.txt");
    generateDescending("inDesc.txt");
    generateRandom("inRand.txt");

    while (1)
    {
        printf("\n\nMAIN MENU(INSERTION SORT)\n");
        printf("1. Ascending Data\n");
        printf("2. Descending Data\n");
        printf("3. Random Data\n");
        printf("4. Exit\n");
        printf("Enter option: ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            start_time = clock();
            FILE *infile3 = fopen("inAsce.txt", "r");
            if (infile3 == NULL)
            {
                printf("Error opening the file.");
                return 1;
            }
            for (int i = 0; i < right; i++)
            {
                fscanf(infile3, "%d", &arr[i]);
            }
            fclose(infile3);
            printf("\nBefore sorting: \n");
            for (int i = 0; i < right; i++)
            {
                printf("%d ", arr[i]);
            }
            comparisions = 0;
            mergeSort(arr, left, right);
            printf("\n  \nAfter sorting: \n");
            for (int i = 0; i < right; i++)
            {
                printf("%d ", arr[i]);
            }
            FILE *outfile3 = fopen("outMergeAsce.txt", "w");
            for (int i = 0; i < right; i++)
            {
                fprintf(outfile3, "\n%d", arr[i]);
            }
            fclose(outfile3);
            end_time = clock();
            printf("\nNumber of comparisons: %d", comparisions);
            elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
            printf("\nElapsed time: %.4f seconds\n", elapsed_time);
            printf("\nScenario: Best-Case");
            break;

        case 2:
            start_time = clock();
            FILE *infile1 = fopen("inDesc.txt", "r");
            if (infile1 == NULL)
            {
                printf("Error opening the file.");
                return 1;
            }
            for (int i = 0; i < right; i++)
            {
                fscanf(infile1, "%d", &arr[i]);
            }
            fclose(infile1);
            printf("\nBefore sorting: \n");
            for (int i = 0; i < right; i++)
            {
                printf("%d ", arr[i]);
            }
            comparisions = 0;
            mergeSort(arr, left, right);
            printf("\nAfter sorting: \n");
            for (int i = 0; i < right; i++)
            {
                printf("%d ", arr[i]);
            }
            FILE *outfile1 = fopen("outMergeDesc.txt", "w");
            for (int i = 0; i < right; i++)
            {
                fprintf(outfile1, "\n%d", arr[i]);
            }
            fclose(outfile1);
            end_time = clock();
            printf("\nNumber of comparisons: %d", comparisions);
            elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
            printf("\nElapsed time: %.4f seconds\n", elapsed_time);
            printf("\nScenario: Worst-Case");
            break;

        case 3:
            start_time = clock();
            FILE *infile2 = fopen("inRand.txt", "r");
            if (infile2 == NULL)
            {
                printf("Error opening the file.");
                return 1;
            }
            for (int i = 0; i < right; i++)
            {
                fscanf(infile2, "%d", &arr[i]);
            }
            fclose(infile2);
            printf("\nBefore sorting: \n");
            for (int i = 0; i < right; i++)
            {
                printf("%d ", arr[i]);
            }
            comparisions = 0;
            mergeSort(arr, left, right);
            printf("\nAfter sorting: \n");
            for (int i = 0; i < right; i++)
            {
                printf("%d ", arr[i]);
            }
            FILE *outfile2 = fopen("outMergeRand.dat", "w");
            for (int i = 0; i < right; i++)
            {
                fprintf(outfile2, "\n%d", arr[i]);
            }
            fclose(outfile2);
            end_time = clock();
            printf("\nNumber of comparisons: %d", comparisions);
            elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
            printf("\nElapsed time: %.4f seconds\n", elapsed_time);
            printf("\nScenario: Average Case");
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Enter a valid option!\n");
            break;
        }
    }
    return 0;
}
