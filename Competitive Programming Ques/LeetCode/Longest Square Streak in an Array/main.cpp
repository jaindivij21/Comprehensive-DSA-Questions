// Leetcode: Longest Square Streak in an Array
// https://leetcode.com/problems/longest-square-streak-in-an-array

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution
{
public:
  int longestSquareStreak(vector<int> &nums)
  {
    // Sort array to allow working with numbers in ascending order
    sort(nums.begin(), nums.end());
    int maxNum = nums.back();

    // Create a set to store unique numbers for O(1) lookups
    unordered_set<int> uniqueNums(nums.begin(), nums.end());
    unordered_map<int, int> streakCache;

    int maxStreakLength = 0;

    // Traverse each number in sorted nums to calculate streaks
    for (int num : nums)
    {
      int streakLength = calculateStreak(num, uniqueNums, streakCache, maxNum);
      maxStreakLength = max(streakLength, maxStreakLength);
    }

    // If no valid streak found (only single elements), return -1
    return maxStreakLength <= 1 ? -1 : maxStreakLength;
  }

private:
  int calculateStreak(long long num, unordered_set<int> &uniqueNums, unordered_map<int, int> &streakCache, int maxNum)
  {
    if (streakCache.count(num) > 0)
      // If already calculated, use cached result
      return streakCache[num];

    long long square = num * num;

    // Check if square is out of bounds or not in unique numbers
    if (square > maxNum || uniqueNums.find(square) == uniqueNums.end())
    {
      return uniqueNums.find(num) == uniqueNums.end() ? 0 : 1;
    }

    // Recursive call to continue streak if square exists in unique numbers
    return 1 + calculateStreak(square, uniqueNums, streakCache, maxNum);
  }
};

int main()
{
  Solution sol;
  vector<int> nums = {2, 3, 5, 6, 7};
  int result = sol.longestSquareStreak(nums);

  cout << "Result: " << result << endl;

  return 0;
}