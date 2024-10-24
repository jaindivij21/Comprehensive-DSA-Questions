// Leetcode: Move Zeroes
// https://leetcode.com/problems/move-zeroes

#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
  void moveZeroes(vector<int> &nums)
  {
    stable_sort(nums.begin(), nums.end(), [](int a, int b)
                { return b == 0; });
  }
};

int main()
{
  Solution sol;
  vector<int> nums = {0, 1, 0, 3, 12};
  sol.moveZeroes(nums);

  return 0;
}