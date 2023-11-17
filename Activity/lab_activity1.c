#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int left[], int right[], int left_size, int right_size)
{
    int i = 0, j = 0, k = 0;

    while (i < left_size && j < right_size)
    {
        if (left[i] <= right[j])
        {
            arr[k++] = left[i++];
        }
        else
        {
            arr[k++] = right[j++];
        }
    }

    while (i < left_size)
    {
        arr[k++] = left[i++];
    }

    while (j < right_size)
    {
        arr[k++] = right[j++];
    }
}

void mergeSort(int arr[], int size)
{
    if (size <= 1)
    {
        return;
    }

    int mid = size / 2;
    int left[mid];
    int right[size - mid];

    for (int i = 0; i < mid; i++)
    {
        left[i] = arr[i];
    }

    for (int i = mid; i < size; i++)
    {
        right[i - mid] = arr[i];
    }

    mergeSort(left, mid);
    mergeSort(right, size - mid);
    merge(arr, left, right, mid, size - mid);
}

void mergeArrays(int arr1[], int arr2[], int n1, int n2, int arr3[])
{
    int i = 0, j = 0, k = 0;

    while (i < n1 && j < n2)
    {
        if (arr1[i] < arr2[j])
        {
            arr3[k++] = arr1[i++];
        }
        else
        {
            arr3[k++] = arr2[j++];
        }
    }

    while (i < n1)
    {
        arr3[k++] = arr1[i++];
    }

    while (j < n2)
    {
        arr3[k++] = arr2[j++];
    }
}

int main()
{
    int group1[100], group2[100], group3[100], group4[100];
    int size1 = 0, size2 = 0, size3 = 0, size4 = 0;

    FILE *file1 = fopen("panel1.txt", "r");
    while (fscanf(file1, "%d", &group1[size1]) != EOF)
    {
        size1++;
    }
    fclose(file1);

    mergeSort(group1, size1);

    FILE *file2 = fopen("panel2.txt", "r");
    while (fscanf(file2, "%d", &group2[size2]) != EOF)
    {
        size2++;
    }
    fclose(file2);

    mergeSort(group2, size2);

    FILE *file3 = fopen("panel3.txt", "r");
    while (fscanf(file3, "%d", &group3[size3]) != EOF)
    {
        size3++;
    }
    fclose(file3);

    mergeSort(group3, size3);

    FILE *file4 = fopen("panel4.txt", "r");
    while (fscanf(file4, "%d", &group4[size4]) != EOF)
    {
        size4++;
    }
    fclose(file4);

    mergeSort(group4, size4);

    int temp1[200], temp2[200], temp3[400], result[10];

    mergeArrays(group1, group2, size1, size2, temp1);
    mergeArrays(group3, group4, size3, size4, temp2);
    mergeArrays(temp1, temp2, (size1 + size2), (size3 + size4), temp3);

    int netSize = size1 + size2 + size3 + size4, c = 0;

    for (int i = 0; i < netSize; i++)
    {
        int count = 0;
        for (int j = 0; j < netSize; j++)
        {
            if ((j >= i) && temp3[j] == temp3[i])
            {
                count++;
            }
        }
        if (count >= 3 && (temp3[i - 1] != temp3[i] && (temp3[i - 2] != temp3[i]) && (temp3[i - 3] != temp3[i])))
        {
            result[c++] = temp3[i];
        }
    }

    printf("%d students are selected having roll numbers", c);

    for (int i = 0; i < c; i++)
    {
        printf(" %d", result[i]);
    }

    printf(".\n");

    return 0;
}
