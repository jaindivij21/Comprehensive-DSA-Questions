// Leetcode: Buy Two Chocolates
// https://leetcode.com/problems/buy-two-chocolates

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
  int buyChoco(vector<int> &prices, int money)
  {
    if (prices.size() < 2)
    {
      return money;
    }

    sort(prices.begin(), prices.end());

    int moneyLeft = money - (prices[0] + prices[1]);
    return moneyLeft >= 0 ? moneyLeft : money;
  }
};

int main()
{
  Solution sol;
  vector<int> prices = {1, 2, 3, 4, 5};
  int money = 5;
  cout << sol.buyChoco(prices, money) << endl;

  return 0;
}
