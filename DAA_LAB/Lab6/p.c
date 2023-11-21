#include <stdio.h>
#include <stdlib.h>

// Structure to represent an item
struct Item {
    int weight;
    int value;
    double value_to_weight_ratio;
};

// Function to compare items based on their value-to-weight ratio
int compareItems(const void *a, const void *b) {
    struct Item *itemA = (struct Item *)a;
    struct Item *itemB = (struct Item *)b;
    if (itemA->value_to_weight_ratio > itemB->value_to_weight_ratio) {
        return -1; // Sort in descending order
    } else if (itemA->value_to_weight_ratio < itemB->value_to_weight_ratio) {
        return 1;
    } else {
        return 0;
    }
}

// Function to find the maximum profit using Fractional Knapsack algorithm
double fractionalKnapsack(struct Item items[], int n, int capacity) {
    // Calculate the value-to-weight ratio for each item
    for (int i = 0; i < n; i++) {
        items[i].value_to_weight_ratio = (double)items[i].value / items[i].weight;
    }

    // Sort items based on the value-to-weight ratio
    qsort(items, n, sizeof(struct Item), compareItems);

    double totalProfit = 0.0;
    int currentWeight = 0;

    for (int i = 0; i < n; i++) {
        if (currentWeight + items[i].weight <= capacity) {
            // Take the whole item
            currentWeight += items[i].weight;
            totalProfit += items[i].value;
        } else {
            // Take a fraction of the item
            double remainingCapacity = capacity - currentWeight;
            totalProfit += remainingCapacity * items[i].value_to_weight_ratio;
            break; // Knapsack is full
        }
    }

    return totalProfit;
}

int main() {
    int n;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    struct Item items[n];
    for (int i = 0; i < n; i++) {
        printf("Enter weight and value for item %d: ", i + 1);
        scanf("%d %d", &items[i].weight, &items[i].value);
        items[i].value_to_weight_ratio = 0.0;
    }

    int capacity;
    printf("Enter the knapsack capacity: ");
    scanf("%d", &capacity);

    double maxProfit = fractionalKnapsack(items, n, capacity);

    printf("Maximum profit: %lf\n", maxProfit);

}
