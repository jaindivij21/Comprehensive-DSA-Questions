// Unique Path :: Leetcode
// https://leetcode.com/problems/unique-paths/

#include<bits/stdc++.h>

using namespace std;

int uniquePaths(int m, int n) {
    // Dynamic Programming :: Bottom Up Approach

    // dp table
    int dp[m][n];

    // fill in the first row and column as 1 since the robot can move only right or down
    for (int i = 0; i < m; i++) {
        dp[i][0] = 1;   // make the first col as 1
    }
    for (int i = 0; i < n; i++) {
        dp[0][i] = 1;   // make the first col as 1
    }

    // main logic
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }

    return dp[m - 1][n - 1];
}

int main() {
    int m, n;
    cin >> m >> n;

    int ans = uniquePaths(m, n);

    cout << ans;

    return 0;
}