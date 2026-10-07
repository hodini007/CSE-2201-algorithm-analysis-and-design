#include <bits/stdc++.h>
using namespace std;

int knapsack2D(int W, const vector<int>& weights, const vector<int>& values,
               int n, vector<int>& selectedItems) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
    for (int i = 1; i <= n; ++i) {
        for (int w = 1; w <= W; ++w) {
            if (weights[i - 1] <= w) {
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], 
                                    dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    int remainingWeight = W;
    for (int i = n; i > 0; --i) {
        if (dp[i][remainingWeight] != dp[i - 1][remainingWeight]) {
            selectedItems.push_back(i - 1);
            remainingWeight -= weights[i - 1];
        }
    }
    reverse(selectedItems.begin(), selectedItems.end());

    return dp[n][W];
} 

int main() {
    vector<int> values = {60, 100, 120};
    vector<int> weights = {10, 20, 30};
    int W = 50;
    int n = values.size();

    vector<int> selectedItems;
    int maximumValue = knapsack2D(W, weights, values, n, selectedItems);

    cout << "Maximum value: " << maximumValue << endl;
    cout << "Selected items:\n";
    for (int index : selectedItems) {
        cout << "Item " << index + 1 << ": weight = " << weights[index]
             << ", value = " << values[index] << endl;
    }
    return 0;
}
