#include <stdio.h>

void findSecondSmallestAndLargest(int arr[], int n)
{
    int i;
    int smallest = arr[0];
    int largest = arr[0];
    int secondSmallest = arr[0];
    int secondLargest = arr[0];

    for (i = 1; i < n; i++)
    {
        if (arr[i] < smallest)
        {
            secondSmallest = smallest;
            smallest = arr[i];
        }
        else if (arr[i] < secondSmallest && arr[i] != smallest)
        {
            secondSmallest = arr[i];
        }

        if (arr[i] > largest)
        {
            secondLargest = largest;
            largest = arr[i];
        }
        else if (arr[i] > secondLargest && arr[i] != largest)
        {
            secondLargest = arr[i];
        }
    }

    printf("Second Smallest: %d\n", secondSmallest);
    printf("Second Largest: %d\n", secondLargest);

    // Delete second smallest and second largest elements from the array
    int j, k;
    for (j = 0; j < n; j++)
    {
        if (arr[j] == secondSmallest || arr[j] == secondLargest)
        {
            for (k = j; k < n - 1; k++)
            {
                arr[k] = arr[k + 1];
            }
            n--;
            j--;
        }
    }

    printf("Array after deletion: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int n, i;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    findSecondSmallestAndLargest(arr, n);

    return 0;
}
