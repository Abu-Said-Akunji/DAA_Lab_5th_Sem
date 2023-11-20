/*Write a function to ROTATE_RIGHT(p1_3, p2_3 ) right an array for first p2_3 elements by 1 position using
EXCHANGE(p, q) function that swaps/exchanges the numbers p & q.Parameter p1_3 be the starting address
of the array and p2_3 be the number of elements to be rotated.  */

#include <stdio.h>

void EXCHANGE(int *p_3, int *q_3)
{
    int temp_3 = *p_3;
    *p_3 = *q_3;
    *q_3 = temp_3;
}

void ROTATE_RIGHT(int *p1_3, int p2_3)
{
    if (p2_3 < 1)
    {
        printf("Number of elements to rotate should be at least 1.\n");
        return;
    }

    for (int i = 0; i < p2_3 - 1; i++)
    {
        EXCHANGE(p1_3 + i, p1_3 + i + 1);
    }
}

int main()
{
    int n_3;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n_3);

    int arr_3[n_3];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n_3; i++)
    {
        scanf("%d", &arr_3[i]);
    }

    int p2_3;
    printf("Enter the number of elements to rotate: ");
    scanf("%d", &p2_3);

    ROTATE_RIGHT(arr_3, p2_3);

    printf("Array after rotation:\n");
    for (int i = 0; i < n_3; i++)
    {
        printf("%d ", arr_3[i]);
    }
    printf("\n");
    return 0;
}