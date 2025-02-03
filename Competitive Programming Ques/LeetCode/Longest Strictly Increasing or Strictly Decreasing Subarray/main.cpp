// Leetcode: Longest Strictly Increasing or Strictly Decreasing Subarray
// https://leetcode.com/problems/longest-strictly-increasing-or-strictly-decreasing-subarray

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  int longestMonotonicSubarray(vector<int> &nums)
  {
    int n = nums.size();

    // Single element case
    if (n == 1)
      return 1;

    int maxLen = 1, incLen = 1, decLen = 1;

    for (int i = 1; i < n; i++)
    {
      int currNum = nums[i];
      int revNum = nums[n - i - 1];

      // Update increasing sequence length
      incLen = (currNum > nums[i - 1]) ? incLen + 1 : 1;

      // Update decreasing sequence length
      decLen = (revNum > nums[n - i]) ? decLen + 1 : 1;

      // Track the longest monotonic subarray
      maxLen = max({maxLen, incLen, decLen});
    }

    return maxLen;
  }
};

int main()
{
  Solution s;
  vector<int> nums = {1, 4, 3, 3, 2};

  cout << s.longestMonotonicSubarray(nums) << endl;

  return 0;
}