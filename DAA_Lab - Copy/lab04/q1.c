// Write a menu driven program to sort list of array elements using Merge
// Sort technique and calculate the execution time only to sort the elements.
// Count the number of comparisons.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
long long merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    // Create temporary arrays.
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[left + i];
    }
    for (int i = 0; i < n2; i++)
    {
        R[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = left;
    long long comparisons = 0;

    // Merge the temporary arrays back into 'arr[]'.
    while (i < n1 && j < n2)
    {
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
        comparisons++;
    }

    // Copy the remaining elements of L[], if any.
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if any.
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }

    return comparisons;
}

long long merge_sort(int arr[], int left, int right)
{
    long long comparisons = 0;
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        comparisons += merge_sort(arr, left, mid);
        comparisons += merge_sort(arr, mid + 1, right);

        comparisons += merge(arr, left, mid, right);
    }
    return comparisons;
}

int main()
{
    char filepath[100];
    printf("Enter the relative file path: ");
    scanf("%s", filepath);

    FILE *file = fopen(filepath, "r");
    if (!file)
    {
        fprintf(stderr, "Error: Unable to open the file.\n");
        return 1;
    }

    int arr[1000];
    int num, count = 0;
    while (fscanf(file, "%d", &num) != EOF)
    {
        arr[count++] = num;
    }

    fclose(file);

    clock_t start_time = clock();
    long long comparisons = merge_sort(arr, 0, count - 1);
    clock_t end_time = clock();

    printf("Sorted array:\n");
    for (int i = 0; i < count; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Number of comparisons: %lld\n", comparisons);

    double execution_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC * 1000;
    printf("Execution time: %.2f milliseconds\n", execution_time);

    return 0;
}
