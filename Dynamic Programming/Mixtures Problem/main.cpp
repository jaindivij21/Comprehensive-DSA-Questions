// Dynamic Programming :: Mixtures
// https://www.spoj.com/problems/MIXTURES/
// https://www.youtube.com/watch?v=XHjjIJxnAJY&ab_channel=CodingBlocks
/*
 *  This is an optimal merge pattern like problem where we have to mix the solutions such that the smoke is minimized. Also very similar to matrix multiplication.
 *  Here in this problem we will use top town approach or memorization in normal recursion.
 */

#include<bits/stdc++.h>

using namespace std;

int arr[1000];
long long dp[1000][1000];

long long sum(int s, int e) {
    long long ans = 0;
    for (int i = s; i <= e; i++) {
        ans += arr[i];
        ans %= 100;
    }
    return ans;
}

long long solveMix(int i, int j) {
    // base case :: if only one element is left, then they cannot be combined hence smoke will be 0
    if (i >= j)
        return 0;
    // if the ans is already there : memorization
    if (dp[i][j] != -1) {
        return dp[i][j];
    }
    // other cases : we have to break the expression at every possible k; basically into 2 parts 
    dp[i][j] = INT_MAX; // we'll minimize it
    for (int k = i; k <= j; k++) {
        dp[i][j] = min(dp[i][j], (solveMix(i, k) + solveMix(k + 1, j) + sum(i, k) * sum(k + 1, j)));
    }
    return dp[i][j];
}

int main() {
    int n;
    cin >> n;
    // read n integers
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    // init dp with -1
    memset(dp, -1, sizeof(dp));

    cout << solveMix(0, n - 1) << endl;
    return 0;
}