#include <bits/stdc++.h>
using namespace std;
vector<int> findLIS(const vector<int>& nums) {
    if (nums.empty()) return {};

    int n = nums.size();
    vector<int> dp(n, 1);
    vector<int> previous(nums.size(), -1);
    int lastIndex = 0;

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[i] > nums[j] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
                previous[i] = j;
            }
        }
        if (dp[i] > dp[lastIndex]) {
            lastIndex = i;
        }
    }

    vector<int> sequence;
    for (int index = lastIndex; index != -1;
         index = previous[index]) {
        sequence.push_back(nums[index]);
    }
    reverse(sequence.begin(), sequence.end());
    return sequence;
}

int main() {
    vector<int> arr = {10, 22, 9, 33, 21, 50, 41, 60};
    vector<int> sequence = findLIS(arr);

    cout << "Length of LIS: " << sequence.size() << endl;
    cout << "LIS: ";
    for (int value : sequence) {
        cout << value << ' ';
    }
    cout << endl;
    return 0;
}


