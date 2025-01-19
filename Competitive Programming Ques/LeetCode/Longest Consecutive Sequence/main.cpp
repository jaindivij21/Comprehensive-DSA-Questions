// Leetcode: Longest Consecutive Sequence
// https://leetcode.com/problems/longest-consecutive-sequence/

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
public:
  // Map to store the length of the longest consecutive sequence starting from a given number
  unordered_map<int, int> sequenceLengthMap;

  int longestConsecutive(vector<int> &nums)
  {
    // Populate the map with all numbers in the input array, initialized with a placeholder (-1)
    for (int num : nums)
    {
      sequenceLengthMap[num] = -1;
    }

    int maxConsecutiveLength = 0;

    // Check the longest sequence starting from each number in the input array
    for (int num : nums)
    {
      maxConsecutiveLength = max(maxConsecutiveLength, findLongestSequence(num));
    }

    return maxConsecutiveLength;
  }

private:
  // Recursive helper function to calculate the length of the longest consecutive sequence starting from 'num'
  int findLongestSequence(int num)
  {
    // If the number is not in the map, it's not part of any sequence
    if (sequenceLengthMap.find(num) == sequenceLengthMap.end())
    {
      return 0;
    }

    // If the sequence length for this number is already computed, return it
    if (sequenceLengthMap[num] != -1)
    {
      return sequenceLengthMap[num];
    }

    // Compute the sequence length recursively
    int consecutiveLength = 1 + findLongestSequence(num + 1);

    // Cache the computed length in the map for future use
    sequenceLengthMap[num] = consecutiveLength;

    return consecutiveLength;
  }
};

int main()
{
  Solution s;

  vector<int> nums = {100, 4, 200, 1, 3, 2};
  cout << s.longestConsecutive(nums) << endl;

  return 0;
}