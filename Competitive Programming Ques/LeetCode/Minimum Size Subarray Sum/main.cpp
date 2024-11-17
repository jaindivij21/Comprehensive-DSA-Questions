// Leetcode: Minimum Size Subarray Sum
// https://leetcode.com/problems/minimum-size-subarray-sum

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  // Sliding Window
  int minSubArrayLen(int target, vector<int> &nums)
  {
    if (nums.size() == 1)
    {
      return nums[0] >= target ? 1 : 0;
    }

    int minSubarrayLen = INT_MAX;
    int windowSum = 0;
    int i = 0;

    for (int j = 0; j < nums.size(); ++j)
    {
      // Expand the window by adding nums[j]
      windowSum += nums[j];

      // Shrink the window as long as the sum is greater than or equal to target
      while (windowSum >= target)
      {
        minSubarrayLen = min(minSubarrayLen, j - i + 1);
        windowSum -= nums[i];
        i++;
      }
    }

    return minSubarrayLen == INT_MAX ? 0 : minSubarrayLen;
  }
};

int main()
{
  Solution sol;
  vector<int> nums = {2, 3, 1, 2, 4, 3};
  int target = 7;

  cout << sol.minSubArrayLen(target, nums) << endl;

  return 0;
}