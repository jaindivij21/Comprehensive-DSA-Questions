// Dynamic Programming :: Robots anb Paths
// Will solve using 2d DP Table i.e. bottom up approach
// https://www.codechef.com/problems/CD1IT4

#include<bits/stdc++.h>

#define MOD 1000000007

using namespace std;

int dp[1001][1001];

int numWays(int rows, int cols) {
    // base case
    if (dp[0][0] == -1)
        return 0;   // no way to go to the end
    // initiate first row and first column with 1 :: because number of ways to reach them is just one since we can only move in 2 direction that are right or bottom!
    for (int j = 0; j < cols; j++) {
        if (dp[0][j] == -1)
            break;
        dp[0][j] = 1;
    }
    for (int i = 0; i < rows; i++) {
        if (dp[i][0] == -1)
            break;
        dp[i][0] = 1;
    }

    // Bottom Up approach for the rest of the dp table
    for (int i = 1; i < rows; i++) {
        for (int j = 1; j < cols; j++) {
            // if the cell is blocked leave it
            if (dp[i][j] == -1)
                continue;
            // ELSE, add the top and left cells
            dp[i][j] = 0;
            if (dp[i][j - 1] != -1) {
                dp[i][j] = dp[i][j - 1] % MOD;
            }
            if (dp[i - 1][j] != -1) {
                dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
            }
        }
    }
    if (dp[rows - 1][cols - 1] == -1)
        return 0;
    return dp[rows - 1][cols - 1];
}

int main() {
    memset(dp, 0, sizeof(dp));

    // input the data
    int M, N, P;
    cin >> M >> N >> P;

    // input the blocked places :: remember, in the ques the grid starts from 1,1 and not 0,0
    for (int i = 0; i < P; i++) {
        int x, y;
        cin >> x >> y;
        dp[x - 1][y - 1] = -1;
    }

    // main function call
    cout << numWays(M, N) << endl;

    return 0;
}