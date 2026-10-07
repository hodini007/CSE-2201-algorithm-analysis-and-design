#include <bits/stdc++.h>
using namespace std;

int main() {
    string x = "abc";
    string y = "acd";
    int m = x.length();
    int n = y.length();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (x[i - 1] == y[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    string sequence;
    int i = m;
    int j = n;

    while (i > 0 && j > 0) {
        if (x[i - 1] == y[j - 1]) {
            sequence += x[i - 1];
            --i;
            --j;
        } else if (dp[i - 1][j] >= dp[i][j - 1]) {
            --i;
        } else {
            --j;
        }
    }

    reverse(sequence.begin(), sequence.end());

    cout << "Length: " << dp[m][n] << '\n';
    cout << "Sequence: " << sequence << '\n';
    return 0;
}