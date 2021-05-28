// Dynamic Programming : Cutting a Rod
// https://www.geeksforgeeks.org/cutting-a-rod-dp-13/
// Only recursion TC : len^n --> DP: TC = O()
// Normal recursion optimized by memorization due to presence of overlapping problem :: here a state will be the max profit of a specific length of rod

#include<bits/stdc++.h>

using namespace std;

// recursive solution
int maxProfit(int len, int price[], int memo[]) {
    // base case
    if (len == 0)
        // if the length is 0, no need to cal profit
        return 0;
    if (memo[len] != -1)
        return memo[len];

    // recursive case
    int best = 0;
    for (int i = 1; i <= len; i++) {
        // consider all cases such as for example for a len 4; (1, 2-4), (1-2, 3-4), (1-3, 4), where the latter part is calculated through recursion
        int netProfit = price[i] + maxProfit(len - i, price, memo);
        best = max(netProfit, best);
    }
    // remember to store the val in memo
    memo[len] = best;
    return best;
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

    // memo array
    int memo[totalLen + 1];
    fill(memo, memo + totalLen + 1, -1);
    cout << "The max profit will be: " << maxProfit(totalLen, priceOfEachLen, memo);

    return 0;
}