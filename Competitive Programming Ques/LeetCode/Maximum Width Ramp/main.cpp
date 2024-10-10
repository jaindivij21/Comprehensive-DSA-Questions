// Leetcode: Maximum Width Ramp
// https://leetcode.com/problems/maximum-width-ramp

#include <iostream>
#include <stack>

using namespace std;

// Monotonic Stack Solution
class Solution
{
public:
  int maxWidthRamp(vector<int> &nums)
  {
    int maxWidth = 0;
    stack<int> s;

    // Build a ascending stack from nums array
    s.push(0);
    for (int i = 1; i < nums.size(); i++)
    {
      if (nums[i] < nums[s.top()])
        s.push(i);
    }

    // Loop from the end of the array
    for (int i = nums.size() - 1; i >= 0; i--)
    {
      while (!s.empty() && nums[s.top()] <= nums[i])
      {
        maxWidth = max(maxWidth, i - s.top());
        s.pop();
      }
    }

    return maxWidth;
  }
};

int main()
{
  Solution sol;
  vector<int> nums = {6, 0, 8, 2, 1, 5};
  cout << sol.maxWidthRamp(nums) << endl;

  return 0;
}