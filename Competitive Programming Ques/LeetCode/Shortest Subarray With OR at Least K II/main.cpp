// Leetcode: Shortest Subarray With OR at Least K II
// https://leetcode.com/problems/shortest-subarray-with-or-at-least-k-ii

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  int minimumSubarrayLength(vector<int> &nums, int k)
  {
    int shortedSubarrayLen = INT_MAX;

    for (int i = 0; i < nums.size(); i++)
    {
      for (int j = i; j < nums.size(); j++)
      {
        int bitWiseOR = 0;

        for (int x = i; x <= j; x++)
        {
          bitWiseOR |= nums[x];
        }

        if (bitWiseOR >= k)
        {
          shortedSubarrayLen = min(shortedSubarrayLen, j - i + 1);
        }
      }
    }

    return shortedSubarrayLen == INT_MAX ? -1 : shortedSubarrayLen;
  }
};

int main()
{
  Solution s;
  vector<int> nums = {1, 2, 3};
  int k = 2;

  cout << s.minimumSubarrayLength(nums, k) << endl;

  return 0;
}