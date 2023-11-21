#include <stdio.h>

void find_duplicates(int arr[], int n) {
    int freq[n];
    for (int i = 0; i < n; i++) {
    freq[i]=0;
    }
    int total_duplicates = 0;
    int max_repeating_element = arr[0];
    int max_repeating_count = 1;

    for (int i = 0; i < n; i++) {
        if(freq[i]==0){
        int current_element = arr[i];
        int current_count=1;


        for (int j = i + 1; j < n; j++) {
            if (arr[j] == current_element) {
                current_count++;
                freq[j]=1;
            }
        }


        if (current_count > 1) {
            total_duplicates += (current_count-1);
        }


        if (current_count > max_repeating_count) {
            max_repeating_element = current_element;
            max_repeating_count = current_count;
        }
    }}

    printf("Total number of duplicate elements: %d\n", total_duplicates);
    printf("Most repeating element: %d (Repeats %d times)\n", max_repeating_element, max_repeating_count);
}

int main() {
    int n;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Error: Array size must be greater than 0.\n");
        return 1;
    }

    char filename[100];
    printf("Enter the filename to read the elements from: ");
    scanf("%s", filename);

    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Failed to open the file.\n");

    }

    int arr[n];
    for (int i = 0; i < n; i++) {
        fscanf(file, "%d", &arr[i]);
    }
    fclose(file);

    find_duplicates(arr, n);

    return 0;
}

