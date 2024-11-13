// Leetcode: Count the Number of Fair Pairs
// https://leetcode.com/problems/count-the-number-of-fair-pairs

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
  long long countFairPairs(vector<int> &nums, int lower, int upper)
  {
    long long fairPairsCount = 0;

    // Sort the array to allow binary search for pairs
    sort(nums.begin(), nums.end());

    // Iterate through each element, treating it as the first element in the pair
    for (int i = 0; i < nums.size(); i++)
    {
      // lower - nums[i] <= nums[j] <= upper - nums[i]
      // For each i, we need to find all j's greater than i that satisfy the above equation
      int lowerBound = lower - nums[i];
      int upperBound = upper - nums[i];

      // Use binary search to find the range of valid indices for nums[j]
      auto lowerBoundIt = lower_bound(nums.begin() + i + 1, nums.end(), lowerBound);
      auto upperBoundIt = upper_bound(nums.begin() + i + 1, nums.end(), upperBound);

      // The number of valid pairs is the difference in iterator positions
      fairPairsCount += (upperBoundIt - lowerBoundIt);
    }

    return fairPairsCount;
  }
};

int main()
{
  Solution sol;
  vector<int> nums = {0, 1, 7, 4, 4, 5};
  int lower = 3;
  int upper = 6;

  cout << sol.countFairPairs(nums, lower, upper) << endl;

  return 0;
}