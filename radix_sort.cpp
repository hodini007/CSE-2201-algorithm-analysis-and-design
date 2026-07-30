#include<bits/stdc++.h>
using namespace std;

void radix_sort(vector<int>& arr) {
    int max_num = *max_element(arr.begin(), arr.end());
    for (int exp = 1; max_num / exp > 0; exp *= 10) {
        vector<int> output(arr.size());
        vector<int> count(10, 0);

        for (int i = 0; i < arr.size(); i++)
            count[(arr[i] / exp) % 10]++;

        for (int i = 1; i < 10; i++)
            count[i] += count[i - 1];

        for (int i = arr.size() - 1; i >= 0; i--) {
            output[count[(arr[i] / exp) % 10] - 1] = arr[i];
            count[(arr[i] / exp) % 10]--;
        }

        for (int i = 0; i < arr.size(); i++)
            arr[i] = output[i];
    }
}
int main(){


    vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};
    radix_sort(arr);
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    return 0;
}

