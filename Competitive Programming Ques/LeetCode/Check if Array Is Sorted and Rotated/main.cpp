// Leetcode: Check if Array Is Sorted and Rotated
// https://leetcode.com/problems/check-if-array-is-sorted-and-rotated

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  bool check(vector<int> &nums)
  {
    int n = nums.size();

    int isUnsorted = false;
    for (int i = 0; i < nums.size(); i++)
    {
      int currNum = nums[i];
      int nextNum = nums[(i + 1) % n];

      if (nextNum < currNum && !isUnsorted)
      {
        isUnsorted = !isUnsorted;
      }
      else if (nextNum < currNum)
      {
        return false;
      }
    }

    return true;
  }
};

int main()
{
  Solution s;
  vector<int> nums = {3, 4, 5, 1, 2};

  cout << s.check(nums) << endl;

  return 0;
}