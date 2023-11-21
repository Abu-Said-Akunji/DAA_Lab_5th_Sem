#include <stdio.h>
#include <stdlib.h>

void printNodesBetweenLevels(int arr[], int size, int level1, int level2) {
    if (level1 > level2 || level1 < 0 || level2 < 0 || level1 >= size || level2 >= size) {
        printf("Invalid levels\n");
        return;
    }

    for (int level = 0; level < size; level++) {
        for (int i = 0; i < size; i++) {
            int node = arr[i];
            int currentLevel = 0;
            int index = i;

            while (index > 0) {
                index = (index - 1) / 2;
                currentLevel++;
            }

            if (currentLevel == level) {
                if (level >= level1 && level <= level2) {
                    printf("%d ", node);
                }
            }
        }
    }
    printf("\n");
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int size = sizeof(arr) / sizeof(arr[0]);
    int level1, level2;

    printf("Enter two levels: ");
    scanf("%d %d", &level1, &level2);

    printf("Nodes between levels %d and %d: ", level1, level2);
    printNodesBetweenLevels(arr, size, level1, level2);

    return 0;
}

