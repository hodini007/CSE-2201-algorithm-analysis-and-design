#include<bits/stdc++.h>
using namespace std;
typedef vector<pair<int, int>> vct;
double knapsac(vct item, int capacity, vector<double>& fraction) {
    vector<pair<double, int>> ratio;
    for (int i = 0; i < item.size(); i++) {
        double currentRatio = static_cast<double>(item[i].first) / item[i].second;
        ratio.push_back(make_pair(currentRatio, i));
    }

    sort(ratio.rbegin(), ratio.rend());

    vct after;
    for (int i = 0; i < ratio.size(); i++) {
        after.push_back(item[ratio[i].second]);
    }

    fraction.assign(item.size(), 0.0);
    double remaining = capacity;
    double total = 0;

    for (int i = 0; i < after.size(); i++) {
        if (remaining == 0) {
            break;
        }

        int originalIndex = ratio[i].second;
        int value = after[i].first;
        int weight = after[i].second;

        if (weight <= remaining) {
            fraction[originalIndex] = 1;
            remaining -= weight;
            total += value;
        } else {
            fraction[originalIndex] = remaining / weight;
            total += fraction[originalIndex] * value;
            remaining = 0;
        }
    }

    return total;
}

int main() {
    vct items = {{54, 9}, {48, 6}, {70, 14}, {35, 5}, {77, 11}, {44, 8}};
    int capacity = 27;
    vector<double> fractions;

    double totalValue = knapsac(items, capacity, fractions);

    cout << fixed << setprecision(2);
    cout << "Total value: " << totalValue << '\n';
    for (int i = 0; i < fractions.size(); i++) {
        cout << "Item " << i + 1 << " fraction: " << fractions[i] << '\n';
    }
}