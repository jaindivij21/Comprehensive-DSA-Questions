// Leetcode: Count Pairs Whose Sum is Less than Target
// https://leetcode.com/problems/count-pairs-whose-sum-is-less-than-target

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
  int countPairs(vector<int> &nums, int target)
  {
    int pairCount = 0;

    // Sort the array to enable binary search for pairs
    sort(nums.begin(), nums.end());

    // Iterate over each element, treating it as the first element of the pair
    for (int i = 0; i < nums.size() - 1; i++)
    {
      // Find the highest index where the second element of the pair
      // would still satisfy nums[i] + nums[j] < target
      int maxIndex = findMaxIndex(nums, target - nums[i], i);

      // If a valid index is found, count all pairs (i, j) with i < j <= maxIndex
      if (maxIndex != -1)
      {
        pairCount += (maxIndex - i);
      }
    }

    return pairCount;
  }

private:
  // Binary search to find the largest index j where nums[j] < x
  // starting the search from index i + 1 to avoid counting pairs where i == j
  int findMaxIndex(const vector<int> &nums, int limit, int start)
  {
    int left = start + 1;
    int right = nums.size() - 1;
    int maxIndex = -1;

    while (left <= right)
    {
      int mid = left + (right - left) / 2;

      // Check if nums[mid] is less than the limit (target - nums[i])
      if (nums[mid] < limit)
      {
        maxIndex = mid; // Store the index as a potential answer
        left = mid + 1; // Search right for a larger valid index
      }
      else
      {
        right = mid - 1; // Otherwise, search left
      }
    }

    return maxIndex;
  }
};