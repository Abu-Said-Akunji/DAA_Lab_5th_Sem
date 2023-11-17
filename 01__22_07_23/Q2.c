/*Given an array arr[] of size N, find the prefix sum of the array.
 A prefix sum array is another array prefixSum[] of the same size,
 such that the value of prefixSum[i] is arr[0] + arr[1] + arr[2] . . . arr[i].*/

#include <stdio.h>

// Function to calculate the prefix sum array

int main()
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int prefixSum[n]; // Array to store the prefix sum

    // Calculate the prefix sum array
    find_prefix_sum(arr, prefixSum, n);

    // Print the prefix sum array
    printf("Prefix sum array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", prefixSum[i]);
    }
    printf("\n");

    return 0;
}
void find_prefix_sum(int arr[], int prefixSum[], int n)
{
    prefixSum[0] = arr[0]; // The first element of prefixSum is the same as arr[0]

    // Calculate the prefix sum for the remaining elements
    for (int i = 1; i < n; i++)
    {
        prefixSum[i] = prefixSum[i - 1] + arr[i];
    }
}