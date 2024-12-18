// Leetcode: Final Prices With a Special Discount in a Shop
// https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  vector<int> finalPrices(vector<int> &prices)
  {
    for (int i = 0; i < prices.size(); i++)
    {
      int discount = 0;
      for (int j = i + 1; j < prices.size(); j++)
      {
        if (prices[j] <= prices[i])
        {
          discount = prices[j];
          break;
        }
      }

      prices[i] -= discount;
    }

    return prices;
  }
};

int main()
{
  Solution sol;
  vector<int> prices = {8, 4, 6, 2, 3};

  vector<int> result = sol.finalPrices(prices);

  for (int i = 0; i < result.size(); i++)
  {
    cout << result[i] << " ";
  }

  return 0;
}