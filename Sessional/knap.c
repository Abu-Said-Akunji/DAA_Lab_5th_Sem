#include <stdio.h>
#include <stdlib.h>

struct ITEM
{
    int item_id;
    float item_profit;
    float item_weight;
    float profit_weight_ratio;
    float amount_taken;
};
void minHeapify(struct ITEM *items, int n, int i)
{
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && items[left].profit_weight_ratio < items[smallest].profit_weight_ratio)
        smallest = left;

    if (right < n && items[right].profit_weight_ratio < items[smallest].profit_weight_ratio)
        smallest = right;

    if (smallest != i)
    {
        struct ITEM temp = items[i];
        items[i] = items[smallest];
        items[smallest] = temp;

        minHeapify(items, n, smallest);
    }
}

void buildMinHeap(struct ITEM *items, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        minHeapify(items, n, i);
    }
}

void heapSort(struct ITEM *items, int n)
{
    buildMinHeap(items, n);

    for (int i = n - 1; i > 0; i--)
    {
        struct ITEM temp = items[0];
        items[0] = items[i];
        items[i] = temp;

        minHeapify(items, i, 0);
    }
}
void printHeap(struct ITEM *items, int n)
{

    for (int i = 0; i < n; i++)
    {
        printf("%d\t%6f\t%6f\t%6f\t%6f\n", items[i].item_id, items[i].item_profit, items[i].item_weight, items[i].profit_weight_ratio, items[i].amount_taken);
    }
    printf("\n");
}

int main()
{
    int n;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    float knapsack_capacity;
    printf("Enter the knapsack capacity: ");
    scanf("%f", &knapsack_capacity);

    struct ITEM items[n];

    for (int i = 0; i < n; i++)
    {
        items[i].item_id = i + 1;
        items[i].amount_taken = 0.0;
        printf("Enter profit and weight for item %d: ", i + 1);
        scanf("%f %f", &items[i].item_profit, &items[i].item_weight);
        items[i].profit_weight_ratio = items[i].item_profit / items[i].item_weight;
    }
    printf("item_No\tProfit\t\tWeight\t\tProfit_ratio\tAmount to be taken\t\n");
    printHeap(items, n);

    heapSort(items, n);

    float current_weight = 0.0;
    float maximum_profit = 0.0;

    for (int i = 0; i < n; i++)
    {
        if (current_weight + items[i].item_weight <= knapsack_capacity)
        {
            current_weight += items[i].item_weight;
            maximum_profit += items[i].item_profit;
            items[i].amount_taken++;
        }
        else
        {
            items[i].amount_taken = (knapsack_capacity - current_weight) / items[i].item_weight;
            maximum_profit += ((knapsack_capacity - current_weight) / items[i].item_weight) * items[i].item_profit;
            break;
        }
    }
    printf("item_No\tProfit\t\tWeight\t\tProfit_ratio\tAmount to be taken\t\n");
    printHeap(items, n);
    printf("Maximum Profit: %.6f", maximum_profit);

    return 0;
}
