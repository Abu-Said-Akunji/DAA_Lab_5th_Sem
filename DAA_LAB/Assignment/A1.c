#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void mergeArrays(int arr1[], int arr2[], int n1, int n2, int arr3[])
{
    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2)
    {
        if (arr1[i] < arr2[j])
            arr3[k++] = arr1[i++];
        else
            arr3[k++] = arr2[j++];
    }
    while (i < n1)
        arr3[k++] = arr1[i++];
    while (j < n2)
        arr3[k++] = arr2[j++];
}

int main()
{
    int arr1[20], arr2[20], arr3[100], arr4[100];
    int n1 = 0, n2 = 0, n3 = 0, n4 = 0;

    FILE *panel1 = fopen("panel1.txt", "r");
    while (fscanf(panel1, "%d", &arr1[n1]) != EOF)
    {
        n1++;
    }
    fclose(panel1);
    bubbleSort(arr1, n1);

    FILE *panel2 = fopen("panel2.txt", "r");
    while (fscanf(panel2, "%d", &arr2[n2]) != EOF)
    {
        n2++;
    }
    fclose(panel2);
    bubbleSort(arr2, n2);

    FILE *panel3 = fopen("panel3.txt", "r");
    while (fscanf(panel3, "%d", &arr3[n3]) != EOF)
    {
        n3++;
    }
    fclose(panel3);
    bubbleSort(arr3, n3);

    FILE *panel4 = fopen("panel4.txt", "r");
    while (fscanf(panel4, "%d", &arr4[n4]) != EOF)
    {
        n4++;
    }
    fclose(panel4);
    bubbleSort(arr4, n4);

    int a1[200], a2[200], a3[400], result[10];
    mergeArrays(arr1, arr2, n1, n2, a1);
    mergeArrays(arr3, arr4, n3, n4, a2);
    mergeArrays(a1, a2, (n1 + n2), (n3 + n4), a3);

    int Size = n1 + n2 + n3 + n4;
    int c = 0;
    for (int i = 0; i < Size; i++)
    {
        int k = 0;
        for (int j = 0; j < Size; j++)
        {
            if ((j >= i) && a3[j] == a3[i])
            {
                k++;
            }
        }
        if (k >= 3 && (a3[i - 1] != a3[i] && (a3[i - 2] != a3[i]) && (a3[i - 3] != a3[i])))
        {
            result[c++] = a3[i];
        }
    }

    printf("%d students are selected having roll no.s", c);
    for (int i = 0; i < c; i++)
    {
        printf(" %d", result[i]);
    }
    printf(".\n");

    return 0;
}
