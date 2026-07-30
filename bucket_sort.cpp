#include<bits/stdc++.h>
using namespace std;


void insertion_sort(vector<float>&buck)
{
    for (int i = 1; i < buck.size(); ++i) {
        float key = buck[i];
        int j = i - 1;
        while (j >= 0 && buck[j] > key) {
            buck[j + 1] = buck[j];
            j--;
        }
        buck[j + 1] = key;
    }
}


void bucketSort(float arr[], int n) {
    vector<float> b[n];

    for (int i = 0; i < n; i++) {
        int bi = n * arr[i];
        b[bi].push_back(arr[i]);
    }

    for (int i = 0; i < n; i++) {
        insertion_sort(b[i]);
    }

    int index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < b[i].size(); j++) {
            arr[index++] = b[i][j];
        }
    }
}

int main() {
    float arr[] = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};
    int n = sizeof(arr) / sizeof(arr[0]);
    bucketSort(arr, n);

    cout << "Sorted array is \n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}

