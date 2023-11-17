#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct person
{
    int id;
    char *name;
    int age;
    int height;
    int weight;
};

// Function to swap two struct person elements
void swap(struct person *x, struct person *y)
{
    struct person temp = *x;
    *x = *y;
    *y = temp;
}

// Function to heapify a subtree rooted at given index
void heapify(struct person *arr, int n, int i, int choice)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (choice == 1) // Min-heap based on age
    {
        if (left < n && arr[left].age < arr[largest].age)
            largest = left;
        if (right < n && arr[right].age < arr[largest].age)
            largest = right;
    }
    else if (choice == 2) // Max-heap based on weight
    {
        if (left < n && arr[left].weight > arr[largest].weight)
            largest = left;
        if (right < n && arr[right].weight > arr[largest].weight)
            largest = right;
    }

    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest, choice);
    }
}

// Function to build heap
void buildHeap(struct person *arr, int n, int choice)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i, choice);
    }
}

int main()
{
    int n;
    struct person *students = NULL;

    printf("Enter the number of students: ");
    scanf("%d", &n);

    students = (struct person *)malloc(n * sizeof(struct person));
    if (students == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        printf("Enter data for student %d:\n", i + 1);
        students[i].id = i;
        students[i].name = (char *)malloc(50 * sizeof(char));
        printf("Id: %d\n", students[i].id);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Age: ");
        scanf("%d", &students[i].age);
        printf("Height: ");
        scanf("%d", &students[i].height);
        printf("Weight (in pounds): ");
        scanf("%d", &students[i].weight);
    }

    int choice;
    do
    {
        printf("\nMAIN MENU (HEAP)\n");
        printf("1. Read Data\n");
        printf("2. Create a Min-heap based on the age\n");
        printf("3. Create a Max-heap based on the weight\n");
        printf("4. Display weight of the youngest person\n");
        printf("5. Insert a new person into the Min-heap\n");
        printf("6. Delete the oldest person\n");
        printf("7. Exit\n");
        printf("Enter option: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            // Data is already read during initialization
            break;

        case 2:
            buildHeap(students, n, 1); // Create Min-heap based on age
            printf("Min-heap based on age created.\n");
            break;

        case 3:
            buildHeap(students, n, 2); // Create Max-heap based on weight
            printf("Max-heap based on weight created.\n");
            break;

        case 4:
            printf("Weight of youngest student: %.2f kg\n", students[0].weight / 2.20462);
            break;

        case 5:
            if (n >= 1)
            {
                // Insert a new person into the Min-heap based on age
                n++;
                students = (struct person *)realloc(students, n * sizeof(struct person));
                printf("Enter data for the new student:\n");
                students[n - 1].id = n - 1;
                students[n - 1].name = (char *)malloc(50 * sizeof(char));
                printf("Id: %d\n", students[n - 1].id);
                printf("Name: ");
                scanf("%s", students[n - 1].name);
                printf("Age: ");
                scanf("%d", &students[n - 1].age);
                printf("Height: ");
                scanf("%d", &students[n - 1].height);
                printf("Weight (in pounds): ");
                scanf("%d", &students[n - 1].weight);
                buildHeap(students, n, 1);
                printf("New student inserted into the Min-heap based on age.\n");
            }
            else
            {
                printf("Min-heap is empty. Cannot insert a new student.\n");
            }
            break;

        case 6:
            if (n >= 1)
            {
                // Delete the oldest person from the Min-heap based on age
                students[0] = students[n - 1];
                n--;
                students = (struct person *)realloc(students, n * sizeof(struct person));
                buildHeap(students, n, 1);
                printf("Oldest student deleted from the Min-heap based on age.\n");
            }
            else
            {
                printf("Min-heap is empty. Cannot delete the oldest student.\n");
            }
            break;

        case 7:
            printf("Exiting the program.\n");
            break;

        default:
            printf("Invalid option! Please enter a valid option.\n");
        }
    } while (choice != 7);

    // Free allocated memory
    for (int i = 0; i < n; i++)
    {
        free(students[i].name);
    }
    free(students);

    return 0;
}