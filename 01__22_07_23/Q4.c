/*Write a function to ROTATE_RIGHT(p1, p2 ) right an array for first p2 elements by 1 position using
EXCHANGE(p, q) function that swaps/exchanges the numbers p & q.Parameter p1 be the starting address
of the array and p2 be the number of elements to be rotated.  */

#include <stdio.h>

// Function to swap two elements using EXCHANGE(p, q) function
void EXCHANGE(int *p, int *q)
{
    int temp = *p;
    *p = *q;
    *q = temp;
}

// Function to rotate right an array for the first p2 elements by 1 position
void ROTATE_RIGHT(int *p1, int p2)
{
    if (p2 < 1)
    {
        printf("Number of elements to rotate should be at least 1.\n");
        return;
    }

    for (int i = 0; i < p2 - 1; i++)
    {
        EXCHANGE(p1 + i, p1 + i + 1);
    }
}

int main()
{
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int p2;
    printf("Enter the number of elements to rotate: ");
    scanf("%d", &p2);

    ROTATE_RIGHT(arr, p2);

    printf("Array after rotation:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}