// K-Ordered Longest Common Subsequence
// Dynamic Programming
/*
 *  Variation of Normal LCS:
 *      There is just one added condition that needs to be taken into consideration.
 *      We will solve it using MEMORIZATION instead of Pure DP.
 *      Will solve it using a 3D array
 *      O(N*M*K)
 */

// https://www.geeksforgeeks.org/longest-common-subsequence-with-at-most-k-changes-allowed/

#include<bits/stdc++.h>

using namespace std;

// 3-D DP ARRAY
int dp[2005][2005][8];  // row column and value of k

int dpSol(int arr1[], int arr2[], int size1, int size2, int i, int j, int k) {
    // base case :: if we exceed any of the arrays
    if (size1 == i || size2 == j) {
        // if the arrays are finished
        return 0;
    }
    // MEMORIZATION
    if (dp[i][j][k] != -1) {
        return dp[i][j][k];
    }

    // Other cases
    int res = INT_MIN;
    if (arr1[i] == arr2[j]) {
        // means the char of the string match thus, return 1 and move both the pointers
        res = 1 + dpSol(arr1, arr2, size1, size2, i + 1, j + 1, k);
    } else {
        // 3 cases
        if (k > 0) {
            // then we can try to replace this position's char in order to try to match i the chars
            res = 1 + dpSol(arr1, arr2, size1, size2, i + 1, j + 1, k - 1);
        } else {
            // left 2 options
            res = max(res, max(dpSol(arr1, arr2, size1, size2, i, j + 1, k), dpSol(arr1, arr2, size1, size2, i + 1, j, k)));
        }
    }
    dp[i][j][k] = res;
    return dp[i][j][k];
}

int main() {
    // input
    int size1, size2, k;

    cin >> size1 >> size2 >> k;
    int arr[size1 + 1];
    int arr2[size2 + 1];
    for (int i = 0; i < size1; i++)
        cin >> arr[i];
    for (int i = 0; i < size2; i++)
        cin >> arr2[i];

    // set all the values of dp table initially as -1 as they aren't yet memorized
    memset(dp, -1, sizeof(dp));

    // call the function
    int ans = dpSol(arr, arr2, size1, size2, 0, 0, k);
    cout << ans << endl;

    return 0;
}