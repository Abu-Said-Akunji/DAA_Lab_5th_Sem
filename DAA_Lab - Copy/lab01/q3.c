#include <stdio.h>
#include <stdlib.h>

// Function to read 'n' integers from a file and store them in an array
int readFromFile(const char* filename, int* array, int n) {
    FILE* file;
    file = fopen("input_3.txt.txt", "r");
    if (file == NULL) {
        printf("Error opening the file.\n");
        return 0;
    }

    int i;
    for (i = 0; i < n; i++) {
        if (fscanf(file, "%d", &array[i]) != 1) {
            printf("Error reading from the file.\n");
            fclose(file);
            return 0;
        }
    }

    fclose(file);
    return 1;
}

// Function to find the total number of duplicate elements
int countDuplicates(int* array, int n) {
    int count = 0;

    // Check each element against the rest of the elements in the array
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (array[i] == array[j]) {
                count++;
                break; // To avoid counting the same duplicate element multiple times
            }
        }
    }

    return count;
}

// Function to find the most repeating element in the array
int mostRepeatingElement(int* array, int n) {
    int maxCount = 0;
    int mostRepeated = 0;

    for (int i = 0; i < n; i++) {
        int count = 1;
        for (int j = i + 1; j < n; j++) {
            if (array[i] == array[j]) {
                count++;
            }
        }

        if (count > maxCount) {
            maxCount = count;
            mostRepeated = array[i];
        }
    }

    return mostRepeated;
}

int main() {
    int n;

    printf("Enter the number of integers in the file: ");
    scanf("%d", &n);

    int* array = (int*)malloc(n * sizeof(int));
    if (array == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    if (!readFromFile("text_1.txt", array, n)) {
        free(array);
        return 1;
    }

    // Print the array
    printf("Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    int totalDuplicates = countDuplicates(array, n);
    printf("Total number of duplicate elements: %d\n", totalDuplicates);

    int mostRepeatedElement = mostRepeatingElement(array, n);
    printf("Most repeating element: %d\n", mostRepeatedElement);

    free(array);
    return 0;
}