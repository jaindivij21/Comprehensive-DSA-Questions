// Leetcode: Find the Power of K-Size Subarrays I
// https://leetcode.com/problems/find-the-power-of-k-size-subarrays-i

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  vector<int> resultsArray(vector<int> &nums, int k)
  {
    vector<int> result;

    // Define the sliding window
    int windowStart = 0;
    int windowEnd = k - 1;

    int countOfValidPairs = 1; // Tracks the count of valid consecutive numbers in the window

    // Iterate through the array while the window is within bounds
    while (windowEnd < nums.size())
    {
      if (isValidWindow(countOfValidPairs, nums, windowStart, windowEnd, k))
      {
        // Add the end of the valid window to the result
        result.push_back(nums[windowEnd]);
      }
      else
      {
        // Add -1 if the window is invalid
        result.push_back(-1);
      }

      // Slide the window
      windowStart++;
      windowEnd++;
    }

    // Return the result
    return result;
  }

private:
  bool isValidWindow(int &countOfValidPairs, vector<int> &nums, int windowStart, int windowEnd, int k)
  {
    // Initialize the count for the first window
    if (windowStart == 0)
    {
      countOfValidPairs = 1;
      for (int i = windowStart + 1; i <= windowEnd; i++)
      {
        if (nums[i] == nums[i - 1] + 1)
        {
          countOfValidPairs++;
        }
      }
    }
    else
    {
      // Adjust count when the window slides
      if (nums[windowStart] == nums[windowStart - 1] + 1)
      {
        // A consecutive pair leaves the window
        countOfValidPairs--;
      }
      if (nums[windowEnd] == nums[windowEnd - 1] + 1)
      {
        // A consecutive pair enters the window
        countOfValidPairs++;
      }
    }

    // Window is valid if count matches k
    return countOfValidPairs == k;
  }
};

int main()
{
  Solution sol;
  vector<int> arr = {1, 2, 3, 4, 3, 2, 5};
  int k = 3;

  vector<int> ans = sol.resultsArray(arr, k);

  return 0;
}