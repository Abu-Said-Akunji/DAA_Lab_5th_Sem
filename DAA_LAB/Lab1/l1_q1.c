#include <stdio.h>


void find_second_smallest_largest(int arr[], int n, int* second_smallest, int* second_largest) {
    int a[n];
        for(int i=0;i<n;i++){
            a[i]=arr[i];
        }


    for(int i=0;i<n;i++)
    {
        int temp;
        for(int j=i+1; j<n ;j++)
        {
            if(a[i]<a[j])
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
        *second_smallest=a[1];
        *second_largest=a[n-2];

}}

int main() {
    int n;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    if (n <= 1) {
        printf("Error: Array size must be greater than 1.\n");

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

    int second_smallest, second_largest;
    find_second_smallest_largest(arr, n, &second_smallest, &second_largest);

    printf("Second Smallest Element: %d\n", second_smallest);
    printf("Second Largest Element: %d\n", second_largest);

    return 0;
}
