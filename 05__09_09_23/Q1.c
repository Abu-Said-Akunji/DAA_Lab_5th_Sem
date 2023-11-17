#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct person_5
{
    int id_5;
    char *name_5;
    int age_5;
    int height_5;
    int weight_5;
};

void swap_5(struct person_5 *a_5, struct person_5 *b_5)
{
    struct person_5 temp_5 = *a_5;
    *a_5 = *b_5;
    *b_5 = temp_5;
}

void minHeapify_5(struct person_5 *arr_5, int n_5, int i_5)
{
    int smallest_5 = i_5;
    int left_5 = 2 * i_5 + 1;
    int right_5 = 2 * i_5 + 2;

    if (left_5 < n_5 && arr_5[left_5].age_5 < arr_5[smallest_5].age_5)
        smallest_5 = left_5;

    if (right_5 < n_5 && arr_5[right_5].age_5 < arr_5[smallest_5].age_5)
        smallest_5 = right_5;

    if (smallest_5 != i_5)
    {
        swap_5(&arr_5[i_5], &arr_5[smallest_5]);
        minHeapify_5(arr_5, n_5, smallest_5);
    }
}

void maxHeapify_5(struct person_5 *arr_5, int n_5, int i_5)
{
    int largest_5 = i_5;
    int left_5 = 2 * i_5 + 1;
    int right_5 = 2 * i_5 + 2;

    if (left_5 < n_5 && arr_5[left_5].weight_5 > arr_5[largest_5].weight_5)
        largest_5 = left_5;

    if (right_5 < n_5 && arr_5[right_5].weight_5 > arr_5[largest_5].weight_5)
        largest_5 = right_5;

    if (largest_5 != i_5)
    {
        swap_5(&arr_5[i_5], &arr_5[largest_5]);
        maxHeapify_5(arr_5, n_5, largest_5);
    }
}

void createMinHeap_5(struct person_5 *arr_5, int n_5)
{
    for (int i_5 = n_5 / 2 - 1; i_5 >= 0; i_5--)
    {
        minHeapify_5(arr_5, n_5, i_5);
    }
}

void createMaxHeap_5(struct person_5 *arr_5, int n_5)
{
    for (int i_5 = n_5 / 2 - 1; i_5 >= 0; i_5--)
    {
        maxHeapify_5(arr_5, n_5, i_5);
    }
}

int main()
{
    int option_5, n_5 = 0;
    struct person_5 *people_5 = NULL;

    while (1)
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
        scanf("%d", &option_5);

        switch (option_5)
        {
        case 1:
        {
            char filename_5[100];
            FILE *file_5;

            printf("Enter the name of the file: ");
            scanf("%s", filename_5);

            file_5 = fopen(filename_5, "r");
            if (file_5 == NULL)
            {
                printf("Error opening the file.\n");
                break;
            }

            fscanf(file_5, "%d", &n_5);
            people_5 = (struct person_5 *)malloc(n_5 * sizeof(struct person_5));

            printf("Id Name Age Height Weight(pound)\n");
            for (int i_5 = 0; i_5 < n_5; i_5++)
            {
                people_5[i_5].id_5 = i_5;
                printf("Id Name Age Height Weight(pound)\n");
                people_5[i_5].name_5 = (char *)malloc(50 * sizeof(char));
                fscanf(file_5, "%d %s %d %d %d", &people_5[i_5].id_5, people_5[i_5].name_5, &people_5[i_5].age_5, &people_5[i_5].height_5, &people_5[i_5].weight_5);
                printf("%d %s %d %d %d\n", people_5[i_5].id_5, people_5[i_5].name_5, people_5[i_5].age_5, people_5[i_5].height_5, people_5[i_5].weight_5);
            }

            fclose(file_5);
            break;
        }
        case 2:
            createMinHeap_5(people_5, n_5);
            printf("Min-heap based on age created.\n");
            break;

        case 3:
            createMaxHeap_5(people_5, n_5);
            printf("Max-heap based on weight created.\n");
            break;

        case 4:
            if (n_5 == 0)
            {
                printf("No data available.\n");
            }
            else
            {
                printf("Weight of youngest student: %.2f kg\n", (float)people_5[0].weight_5 * 0.453592);
            }
            break;

        case 5:
            if (n_5 == 0)
            {
                printf("No data available.\n");
            }
            else
            {
                n_5++;
                people_5 = (struct person_5 *)realloc(people_5, n_5 * sizeof(struct person_5));
                printf("Enter the new person's name, age, height, and weight: ");
                people_5[n_5 - 1].id_5 = n_5 - 1;
                people_5[n_5 - 1].name_5 = (char *)malloc(50 * sizeof(char));
                scanf("%s %d %d %d", people_5[n_5 - 1].name_5, &people_5[n_5 - 1].age_5, &people_5[n_5 - 1].height_5, &people_5[n_5 - 1].weight_5);
                createMinHeap_5(people_5, n_5);
            }
            break;

        case 6:
            if (n_5 == 0)
            {
                printf("No data available.\n");
            }
            else
            {
                swap_5(&people_5[0], &people_5[n_5 - 1]);
                free(people_5[n_5 - 1].name_5);
                n_5--;
                people_5 = (struct person_5 *)realloc(people_5, n_5 * sizeof(struct person_5));
                createMinHeap_5(people_5, n_5);
                printf("Oldest person deleted.\n");
            }
            break;

        case 7:
            for (int i_5 = 0; i_5 < n_5; i_5++)
            {
                free(people_5[i_5].name_5);
            }
            free(people_5);
            exit(0);
            break;

        default:
            printf("Invalid option. Please try again.\n");
        }
    }
    return 0;
}
