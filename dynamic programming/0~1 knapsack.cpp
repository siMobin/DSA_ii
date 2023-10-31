#include <iostream>
#include <vector>

using namespace std;

// Structure to represent an item with weight and value
struct Item
{
    int weight;
    int value;
};

// Function to solve the 0/1 knapsack problem
int knapsack(vector<Item> &items, int capacity)
{
    int n = items.size();
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int w = 0; w <= capacity; w++)
        {
            if (items[i - 1].weight > w)
            {
                dp[i][w] = dp[i - 1][w];
            }
            else
            {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - items[i - 1].weight] + items[i - 1].value);
            }
        }
    }

    // Reconstruct the selected items
    int w = capacity;
    vector<Item> selectedItems;
    for (int i = n; i > 0 && w > 0; i--)
    {
        if (dp[i][w] != dp[i - 1][w])
        {
            selectedItems.push_back(items[i - 1]);
            w -= items[i - 1].weight;
        }
    }

    // Print the selected items
    cout << "Selected items:" << endl;
    for (int i = selectedItems.size() - 1; i >= 0; i--)
    {
        cout << "Weight: " << selectedItems[i].weight << ", Profit: " << selectedItems[i].value << endl;
    }

    return dp[n][capacity];
}

int main()
{
    vector<Item> items =
        {
            {10, 60},
            {20, 100},
            {30, 120},
        };

    int capacity = 50;

    int maxValue = knapsack(items, capacity);
    cout << "\nMaximum profit: " << maxValue << endl;

    return 0;
}
