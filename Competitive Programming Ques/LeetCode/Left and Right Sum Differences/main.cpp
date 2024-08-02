// Leetcode: Left and Right Sum Differences
// https://leetcode.com/problems/left-and-right-sum-differences/description/

#include <numeric>
#include <vector>

using namespace std;

class Solution
{
public:
  vector<int> leftRightDifference(vector<int> &nums)
  {
    vector<int> result; // Result vector to store the left-right sum differences

    // Calculate the total sum of the array elements
    int totalSum = accumulate(nums.begin(), nums.end(), 0);

    // Variable to keep track of the sum of elements on the left side
    int leftSum = 0;

    // Iterate over each element in the array
    for (auto num : nums)
    {
      // Calculate the sum of elements on the right side
      int rightSum = totalSum - leftSum - num;

      // Calculate the absolute difference between leftSum and rightSum
      result.push_back(abs(leftSum - rightSum));

      // Update leftSum to include the current element
      leftSum += num;
    }

    return result;
  }
};

int main()
{
  vector<int> nums = {10, 4, 8, 3};

  Solution s;
  vector<int> ans = s.leftRightDifference(nums);
  return 0;
}