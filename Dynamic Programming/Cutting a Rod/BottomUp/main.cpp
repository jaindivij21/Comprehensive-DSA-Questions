// Dynamic Programming : Cutting a Rod
// https://www.geeksforgeeks.org/cutting-a-rod-dp-13/
// Only recursion TC : len^n --> DP: TC = O(n2)
// Bottom Up Approach

#include<bits/stdc++.h>

using namespace std;

int maxProfit(int totalLen, int price[]) {
    int dp[100] = {};

    for (int len = 1; len <= totalLen; len++) {
        int best = 0;
        // trying to compute max Profit for every length of rod
        for (int cut = 1; cut <= len; cut++) {
            // for every possible length piece trying to compute all its options and thus the maxProfit possible on that length
            best = max(best, price[cut] + dp[len - cut]);
        }
        // store the best profit from all the possible cuts in dp[len]
        dp[len] = best;
    }
    // return total len's dp value
    return dp[totalLen];
}

int main() {
    // input the total len and cost of each len of rod
    int priceOfEachLen[100];
    int totalLen;

    cin >> totalLen;

    // start from index 1 :: since minimum length we can sell is 1
    priceOfEachLen[0] = 0;
    for (int i = 1; i <= totalLen; i++) {
        cin >> priceOfEachLen[i];
    }

    cout << "The max profit will be: " << maxProfit(totalLen, priceOfEachLen);

    return 0;
}