// Leetcode: Minimum Swaps to Group All 1's Together II
// https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together-ii

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
  int minSwaps(vector<int> &nums)
  {
    int minSwapsRequired = INT_MAX;
    int arraySize = nums.size();

    // Count the total number of 1's in the array
    int totalOnes = ranges::count_if(nums, [](int num)
                                     { return num == 1; });

    // Edge case: If there are no 1's or all elements are 1's, no swaps are needed
    if (totalOnes == 0 || totalOnes == arraySize)
      return 0;

    // Initialize the number of zeroes in the first window of size equal to the number of 1's
    int zeroCount = 0;
    for (int i = 0; i < totalOnes; i++)
    {
      if (nums[i] == 0)
      {
        zeroCount++;
      }
    }
    minSwapsRequired = min(minSwapsRequired, zeroCount);

    // Use sliding window to find the minimum number of zeroes in any window of size equal to the number of 1's
    for (int i = totalOnes; i < arraySize + totalOnes - 1; i++)
    {
      int newElement = nums[i % arraySize];
      int oldElement = nums[(i - totalOnes) % arraySize];

      // Update zero count based on the new and old elements
      zeroCount += (newElement == 0) - (oldElement == 0);
      minSwapsRequired = min(minSwapsRequired, zeroCount);
    }

    return minSwapsRequired;
  }
};

int main()
{
  vector<int> nums = {0, 1, 0, 1, 1, 0, 0};

  Solution s;
  cout << s.minSwaps(nums) << endl;
  return 0;
}