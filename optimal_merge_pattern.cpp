#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int minMergeCost(const vector<int>& files) {
    if (files.size() <= 1) return 0;

    // Min-heap to store file sizes
    priority_queue<int, vector<int>, greater<int>> minHeap;

    // Insert all files into the min-heap
    for (int size : files) {
        minHeap.push(size);
    }

    int totalCost = 0;

    // Keep combining the two smallest files
    while (minHeap.size() > 1) {
        int first = minHeap.top();
        minHeap.pop();

        int second = minHeap.top();
        minHeap.pop();

        int currentMergeCost = first + second;
        totalCost += currentMergeCost;

        // Push the merged file back into the heap
        minHeap.push(currentMergeCost);
    }

    return totalCost;
}

int main() {
    vector<int> files = {2, 3, 4, 5, 6, 7};

    cout << "Minimum Merge Cost: " << minMergeCost(files) << "\n";
    // Output: 68
    return 0;
}