#include <bits/stdc++.h>
using namespace std;

// Define a structure to represent each item
struct Item
{
    int item_id;
    double item_profit;
    double item_weight;
    double profit_weight_ratio;
};

// Function to compare two items based on their profit/weight ratio
bool compareItems(const Item &a, const Item &b)
{
    return a.profit_weight_ratio > b.profit_weight_ratio;
}

int main()
{
    int num_items;
    cout << "Enter the number of items: ";
    cin >> num_items;

    vector<Item> items(num_items);

    // Input the item details
    for (int i = 0; i < num_items; i++)
    {
        items[i].item_id = i + 1;
        cout << "Enter the profit and weight of item no " << i + 1 << ": ";
        cin >> items[i].item_profit >> items[i].item_weight;
        items[i].profit_weight_ratio = items[i].item_profit / items[i].item_weight;
    }

    double knapsack_capacity;
    cout << "Enter the capacity of knapsack: ";
    cin >> knapsack_capacity;

    // Sort items based on their profit/weight ratio in non-increasing order
    sort(items.begin(), items.end(), compareItems);

    double total_profit = 0.0;
    double remaining_capacity = knapsack_capacity;

    cout << "\nItem No\tProfit\tWeight\tAmount to be taken" << endl;

    for (int i = 0; i < num_items; i++)
    {
        if (remaining_capacity >= items[i].item_weight)
        {
            // Take the whole item
            cout << items[i].item_id << "\t" << items[i].item_profit << "\t" << items[i].item_weight << "\t1.000000" << endl;
            total_profit += items[i].item_profit;
            remaining_capacity -= items[i].item_weight;
        }
        else
        {
            // Take a fraction of the item
            double fraction = remaining_capacity / items[i].item_weight;
            cout << items[i].item_id << "\t" << items[i].item_profit << "\t" << items[i].item_weight << "\t" << fixed << setprecision(6) << fraction << endl;
            total_profit += fraction * items[i].item_profit;
            break; // Knapsack is full
        }
    }

    cout << "Maximum profit: " << fixed << setprecision(6) << total_profit << endl;

    return 0;
}
