#include <stdio.h>
#include <stdlib.h>


struct Item {
    int item_id;
    double item_profit;
    double item_weight;
    double profit_weight_ratio;
};

void swap(struct Item *a, struct Item *b) {
    struct Item temp = *a;
    *a = *b;
    *b = temp;
}


void maxHeapify(struct Item arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left].profit_weight_ratio > arr[largest].profit_weight_ratio) {
        largest = left;
    }

    if (right < n && arr[right].profit_weight_ratio > arr[largest].profit_weight_ratio) {
        largest = right;
    }

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        maxHeapify(arr, n, largest);
    }
}


void heapSort(struct Item arr[], int n) {

    for (int i = n / 2 - 1; i >= 0; i--) {
        maxHeapify(arr, n, i);
    }



}

double fractionalKnapsack(struct Item arr[], int n, double capacity) {

    heapSort(arr, n);

    double maxProfit = 0.0;
    double currentWeight = 0.0;

    for (int i = 0; i < n; i++) {
        if (currentWeight + arr[i].item_weight <= capacity) {
            currentWeight += arr[i].item_weight;
            maxProfit += arr[i].item_profit;
        } else {
            double remainingCapacity = capacity - currentWeight;
            maxProfit += (arr[i].profit_weight_ratio * remainingCapacity);
            break;
        }
    }

    return maxProfit;
}

int main() {
    int n;
    double capacity;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    struct Item *items = (struct Item *)malloc(n * sizeof(struct Item));

    for (int i = 0; i < n; i++) {
        items[i].item_id = i + 1;

        printf("Enter profit and weight for item %d: ", i + 1);
        scanf("%lf %lf", &items[i].item_profit, &items[i].item_weight);

        items[i].profit_weight_ratio = ((items[i].item_profit )/( items[i].item_weight));
    }

    printf("Enter the knapsack capacity: ");
    scanf("%lf", &capacity);

    double maxProfit = fractionalKnapsack(items, n, capacity);

    printf("Maximum profit: %.2lf\n", maxProfit);

    free(items);

    return 0;
}

