// Write a program to implement Binary Search to give the position of
// leftmost appearance of the element in the array being searched. Display the number of
// comparisons made while searching.

#include <stdio.h>
// binary search function
int binarySearch(int arr[], int n, int key, int *comparison)
{
    int left = 0, right = n - 1, result = -1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key)
        {
            (*comparison)++;
            result = mid;
            right = mid - 1;
        }
        else if (arr[mid] > key)
            right = mid - 1;
        else if (arr[mid] < key)
            left = mid + 1;
    }
    return result;
}
// main function
int main()
{
    int n, key, comparison = 0;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array in ascending order: \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter the key elements: ");
    scanf("%d", &key);

    int index = binarySearch(arr, n, key, &comparison);
    (index != -1) ? printf("%d found at index position %d\nNumber of comparison is %d", key, index, comparison) : printf("%d not found in the array.\n", key);
    return 0;
}