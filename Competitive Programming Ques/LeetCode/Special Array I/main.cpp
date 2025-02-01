// Leetcode: Special Array I
// https://leetcode.com/problems/special-array-i

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  bool isArraySpecial(vector<int> &nums)
  {
    for (int i = 1; i < nums.size(); i++)
    {
      int numA = nums[i];
      int numB = nums[i - 1];

      if ((numA % 2 == 0 && numB % 2 != 0) || (numA % 2 != 0 && numB % 2 == 0))
        continue;
      else
        return false;
    }

    return true;
  }
};

int main()
{
  Solution s;
  vector<int> nums = {2, 1, 4};

  cout << s.isArraySpecial(nums) << endl;

  return 0;
}