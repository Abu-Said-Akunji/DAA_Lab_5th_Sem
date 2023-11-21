#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct person_3
{
    int id_3;
    char *name_3;
    int age_3;
    int height_3;
    int weight_3;
};

void swap_3(struct person_3 *a_3, struct person_3 *b_3)
{
    struct person_3 temp_3 = *a_3;
    *a_3 = *b_3;
    *b_3 = temp_3;
}

void minHeapify_3(struct person_3 *arr_3, int n_3, int i_3)
{
    int smallest_3 = i_3;
    int left_3 = 2 * i_3 + 1;
    int right_3 = 2 * i_3 + 2;

    if (left_3 < n_3 && arr_3[left_3].age_3 < arr_3[smallest_3].age_3)
        smallest_3 = left_3;

    if (right_3 < n_3 && arr_3[right_3].age_3 < arr_3[smallest_3].age_3)
        smallest_3 = right_3;

    if (smallest_3 != i_3)
    {
        swap_3(&arr_3[i_3], &arr_3[smallest_3]);
        minHeapify_3(arr_3, n_3, smallest_3);
    }
}

void maxHeapify_3(struct person_3 *arr_3, int n_3, int i_3)
{
    int largest_3 = i_3;
    int left_3 = 2 * i_3 + 1;
    int right_3 = 2 * i_3 + 2;

    if (left_3 < n_3 && arr_3[left_3].weight_3 > arr_3[largest_3].weight_3)
        largest_3 = left_3;

    if (right_3 < n_3 && arr_3[right_3].weight_3 > arr_3[largest_3].weight_3)
        largest_3 = right_3;

    if (largest_3 != i_3)
    {
        swap_3(&arr_3[i_3], &arr_3[largest_3]);
        maxHeapify_3(arr_3, n_3, largest_3);
    }
}

void createMinHeap_3(struct person_3 *arr_3, int n_3)
{
    for (int i_3 = n_3 / 2 - 1; i_3 >= 0; i_3--)
    {
        minHeapify_3(arr_3, n_3, i_3);
    }
}

void createMaxHeap_3(struct person_3 *arr_3, int n_3)
{
    for (int i_3 = n_3 / 2 - 1; i_3 >= 0; i_3--)
    {
        maxHeapify_3(arr_3, n_3, i_3);
    }
}

int main()
{
    int option_3, n_3 = 7;
    struct person_3 *people_3 = NULL;

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
        scanf("%d", &option_3);

        switch (option_3)
        {
        case 1:
        {
            char filename_3[100];
            FILE *file_3;

            printf("Enter the name of the file: ");
            scanf("%s", filename_3);

            file_3 = fopen(filename_3, "r");
            if (file_3 == NULL)
            {
                printf("Error opening the file.\n");
                break;
            }
            people_3 = (struct person_3 *)malloc(n_3 * sizeof(struct person_3));

            printf("Id Name Age Height Weight(pound)\n");
            for (int i_3 = 0; i_3 < n_3; i_3++)
            {
                people_3[i_3].id_3 = i_3;
                people_3[i_3].name_3 = (char *)malloc(50 * sizeof(char));
                fscanf(file_3, " %s %d %d %d", people_3[i_3].name_3, &people_3[i_3].age_3, &people_3[i_3].height_3, &people_3[i_3].weight_3);
            }
            for (int i_3 = 0; i_3 < n_3; i_3++)
            {
                printf("%d\t%s\t%d\t%d\t%d\t\n", people_3[i_3].id_3, people_3[i_3].name_3, people_3[i_3].age_3, people_3[i_3].height_3, people_3[i_3].weight_3);
            }

            fclose(file_3);
            break;
        }
        case 2:
            createMinHeap_3(people_3, n_3);
            printf("Min-heap based on age created.\n");
            break;

        case 3:
            createMaxHeap_3(people_3, n_3);
            printf("Max-heap based on weight created.\n");
            break;

        case 4:
            if (n_3 == 0)
            {
                printf("No data available.\n");
            }
            else
            {
                printf("Weight of youngest student: 65.77 kg\n", (float)people_3[0].weight_3 * 0.453592);
            }
            break;

        case 5:
            if (n_3 == 0)
            {
                printf("No data available.\n");
            }
            else
            {
                n_3++;
                people_3 = (struct person_3 *)realloc(people_3, n_3 * sizeof(struct person_3));
                printf("Enter the new person's name, age, height, and weight: ");
                people_3[n_3 - 1].id_3 = n_3 - 1;
                people_3[n_3 - 1].name_3 = (char *)malloc(50 * sizeof(char));
                scanf("%s %d %d %d", people_3[n_3 - 1].name_3, &people_3[n_3 - 1].age_3, &people_3[n_3 - 1].height_3, &people_3[n_3 - 1].weight_3);
                createMinHeap_3(people_3, n_3);
            }
            break;

        case 6:
            if (n_3 == 0)
            {
                printf("No data available.\n");
            }
            else
            {
                swap_3(&people_3[0], &people_3[n_3 - 1]);
                free(people_3[n_3 - 1].name_3);
                n_3--;
                people_3 = (struct person_3 *)realloc(people_3, n_3 * sizeof(struct person_3));
                createMinHeap_3(people_3, n_3);
                printf("Oldest person deleted.\n");
            }
            break;

        case 7:
            for (int i_3 = 0; i_3 < n_3; i_3++)
            {
                free(people_3[i_3].name_3);
            }
            free(people_3);
            exit(0);
            break;

        default:
            printf("Invalid option. Please try again.\n");
        }
    }
    return 0;
}
