#include <stdio.h>

int binarySearchLeftmost(int arr[], int size, int target, int *comparisons) {
    int left = 0;
    int right = size - 1;
    int result = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        (*comparisons)++; // Counting the comparison

        if (arr[mid] == target) {
            result = mid; // Update the result, but continue searching to the left
            right = mid - 1;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return result;
}

int main() {
    int size;
    int target;
    printf("Enter size of array: ");
    scanf("%d",&size);
    int arr[10];
     printf("Enter elements of array: ");
    for (int i = 0; i < size; i++) {
    scanf( "%d ", &arr[i]);
    }
    printf("\n");
    printf("Enter the key to be searched:\n");
    int comparisons = 0;
    scanf("%d",&target);

    int position = binarySearchLeftmost(arr, size, target, &comparisons);

    if (position != -1) {
        printf("Element %d found at position %d (leftmost appearance)\n", target, position);
    } else {
        printf("Element %d not found in the array\n", target);
    }

    printf("Number of comparisons made: %d\n", comparisons);

    return 0;
}
