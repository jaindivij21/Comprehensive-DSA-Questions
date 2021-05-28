// Dynamic Programming : Longest Increasing Subsequence
/*
 *  Writing a recursive problem for the same is quite challenging, therefore we directly think about DP.
 *  We'll do this using 1-D DP table i.e. bottom up approach. We will keep track of the maximum numbers in the increasing subsequence up til that index and store it.
 *  Now next time a we need to add a number to the subseq, just add 1 to the index of the prev max *possible* subsequence number.
 */

#include<bits/stdc++.h>

using namespace std;

int lis(int arr[], int n) {
    int dp[100];    // make the dp table

    int ans = -1;   // stores the ans to be returned

    // base case :: set all the elements as 1 since each of them individually are increasing subsequences
    for (int i = 0; i < n; i++)
        dp[i] = 1;
    // main part
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[j] <= arr[i]) {
                // means they can be a part of the increasing subsequence
                int curLen = 1 + dp[j];
                dp[i] = max(curLen, dp[i]);
            }
        }
        ans = max(ans, dp[i]);
    }
    return ans;
}

int main() {
    int arr[100];
    // size of array
    int n;
    cin >> n;
    // input the array
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int ans = lis(arr, n);
    cout << "The largest increasing subsequence in the given array has " << ans << " number of elements." << endl;

    return 0;
}
