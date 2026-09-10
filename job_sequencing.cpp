#include<bits/stdc++.h>
using namespace std;

typedef vector<pair<int, int>> vct;
double knapsac(vct items, int max_deadline) {
    sort(items.begin(),items.end());
    int n = items.size();
    vector<int> result(max_deadline, -1);
    int total_profit = 0;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = min(max_deadline - 1, items[i].second - 1); j >= 0; j--) {
            if (result[j] == -1) {
                result[j] = i;
                total_profit += items[i].first;
                break;
            }
        }
    }
    return total_profit;
}

int main(){

    vct items = {{20,2}, {15,2}, {10,1}, {5,3},{1,3}};
    int max_deadline = 3;
    double total_profit = knapsac(items, max_deadline);
    cout << "Total profit: " << total_profit << endl;



}