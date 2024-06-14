// Leetcode: Minimum Increment to Make Array Unique
// https://leetcode.com/problems/minimum-increment-to-make-array-unique

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int minIncrementForUnique(vector<int> &nums)
{
  sort(nums.begin(), nums.end());

  int ans = 0;
  int nextUniq = nums[0];
  for (int &num : nums)
  {
    if (num < nextUniq)
    {
      ans += (nextUniq - num);
      num = nextUniq;
    }
    nextUniq = num + 1;
  }
  return ans;
}

int main()
{
  vector<int> nums = {3, 2, 1, 2, 1, 7};
  cout << minIncrementForUnique(nums) << endl;
  return 0;
}