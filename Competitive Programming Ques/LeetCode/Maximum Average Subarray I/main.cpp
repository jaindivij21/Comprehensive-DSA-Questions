// Leetcode: Maximum Average Subarray I
// https://leetcode.com/problems/maximum-average-subarray-i

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  // Function to find the maximum average of any contiguous subarray of size k
  double findMaxAverage(vector<int> &nums, int k)
  {
    // Initialize the running sum of the first k elements
    long long currentSum = 0;
    int i = 0;

    // Calculate the sum of the first k elements
    for (int j = 0; j < k; j++)
    {
      currentSum += nums[j];
    }

    // This will hold the maximum sum found
    long long maxSum = currentSum;

    // Slide the window across the array
    for (int j = k; j < nums.size(); j++)
    {
      // Update the running sum by removing the element going out of the window
      // and adding the new element coming into the window
      currentSum = currentSum - nums[i++] + nums[j];

      // Update maxSum if the current running sum is greater
      maxSum = max(maxSum, currentSum);
    }

    // Return the maximum average as a double
    return static_cast<double>(maxSum) / k;
  }
};

int main()
{
  Solution sol;
  vector<int> nums = {5};
  int k = 1;

  cout << "Max average: " << sol.findMaxAverage(nums, k) << endl;

  return 0;
}