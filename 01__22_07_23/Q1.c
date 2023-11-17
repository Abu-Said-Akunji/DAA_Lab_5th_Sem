#include <stdio.h>
int main()
{
    int n, temp;
    printf("enter the nummer of integers: ");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    temp = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > temp)
        {
            temp = arr[i];
        }
    }
    int l = temp;
    temp = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > temp && arr[i] < l)
        {
            temp = arr[i];
        }
    }
    printf("Second Largest: %d \n", temp);
    temp = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < temp)
        {
            temp = arr[i];
        }
    }
    int s = temp;
    printf("%d", s);
    temp = l;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < temp && arr[i] > s)
        {
            temp = arr[i];
        }
    }
    printf("Second Smallest: %d", temp);

    return 0;
}