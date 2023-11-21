/*Write a program to find the maximum profit nearest to but not
exceeding the given knapsack capacity using the Fractional Knapsack algorithm.
Declare a structure ITEM having data members item_id_3, item_profit_3, item_weight_3 and
profit_weight_ratio_3.take the input by user defined methodand Apply heap sort technique to sort the items_3 in non-increasing order,
according to their (profit /weight).*/
#include <stdio.h>
#include <stdlib.h>

struct ITEM
{
    int item_id_3;
    float item_profit_3;
    float item_weight_3;
    float profit_weight_ratio_3;
    float amount_taken_3;
};
void minHeapify(struct ITEM *items_3, int n, int i)
{
    int smallest_3 = i;
    int left_3 = 2 * i + 1;
    int right_3 = 2 * i + 2;

    if (left_3 < n && items_3[left_3].profit_weight_ratio_3 < items_3[smallest_3].profit_weight_ratio_3)
        smallest_3 = left_3;

    if (right_3 < n && items_3[right_3].profit_weight_ratio_3 < items_3[smallest_3].profit_weight_ratio_3)
        smallest_3 = right_3;

    if (smallest_3 != i)
    {
        struct ITEM temp_3 = items_3[i];
        items_3[i] = items_3[smallest_3];
        items_3[smallest_3] = temp_3;

        minHeapify(items_3, n, smallest_3);
    }
}

void buildMinHeap(struct ITEM *items_3, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        minHeapify(items_3, n, i);
    }
}

void heapSort(struct ITEM *items_3, int n)
{
    buildMinHeap(items_3, n);

    for (int i = n - 1; i > 0; i--)
    {
        struct ITEM temp_3 = items_3[0];
        items_3[0] = items_3[i];
        items_3[i] = temp_3;

        minHeapify(items_3, i, 0);
    }
}
void printHeap(struct ITEM *items_3, int n)
{

    for (int i = 0; i < n; i++)
    {
        printf("%d\t%6f\t%6f\t%6f\t%6f\n", items_3[i].item_id_3, items_3[i].item_profit_3, items_3[i].item_weight_3, items_3[i].profit_weight_ratio_3, items_3[i].amount_taken_3);
    }
    printf("\n");
}

int main()
{
    int n;
    printf("Enter the number of items_3: ");
    scanf("%d", &n);

    float knapsack_capacity_3;
    printf("Enter the knapsack capacity: ");
    scanf("%f", &knapsack_capacity_3);

    struct ITEM items_3[n];

    for (int i = 0; i < n; i++)
    {
        items_3[i].item_id_3 = i + 1;
        items_3[i].amount_taken_3 = 0.0;
        printf("Enter profit and weight for item %d: ", i + 1);
        scanf("%f %f", &items_3[i].item_profit_3, &items_3[i].item_weight_3);
        items_3[i].profit_weight_ratio_3 = items_3[i].item_profit_3 / items_3[i].item_weight_3;
    }
    printf("item_No\tProfit\t\tWeight\t\tProfit_ratio\tAmount to be taken\t\n");
    printHeap(items_3, n);

    heapSort(items_3, n);

    float current_weight_3 = 0.0;
    float maximum_profit_3 = 0.0;

    for (int i = 0; i < n; i++)
    {
        if (current_weight_3 + items_3[i].item_weight_3 <= knapsack_capacity_3)
        {
            current_weight_3 += items_3[i].item_weight_3;
            maximum_profit_3 += items_3[i].item_profit_3;
            items_3[i].amount_taken_3++;
        }
        else
        {
            items_3[i].amount_taken_3 = (knapsack_capacity_3 - current_weight_3) / items_3[i].item_weight_3;
            maximum_profit_3 += ((knapsack_capacity_3 - current_weight_3) / items_3[i].item_weight_3) * items_3[i].item_profit_3;
            break;
        }
    }
    printf("item_No\tProfit\t\tWeight\t\tProfit_ratio\tAmount to be taken\t\n");
    printHeap(items_3, n);
    printf("Maximum Profit: %.6f", maximum_profit_3);

    return 0;
}
