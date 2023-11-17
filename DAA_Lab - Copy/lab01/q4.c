#include <stdio.h>

// Function to swap/exchange two integers
void EXCHANGE(int *p, int *q)
{
    int temp = *p;
    *p = *q;
    *q = temp;
}

// Function to reverse the elements in the array from start to end (inclusive)
void reverseArray(int *pl, int start, int end)
{
    while (start < end)
    {
        EXCHANGE(&pl[start], &pl[end]);
        start++;
        end--;
    }
}

// Function to rotate 'p2' elements in the array 'pl' to the right by 'I' positions
void rotateRight(int *pl, int p2, int I)
{
    // Calculate the effective rotation positions (I can be larger than p2)
    I %= p2;

    // Reverse the first p2 elements
    reverseArray(pl, 0, p2 - 1);

    // Reverse the first I elements
    reverseArray(pl, 0, I - 1);

    // Reverse the rest of the elements
    reverseArray(pl, I, p2 - 1);
}

int main()
{
    int arr[] = {11, 22, 33, 44, 55, 66, 77, 88, 89};
    int p2 = 4; // Number of elements to rotate
    int I = 3;  // Number of positions to rotate right

    printf("Original array: ");
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    rotateRight(arr, p2, I);

    printf("Array after rotating first %d elements by %d positions to the right: ", p2, I);
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}