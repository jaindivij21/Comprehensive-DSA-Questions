// Leetcode: Minimized Maximum of Products Distributed to Any Store
// https://leetcode.com/problems/minimized-maximum-of-products-distributed-to-any-store
// https://www.youtube.com/watch?v=GKSSr2xkR8A

#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

class Solution
{
public:
  int minimizedMaximum(int numStores, vector<int> &quantities)
  {
    // Find the maximum quantity to set an initial range for binary search
    int maxQuantity = *max_element(quantities.begin(), quantities.end());

    int left = 1;            // Minimum possible value for max items per store
    int right = maxQuantity; // Maximum possible value for max items per store
    int result = INT_MAX;

    // Binary search to find the minimized maximum items per store
    while (left <= right)
    {
      int mid = left + (right - left) / 2;

      if (canDistribute(numStores, quantities, mid))
      {
        // Update result if mid can be a possible solution and try for a smaller maximum
        result = mid;
        right = mid - 1;
      }
      else
      {
        // Increase the minimum boundary if mid is too small
        left = mid + 1;
      }
    }

    return result;
  }

private:
  bool canDistribute(int numStores, vector<int> &quantities, int maxItemsPerStore)
  {
    int storesNeeded = 0;

    for (int quantity : quantities)
    {
      // Calculate the number of stores required for this quantity, given max items per store
      storesNeeded += ceil(quantity / float(maxItemsPerStore));
    }

    // Check if the required stores exceed available stores
    return storesNeeded <= numStores;
  }
};

int main()
{
  Solution sol;
  vector<int> quantities = {5, 7};
  int n = 2;

  cout << sol.minimizedMaximum(n, quantities) << endl;

  return 0;
}