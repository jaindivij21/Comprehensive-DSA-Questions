// Leetcode: Maximum Sum of Distinct Subarrays With Length K
// https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k

#include <iostream>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  long long maximumSubarraySum(vector<int> &nums, int k)
  {
    unordered_map<int, int> frequencyMap; // Tracks the frequency of elements in the current window
    long long maxSum = LLONG_MIN;
    long long currentSum = 0;

    int start = 0;
    int end = 0;

    // Initialize the window of size `k`
    while (end < k)
    {
      currentSum += nums[end];
      frequencyMap[nums[end]]++;
      end++;
    }
    end--; // Adjust `end` to be within bounds after initialization

    // Check if the initial window contains exactly `k` unique elements
    if (frequencyMap.size() == k)
    {
      maxSum = max(maxSum, currentSum);
    }

    // Slide the window through the array
    while (end < nums.size() - 1)
    {
      // Remove the contribution of the element going out of the window
      currentSum -= nums[start];
      frequencyMap[nums[start]]--;
      if (frequencyMap[nums[start]] == 0)
      {
        frequencyMap.erase(nums[start]);
      }
      start++; // Move the start of the window forward

      // Add the contribution of the new element entering the window
      end++;
      currentSum += nums[end];
      frequencyMap[nums[end]]++;

      // Check if the current window contains exactly `k` unique elements
      if (frequencyMap.size() == k)
      {
        maxSum = max(maxSum, currentSum);
      }
    }

    // Return the maximum sum, or 0 if no valid subarray was found
    return maxSum == LLONG_MIN ? 0 : maxSum;
  }
};

int main()
{
  Solution s;
  vector<int> nums = {1, 1, 1, 1, 1, 1};
  int k = 2;

  cout << s.maximumSubarraySum(nums, k) << endl;

  return 0;
}