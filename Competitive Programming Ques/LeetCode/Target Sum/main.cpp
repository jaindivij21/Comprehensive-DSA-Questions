// Leetcode: Target Sum
// https://leetcode.com/problems/target-sum

#include <iostream>

using namespace std;

class Solution
{
public:
  int findTargetSumWays(vector<int> &nums, int target)
  {
    return helper(nums, target, 0, 0);
  }

private:
  int helper(vector<int> &nums, int target, int i, int sum)
  {
    // Base Case
    if (i == nums.size())
    {
      return sum == target ? 1 : 0;
    }

    // Recursive Cases
    int add1 = helper(nums, target, i + 1, sum + nums[i]);
    int add2 = helper(nums, target, i + 1, sum + nums[i] * -1);

    return sum + add1 + add2;
  }
};

int main()
{
  Solution s;
  vector<int> nums = {1, 1, 1, 1, 1};
  int target = 3;

  cout << s.findTargetSumWays(nums, target) << endl;

  return 0;
}