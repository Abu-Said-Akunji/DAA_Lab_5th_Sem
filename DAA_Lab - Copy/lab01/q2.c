#include <stdio.h>

void findPrefixSum(int arr[], int N)
{
    int prefixSum[N];
    prefixSum[0] = arr[0];

    // Compute prefix sum array
    for (int i = 1; i < N; i++)
    {
        prefixSum[i] = prefixSum[i - 1] + arr[i];
    }

    // Print elements whose values are greater than sum of preceding elements
    for (int i = 0; i < N; i++)
    {
        // if (arr[i] > prefixSum[i - 1]){
            printf("%d ", prefixSum[i]);
        // }
    }
}

int main()
{
    int n;
    printf("Enter number of array");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements: \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    findPrefixSum(arr, n);

    return 0;
}