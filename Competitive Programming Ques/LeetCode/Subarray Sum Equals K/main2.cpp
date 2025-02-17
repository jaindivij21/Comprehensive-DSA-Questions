// Leetcode: Subarray Sum Equals K
// https://leetcode.com/problems/subarray-sum-equals-k

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  int subarraySum(vector<int> &nums, int target)
  {
    // Hash map to store the cumulative sum frequencies
    unordered_map<int, int> cumulativeSumFrequency;

    // Initialize the map with the cumulative sum of 0, to handle cases where a subarray starts from index 0
    cumulativeSumFrequency[0]++;

    int cumulativeSum = 0;
    int resultCount = 0;

    // Iterate through each number in the array
    for (const auto &num : nums)
    {
      cumulativeSum += num; // Update cumulative sum

      // Calculate the difference needed to reach the target sum
      int requiredSum = cumulativeSum - target;

      // If the difference exists in the map, it means we found subarrays that sum to 'target'
      if (cumulativeSumFrequency.count(requiredSum))
      {
        resultCount += cumulativeSumFrequency[requiredSum];
      }

      // Store the current cumulative sum in the map
      cumulativeSumFrequency[cumulativeSum]++;
    }

    return resultCount;
  }
};

int main()
{
  Solution solution;
  vector<int> nums = {1, 1, 1};
  int k = 2;

  cout << solution.subarraySum(nums, k) << endl; // Output: 2

  return 0;
}
