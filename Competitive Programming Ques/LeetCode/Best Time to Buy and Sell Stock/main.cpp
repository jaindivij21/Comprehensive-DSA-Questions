// Best Time to Buy and Sell Stock :: Leetcode
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

#include <bits/stdc++.h>
using namespace std;

// sliding window
int maxProfit(vector<int> &prices)
{
    // if only one day, there cannot be any selling, so profit = 0
    if (prices.size() == 1)
        return 0;

    // initializers
    int maxProfit = 0, buy = 0, sell = 1;
    while (sell <= prices.size() - 1)
    {
        // if the buying price is less than sell price : profit
        if (prices[buy] < prices[sell])
            maxProfit = max(maxProfit, prices[sell] - prices[buy]);
        else
            buy = sell;
        sell++;
    }
    return maxProfit;
}

int main()
{
    vector<int> nums = {2, 1};
    cout << maxProfit(nums) << endl;
    return 0;
}
