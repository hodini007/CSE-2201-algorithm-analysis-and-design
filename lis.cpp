#include <bits/stdc++.h>
using namespace std;
vector<int> findLIS(const vector<int>& nums) {
    if (nums.empty()) return {};

    vector<int> tailIndices;
    vector<int> previous(nums.size(), -1);

    for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
        auto it = lower_bound(
            tailIndices.begin(), tailIndices.end(), nums[i],
            [&nums](int index, int value) { return nums[index] < value; });
        int position = it - tailIndices.begin();

        if (position > 0) {
            previous[i] = tailIndices[position - 1];
        }

        if (it == tailIndices.end()) {
            tailIndices.push_back(i);
        } else {
            *it = i;
        }
    }

    vector<int> sequence;
    for (int index = tailIndices.back(); index != -1;
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


