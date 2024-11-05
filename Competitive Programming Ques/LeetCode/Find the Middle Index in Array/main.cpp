// Leetcode: Find the Middle Index in Array
// https://leetcode.com/problems/find-the-middle-index-in-array

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  int findMiddleIndex(vector<int> &nums)
  {
    vector<int> leftSums(nums.size(), 0);
    vector<int> rightSums(nums.size(), 0);

    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
      leftSums[i] = sum;
      sum += nums[i];
    }

    sum = 0;
    for (int i = nums.size() - 1; i >= 0; i--)
    {
      rightSums[i] = sum;
      sum += nums[i];
    }

    for (int i = 0; i < nums.size(); i++)
    {
      if (leftSums[i] == rightSums[i])
      {
        return i;
      }
    }

    return -1;
  }
};

int main()
{
  Solution sol;
  vector<int> nums = {1, 7, 3, 6, 5, 6};
  cout << sol.findMiddleIndex(nums) << endl;

  return 0;
}