// Leetcode: Max Consecutive Ones III
// https://leetcode.com/problems/max-consecutive-ones-iii

#include <iostream>

using namespace std;

class Solution
{
public:
  int longestOnes(vector<int> &nums, int k)
  {
    int currentWindowSize = 0, maxWindowSize = 0;

    int i = 0, j = 0;

    while (j < nums.size())
    {
      // If we encounter a 0, we decrement k (allowing one flip)
      if (nums[j] == 0)
      {
        k--;
      }

      j++;                 // Expand the window to the right
      currentWindowSize++; // Increase the current window size

      // If we have flipped more than k zeros, shrink the window from the left
      if (k < 0)
      {
        while (k < 0)
        {
          // If the leftmost element is a 0, we need to increment k back
          if (nums[i] == 0)
          {
            k++;
          }

          i++;                 // Move the left index to the right
          currentWindowSize--; // Decrease the current window size
        }
      }

      // Update the maximum window size found
      maxWindowSize = max(maxWindowSize, currentWindowSize);
    }

    // Return the maximum size of consecutive 1's found
    return maxWindowSize;
  }
};

int main()
{
  Solution sol;
  vector<int> nums = {0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1};

  cout << sol.longestOnes(nums, 3) << endl;

  return 0;
}