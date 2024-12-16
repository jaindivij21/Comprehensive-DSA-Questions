// Leetcode: Final Array State After K Multiplication Operations I
// https://leetcode.com/problems/final-array-state-after-k-multiplication-operations-i

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
  vector<int> getFinalState(vector<int> &nums, int k, int multiplier)
  {
    // Min head to store the values and indices to reconstruct the array at the end
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;

    for (int i = 0; i < nums.size(); i++)
      q.push({nums[i], i});

    for (int i = 0; i < k; i++)
    {
      pair<int, int> top = q.top();
      q.pop();

      top.first *= multiplier;
      q.push(top);
    }

    vector<int> ans(nums.size(), 0);

    while (!q.empty())
    {
      pair<int, int> ele = q.top();
      q.pop();

      ans[ele.second] = ele.first;
    }

    return ans;
  }
};

int main()
{
  Solution sol;
  vector<int> nums = {2, 1, 3, 5, 6};
  int k = 5;
  int multiplier = 2;

  vector<int> result = sol.getFinalState(nums, k, multiplier);

  return 0;
}