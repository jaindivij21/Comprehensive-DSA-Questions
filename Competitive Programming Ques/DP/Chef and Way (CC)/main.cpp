// Chef and Way
// https://www.codechef.com/problems/CHRL4

// Dynamic Programming

// WRONG SOLN


#include<bits/stdc++.h>

#define MOD 1000000007
using namespace std;

long long int chefWay(long long int n, long long int k, const long long int arr[]) {
    // follow 1D bottom up approach
    long long int dp[n + 1];  // represents min cost to travel
    dp[0] = -1;
    dp[1] = arr[1];

    // fill the dp table
    for (long long int i = 2; i <= n; i++) {
        dp[i] = LONG_LONG_MAX;
        long long int j = i - 1;
        while (j >= 1) {
            if (arr[i] - arr[j] >= 1 && arr[i] - arr[j] <= k) {
                // there is a possible path
                dp[i] = min(dp[i], ((arr[i] % MOD) * (arr[j] % MOD)) % MOD);
            }
            j--;
        }
    }
    return dp[n];
}

int main() {
    long long int nthStreet;
    cin >> nthStreet;
    long long int k;
    cin >> k;

    long long int arr[nthStreet + 1];
    arr[0] = -1;
    for (long long int i = 1; i <= nthStreet; i++)
        cin >> arr[i];

    long long int ans = chefWay(nthStreet, k, arr);

    cout << ans << endl;

    return 0;
}