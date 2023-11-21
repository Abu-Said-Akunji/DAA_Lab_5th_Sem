#include <stdio.h>

int binarySearchLeftmost(int arr_3[], int size_3, int key_3, int *comparisons_3)
{
    int low_3 = 0;
    int high_3 = size_3 - 1;
    int result_3 = -1;

    while (low_3 <= high_3)
    {
        int mid_3 = low_3 + (high_3 - low_3) / 2;

        if (arr_3[mid_3] == key_3)
        {
            result_3 = mid_3;
            high_3 = mid_3 - 1;
        }
        else if (arr_3[mid_3] < key_3)
        {
            low_3 = mid_3 + 1;
        }
        else
        {
            high_3 = mid_3 - 1;
        }

        (*comparisons_3)++;
    }

    return result_3;
}

int main()
{
    int size_3;
    printf("Enter size_3 of array: ");
    scanf("%d", &size_3);

    int arr_3[size_3];
    printf("Enter elements of the array: ");
    for (int i = 0; i < size_3; i++)
    {
        scanf("%d", &arr_3[i]);
    }

    int key_3;
    printf("Enter the key_3 to be searched: ");
    scanf("%d", &key_3);

    int comparisons_3 = 0;
    int index_3 = binarySearchLeftmost(arr_3, size_3, key_3, &comparisons_3);

    if (index_3 != -1)
    {
        printf("%d found at index_3 position %d\n", key_3, index_3);
        printf("Number of comparisons_3: %d\n", comparisons_3);
    }
    else
    {
        printf("%d not found in the array\n", key_3);
    }

    return 0;
}
