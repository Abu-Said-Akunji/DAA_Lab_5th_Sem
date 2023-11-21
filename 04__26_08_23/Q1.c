#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int comparisions_3 = 0;

void generateAscending(const char *filename_3)
{
    FILE *file = fopen(filename_3, "w");
    if (file == NULL)
    {
        printf("Error opening file %s\n", filename_3);
        return;
    }

    for (int i = 1; i <= 400; i++)
    {
        fprintf(file, "%d\n", i);
    }

    fclose(file);
}

void generateDescending(const char *filename_3)
{
    FILE *file = fopen(filename_3, "w");
    if (file == NULL)
    {
        printf("Error opening file %s\n", filename_3);
        return;
    }

    for (int i = 400; i >= 1; i--)
    {
        fprintf(file, "%d\n", i);
    }

    fclose(file);
}

void generateRandom(const char *filename_3)
{
    FILE *file = fopen(filename_3, "w");
    if (file == NULL)
    {
        printf("Error opening file %s\n", filename_3);
        return;
    }

    srand(time(NULL));
    for (int i = 0; i < 400; i++)
    {
        fprintf(file, "%d\n", rand() % 1000);
    }

    fclose(file);
}

void merge(int arr_3[], int left_3, int right_3, int mid_3)
{
    int i, j, k;
    int n1_3 = mid_3 - left_3 + 1;
    int n2_3 = right_3 - mid_3;
    int L[n1_3], R[n2_3];
    for (i = 0; i < n1_3; i++)
    {
        L[i] = arr_3[left_3 + i];
    }
    for (j = 0; j < n2_3; j++)
    {
        R[j] = arr_3[mid_3 + 1 + j];
    }
    i = 0;
    j = 0;
    k = left_3;

    while (i < n1_3 && j < n2_3)
    {
        comparisions_3++;
        if (L[i] <= R[j])
        {
            arr_3[k] = L[i];
            i++;
        }
        else
        {
            arr_3[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1_3)
    {
        arr_3[k] = L[i];
        i++;
        k++;
    }

    while (j < n2_3)
    {
        arr_3[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr_3[], int left_3, int right_3)
{
    if (left_3 < right_3)
    {
        int mid_3 = left_3 + (right_3 - left_3) / 2;
        mergeSort(arr_3, left_3, mid_3);
        mergeSort(arr_3, mid_3 + 1, right_3);
        merge(arr_3, left_3, right_3, mid_3);
    }
}

int main()
{
    int option_3;
    int arr_3[400];
    int left_3 = 0;
    int right_3 = 399;
    clock_t start_time_3, end_time_3;
    double elapsed_time_3;

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
        printf("Enter option_3: ");
        scanf("%d", &option_3);
        switch (option_3)
        {
        case 1:
            start_time_3 = clock();
            FILE *infile3 = fopen("inAsce.txt", "r");
            if (infile3 == NULL)
            {
                printf("Error opening the file.");
                return 1;
            }
            for (int i = 0; i < right_3; i++)
            {
                fscanf(infile3, "%d", &arr_3[i]);
            }
            fclose(infile3);
            printf("\nBefore sorting: \n");
            for (int i = 0; i < right_3; i++)
            {
                printf("%d ", arr_3[i]);
            }
            comparisions_3 = 0;
            mergeSort(arr_3, left_3, right_3);
            printf("\n  \nAfter sorting: \n");
            for (int i = 0; i < right_3; i++)
            {
                printf("%d ", arr_3[i]);
            }
            FILE *outfile3 = fopen("outMergeAsce.txt", "w");
            for (int i = 0; i < right_3; i++)
            {
                fprintf(outfile3, "\n%d", arr_3[i]);
            }
            fclose(outfile3);
            end_time_3 = clock();
            printf("\nNumber of comparisons: %d", comparisions_3);
            elapsed_time_3 = (double)(end_time_3 - start_time_3) / CLOCKS_PER_SEC;
            printf("\nElapsed time: %.4f seconds\n", elapsed_time_3);
            printf("\nScenario: Best-Case");
            break;

        case 2:
            start_time_3 = clock();
            FILE *infile1 = fopen("inDesc.txt", "r");
            if (infile1 == NULL)
            {
                printf("Error opening the file.");
                return 1;
            }
            for (int i = 0; i < right_3; i++)
            {
                fscanf(infile1, "%d", &arr_3[i]);
            }
            fclose(infile1);
            printf("\nBefore sorting: \n");
            for (int i = 0; i < right_3; i++)
            {
                printf("%d ", arr_3[i]);
            }
            comparisions_3 = 0;
            mergeSort(arr_3, left_3, right_3);
            printf("\nAfter sorting: \n");
            for (int i = 0; i < right_3; i++)
            {
                printf("%d ", arr_3[i]);
            }
            FILE *outfile1 = fopen("outMergeDesc.txt", "w");
            for (int i = 0; i < right_3; i++)
            {
                fprintf(outfile1, "\n%d", arr_3[i]);
            }
            fclose(outfile1);
            end_time_3 = clock();
            printf("\nNumber of comparisons: %d", comparisions_3);
            elapsed_time_3 = (double)(end_time_3 - start_time_3) / CLOCKS_PER_SEC;
            printf("\nElapsed time: %.4f seconds\n", elapsed_time_3);
            printf("\nScenario: Worst-Case");
            break;

        case 3:
            start_time_3 = clock();
            FILE *infile2 = fopen("inRand.txt", "r");
            if (infile2 == NULL)
            {
                printf("Error opening the file.");
                return 1;
            }
            for (int i = 0; i < right_3; i++)
            {
                fscanf(infile2, "%d", &arr_3[i]);
            }
            fclose(infile2);
            printf("\nBefore sorting: \n");
            for (int i = 0; i < right_3; i++)
            {
                printf("%d ", arr_3[i]);
            }
            comparisions_3 = 0;
            mergeSort(arr_3, left_3, right_3);
            printf("\nAfter sorting: \n");
            for (int i = 0; i < right_3; i++)
            {
                printf("%d ", arr_3[i]);
            }
            FILE *outfile2 = fopen("outMergeRand.dat", "w");
            for (int i = 0; i < right_3; i++)
            {
                fprintf(outfile2, "\n%d", arr_3[i]);
            }
            fclose(outfile2);
            end_time_3 = clock();
            printf("\nNumber of comparisons: %d", comparisions_3);
            elapsed_time_3 = (double)(end_time_3 - start_time_3) / CLOCKS_PER_SEC;
            printf("\nElapsed time: %.4f seconds\n", elapsed_time_3);
            printf("\nScenario: Average Case");
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Enter a valid option_3!\n");
            break;
        }
    }
    return 0;
}
