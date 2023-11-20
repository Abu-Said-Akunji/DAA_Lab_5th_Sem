#include <stdio.h>
int main()
{
    int n_3, temp_3;
    printf("enter the nummer of integers: ");
    scanf("%d", &n_3);
    int arr_3[n_3];
    for (int i_3 = 0; i_3 < n_3; i_3++)
    {
        scanf("%d", &arr_3[i_3]);
    }
    temp_3 = arr_3[0];
    for (int i_3 = 0; i_3 < n_3; i_3++)
    {
        if (arr_3[i_3] > temp_3)
        {
            temp_3 = arr_3[i_3];
        }
    }
    int l_3 = temp_3;
    temp_3 = arr_3[0];
    for (int i_3 = 0; i_3 < n_3; i_3++)
    {
        if (arr_3[i_3] > temp_3 && arr_3[i_3] < l_3)
        {
            temp_3 = arr_3[i_3];
        }
    }
    printf("Second Largest: %d \n", temp_3);
    temp_3 = arr_3[0];
    for (int i_3 = 0; i_3 < n_3; i_3++)
    {
        if (arr_3[i_3] < temp_3)
        {
            temp_3 = arr_3[i_3];
        }
    }
    int s_3 = temp_3;
    printf("%d", s_3);
    temp_3 = l_3;
    for (int i_3 = 0; i_3 < n_3; i_3++)
    {
        if (arr_3[i_3] < temp_3 && arr_3[i_3] > s_3)
        {
            temp_3 = arr_3[i_3];
        }
    }
    printf("Second Smallest: %d", temp_3);

    return 0;
}