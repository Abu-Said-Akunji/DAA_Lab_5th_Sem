/*Given an arr_3ay arr_3[] of size N, find the prefix sum of the arr_3ay.
 A prefix sum arr_3ay is another arr_3ay prefixSum_3[] of the same size,
 such that the value of prefixSum_3[i] is arr_3[0] + arr_3[1] + arr_3[2] . . . arr_3[i].*/

#include <stdio.h>
void find_prefix_sum(int arr_3[], int prefixSum_3[], int n_3)
{
    prefixSum_3[0] = arr_3[0];

    for (int i_3 = 1; i_3 < n_3; i_3++)
    {
        prefixSum_3[i_3] = prefixSum_3[i_3 - 1] + arr_3[i_3];
    }
}

int main()
{
    int n_3;
    printf("Enter the size of the arr_3ay: ");
    scanf("%d", &n_3);

    int arr_3[n_3];
    printf("Enter the elements of the arr_3ay:\n");
    for (int i_3 = 0; i_3 < n_3; i_3++)
    {
        scanf("%d", &arr_3[i_3]);
    }

    int prefixSum_3[n_3];

    find_prefix_sum(arr_3, prefixSum_3, n_3);

    printf("Prefix sum arr_3ay: ");
    for (int i_3 = 0; i_3 < n_3; i_3++)
    {
        printf("%d ", prefixSum_3[i_3]);
    }
    printf("\n");

    return 0;
}