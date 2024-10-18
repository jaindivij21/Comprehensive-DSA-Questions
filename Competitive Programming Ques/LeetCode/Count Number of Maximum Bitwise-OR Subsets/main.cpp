// Leetcode: Count Number of Maximum Bitwise-OR Subsets
// https://leetcode.com/problems/count-number-of-maximum-bitwise-or-subsets

#include <iostream>

using namespace std;

class Solution
{
public:
  int countMaxOrSubsets(vector<int> &nums)
  {
    // Calculate the maximum possible bitwise OR value by OR-ing all elements in the array.
    int targetMaxOR = 0;
    for (auto num : nums)
      targetMaxOR |= num;

    int subsetCount = 0;
    // Start the recursive function to count subsets that can reach the targetMaxOR.
    findMaxORSubsets(nums, 0, 0, targetMaxOR, subsetCount);
    return subsetCount;
  }

private:
  void findMaxORSubsets(vector<int> &nums, int currentOR, int index, int targetMaxOR, int &subsetCount)
  {
    // Base Case: If we have processed all elements
    if (index == nums.size())
    {
      // Check if the current subset's OR equals the maximum possible OR
      if (currentOR == targetMaxOR)
      {
        subsetCount++;
      }
      return;
    }

    // Recursive Case:
    // Option 1: Do not include the current element in the subset
    findMaxORSubsets(nums, currentOR, index + 1, targetMaxOR, subsetCount);

    // Option 2: Include the current element in the subset
    findMaxORSubsets(nums, currentOR | nums[index], index + 1, targetMaxOR, subsetCount);
  }
};

int main()
{
  Solution solution;
  vector<int> nums = {3, 1};
  cout << solution.countMaxOrSubsets(nums) << endl;

  return 0;
}