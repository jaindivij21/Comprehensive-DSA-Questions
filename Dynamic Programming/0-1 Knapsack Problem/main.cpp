// Dynamic Programming :: 0-1 Knapsack Problem
// https://www.youtube.com/watch?v=bUSaenttI24

// bottom up DP :: very similar to target subset sum

#include<bits/stdc++.h>

using namespace std;

int knapsack(int k, int v[], int w[], int n) {
    // dp table
    int dp[n + 1][k + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < k + 1; j++) {
            if (j >= w[i - 1]) {
                // there is a possibility of including i
                int rCap = j - w[i - 1];   // index with remaining capacity
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][rCap] + v[i - 1]);
            } else {
                // there is no possibility of including i
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][k];
}

int main() {
    int n;
    cout << "Enter the number of items" << endl;
    cin >> n;

    cout << "Enter the profits and weights array" << endl;
    int wts[n];
    int profits[n];

    for (int i = 0; i < n; i++) {
        cin >> profits[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> wts[i];
    }

    cout << "Enter capacity" << endl;
    int k;
    cin >> k;

    cout << "The max profit that's possible is " << knapsack(k, profits, wts, n);

    return 0;
}