/* Write a program to read ‘n’ integers from a disc file that must contain some duplicate values 
and store them into an array. Perform the following operations on the array.
a)Find out the total number of duplicate elements.
b)Find out the most repeating element in the array.
*/

#include <stdio.h>

int findTotalDuplicates(int arr[], int n) {
    int totalDuplicates = 0;

    for (int i = 0; i < n; i++) {
        int count = 1;
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
            }
        }
        if (count > 1) {
            totalDuplicates++;
        }
    }

    return totalDuplicates;
}

int findMostRepeatingElement(int arr[], int n) {
    int maxCount = 0;
    int mostRepeatingElement = arr[0];

    for (int i = 0; i < n; i++) {
        int count = 1;
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
            }
        }
        if (count > maxCount) {
            maxCount = count;
            mostRepeatingElement = arr[i];
        }
    }

    return mostRepeatingElement;
}

int main() {
    int n;

    printf("Enter how many numbers you want to read from the file: ");
    scanf("%d", &n);

    int arr[n];

    FILE *file = fopen("q3file.txt", "r");
    if (file == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }

    printf("The content of the array: ");
    for (int i = 0; i < n; i++) {
        fscanf(file, "%d", &arr[i]);
        printf("%d ", arr[i]);
    }
    printf("\n");

    fclose(file);

    int totalDuplicates = findTotalDuplicates(arr, n);
    int mostRepeatingElement = findMostRepeatingElement(arr, n);

    printf("Total number of duplicate values = %d\n", totalDuplicates);
    printf("The most repeating element in the array = %d\n", mostRepeatingElement);

    return 0;
}