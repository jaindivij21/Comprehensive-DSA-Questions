// Best Time to Buy and Sell Stock :: Leetcode
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

#include <bits/stdc++.h>
using namespace std;

// sliding window
int maxProfit(vector<int> &prices)
{
    if (prices.size() == 1)
        return 0;
    int maxProfit = 0, start = 0, end = 1;
    while (end < prices.size())
    {
        if (prices[start] < prices[end])
            maxProfit = max(maxProfit, prices[end] - prices[start]);
        else
            start = end;
        end++;
    }
    return maxProfit;
}

int main()
{
    vector<int> nums = {2, 1};
    cout << maxProfit(nums) << endl;
    return 0;
}
