// Leetcode: Find if Array Can Be Sorted
// https://leetcode.com/problems/find-if-array-can-be-sorted

#include <iostream>

using namespace std;

class Solution
{
public:
  // Function that divides the array into sections based on the number of set bits in the number
  // and checks if the array can be sorted by swapping elements within the sections
  bool canSortArray(vector<int> &nums)
  {
    int currSectionMax = nums[0];
    int prevSectionMax = INT_MIN;
    int currentSectionBits = noOfSetBits(nums[0]);

    for (int i = 1; i < nums.size(); i++)
    {
      int currentSetBits = noOfSetBits(nums[i]);
      if (currentSectionBits != currentSetBits)
      {
        // New Section
        prevSectionMax = currSectionMax;
        currentSectionBits = currentSetBits;
      }

      // Check if current element is smaller than the max of the previous section
      if (nums[i] < prevSectionMax)
        return false;
      currSectionMax = max(currSectionMax, nums[i]);
    }

    // Array can be sorted by allowed swaps
    return true;
  }

private:
  // Helper function to count the number of set bits in a number
  int noOfSetBits(int num)
  {
    int setBits = 0;

    while (num != 0)
    {
      if ((num & 1) == 1)
      {
        setBits++;
      }
      num >>= 1;
    }

    return setBits;
  }
};

int main()
{
  Solution sol;
  vector<int> nums = {1, 2, 3, 4, 5};

  cout << sol.canSortArray(nums) << endl;

  return 0;
}