// Leetcode: Minimum Difference Between Largest and Smallest Value in Three Moves
// https://leetcode.com/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int minDifference(vector<int> &nums)
{
  if (nums.size() <= 4)
    return 0; // The other three elements can be made equal to the fourth, hence 0

  sort(nums.begin(), nums.end()); // Sort the array

  int ans = INT_MAX;

  // Check all the 4 cases of deletions
  for (int left = 0, right = nums.size() - 4; left < 4; left++, right++)
  {
    ans = min(ans, nums[right] - nums[left]);
  }

  return ans;
}

int main()
{
  vector<int> nums = {20, 75, 81, 82, 95};
  cout << minDifference(nums) << endl;

  return 0;
}