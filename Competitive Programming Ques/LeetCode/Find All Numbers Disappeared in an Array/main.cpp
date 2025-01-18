// Leetcode: Find All Numbers Disappeared in an Array
// https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
  vector<int> findDisappearedNumbers(vector<int> &nums)
  {
    int n = nums.size();

    // Rearrange elements to their correct positions
    for (int i = 0; i < n; i++)
    {
      // Correct position for nums[i] is nums[i] - 1
      while (nums[i] != nums[nums[i] - 1])
      {
        // Swap nums[i] with the correct position
        swap(nums[i], nums[nums[i] - 1]);
      }
    }

    // Find the numbers that are not in their correct positions
    vector<int> missingNumbers;
    for (int i = 0; i < n; i++)
    {
      if (nums[i] != i + 1)
      {
        missingNumbers.push_back(i + 1);
      }
    }

    return missingNumbers;
  }
};

int main()
{
  Solution s;
  vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};

  vector<int> result = s.findDisappearedNumbers(nums);

  for (int i = 0; i < result.size(); i++)
  {
    cout << result[i] << " ";
  }

  return 0;
}