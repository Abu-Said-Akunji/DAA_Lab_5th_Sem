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

void swap(struct person *a, struct person *b)
{
    struct person temp = *a;
    *a = *b;
    *b = temp;
}

void heapify_age(struct person arr[], int n, int i)
{
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left].age < arr[smallest].age)
        smallest = left;
    if (right < n && arr[right].age < arr[smallest].age)
        smallest = right;

    if (smallest != i)
    {
        swap(&arr[i], &arr[smallest]);
        heapify_age(arr, n, smallest);
    }
}

void heapify_weight(struct person arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left].weight > arr[largest].weight)
        largest = left;
    if (right < n && arr[right].weight > arr[largest].weight)
        largest = right;

    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        heapify_weight(arr, n, largest);
    }
}

void build_heap(struct person arr[], int n, int isMaxHeap)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        if (isMaxHeap==1){
            heapify_weight(arr, n, i);
        }
        else{
            heapify_age(arr, n, i);
    }}
}

void display_weight_youngest(struct person arr[], int n)
{
    if (n == 0)
    {
        printf("Heap is empty.\n");
        return;
    }
    build_heap(arr,n,0);
    printf("Weight of the youngest person: %d\n", arr[0].weight);
}

void insert_person(struct person arr[], int *n, int isMaxHeap)
{
    struct person newPerson;
    printf("Enter new person's details (id name age height weight): ");
    scanf("%d %s %d %d %d", &newPerson.id, newPerson.name, &newPerson.age, &newPerson.height, &newPerson.weight);

    (*n)++;
    arr = (struct person *)realloc(arr, (*n) * sizeof(struct person));
    arr[*n - 1] = newPerson;

    build_heap(arr, *n, isMaxHeap);

    printf("New person inserted into the heap.\n");
    return;
}

void delete_oldest(struct person arr[], int *n)
{
    if (*n == 0)
    {
        printf("Heap is empty.\n");
        return;
    }
    int max=0;
    int num;
    for(int i=0;i<*n;i++){
        if(arr[i].weight>max){
            max=arr[i].weight;
            num=i;
        }
    }
    printf("Deleting the oldest person: %s\n", arr[num].name);
    arr[num] = arr[num - 1];
    (*n)--;

    build_heap(arr, *n, 0);

    printf("Oldest person deleted.\n");
}
void display_heap(struct person arr[], int n)
{
    printf("Heap:\n ");
    printf("%s","ID NAME AGE HEIGHT  WEIGHT\n");
    for (int i = 0; i < n; i++)
    {
        printf(" %d ", arr[i].id);
        printf("%s ", arr[i].name);
        printf("%d ", arr[i].age);
        printf("%d\t", arr[i].height);
        printf("%d ", arr[i].weight);
        printf("\n");
    }
    printf("\n");
}

void display_menu()
{
    printf("\nMAIN MENU (HEAP)\n");
    printf("1. Read Data\n");
    printf("2. Create a Min-heap based on the age\n");
    printf("3. Create a Max-heap based on the weight\n");
    printf("4. Display weight of the youngest person\n");
    printf("5. Insert a new person into the Min-heap\n");
    printf("6. Delete the oldest person\n");
    printf("7. Exit\n");
    printf("Enter your choice: ");
}

int main()
{
    int n = 0;
    struct person *students = NULL;

    int choice;
    while (1)
    {
        display_menu();
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
            {
                FILE *file = fopen("q1.txt", "r");
                if (!file)
                {
                    printf("File not found.\n");
                    continue;
                }

                int temp_id, temp_age, temp_height, temp_weight;
                char temp_name[100];
                while (fscanf(file, "%d %s %d %d %d", &temp_id, temp_name, &temp_age, &temp_height, &temp_weight) != EOF)
                {
                    n++;
                    students = (struct person *)realloc(students, n * sizeof(struct person));
                    students[n - 1].id = temp_id;
                    students[n - 1].name = strdup(temp_name);
                    students[n - 1].age = temp_age;
                    students[n - 1].height = temp_height;
                    students[n - 1].weight = temp_weight;
                }

                fclose(file);
                printf("Data read from file.\n");
                display_heap(students, n);
                break;
            }

            case 2:
                build_heap(students, n, 0);
                printf("Min-heap based on age created.\n");
                display_heap(students, n);
                break;

            case 3:
                build_heap(students, n, 1);
                printf("Max-heap based on weight created.\n");
                display_heap(students, n);
                break;

            case 4:
                display_weight_youngest(students, n);
                break;

            case 5:
                insert_person(students, &n, 0);
                display_heap(students, n);
                break;

            case 6:
                delete_oldest(students, &n);
                display_heap(students, n);
                break;

            case 7:
                for (int i = 0; i < n; i++)
                    free(students[i].name);
                free(students);
                printf("Exiting the program.\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

