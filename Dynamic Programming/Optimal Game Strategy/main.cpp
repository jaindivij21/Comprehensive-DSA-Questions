// Dynamic Programming :: Optimal Game
// https://www.geeksforgeeks.org/optimal-strategy-for-a-game-dp-31/
// https://www.youtube.com/watch?v=ww4V7vRIzSk

/*
 *  Greedy wont work here, rather dynamic programming. Will try to use top down approach using recursion. Greedy might help you win (as shown in the video) but
 *  its only the dp solution that will ensure that you'll win and at the same time have an optimal (max) solution. We'll use a bottom up approach!
 */

#include<bits/stdc++.h>

using namespace std;

int optimalStrategy(int n, int arr[]) {
    // dp table
    int dp[n][n];
    memset(dp, -1, sizeof(dp));

    for (int d = 0; d < n; d++) {
        // for each diagonal
        for (int i = 0, j = d; j < n; i++, j++) {
            // traversing through each diagonal ignoring the lower half
            if (d == 0) {
                // first diagonal
                dp[i][j] = arr[i];
            } else if (d == 1) {
                // second diagonal
                dp[i][j] = max(arr[i], arr[j]);
            } else {
                // other diagonals
                int val1 = arr[i] + min(dp[i + 1][j - 1], dp[i + 2][j]);
                int val2 = arr[j] + min(dp[i][j-2], dp[i+1][j-1]);
                dp[i][j] = max(val1, val2);
            }
        }
    }
    // return the answer
    return dp[0][n - 1];
}

int main() {
    // input array and array size
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // call the function
    cout << optimalStrategy(n, arr);

    return 0;
}