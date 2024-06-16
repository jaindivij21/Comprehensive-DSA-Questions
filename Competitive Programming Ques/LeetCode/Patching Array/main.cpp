// Leetcode: Patching Array
// https://leetcode.com/problems/patching-array
// Get a hint from here: https://www.youtube.com/watch?v=N-tcCOCNSZY

#include <iostream>
#include <vector>

using namespace std;

int minPatches(vector<int> &nums, int n)
{
  int noOfPatches = 0;    // Initialize the count of patches needed
  int maxNumCanReach = 0; // Tracks the maximum number we can reach using current elements
  int numsPtr = 0;        // Pointer to traverse the nums array

  // Continue the loop until maxNumCanReach is less than n
  while (maxNumCanReach < n)
  {
    // If we have exhausted all elements in nums
    if (numsPtr >= nums.size())
    {
      // Add a new patch (maxNumCanReach + 1) since it is needed to extend the range as we have not reached n
      maxNumCanReach += (maxNumCanReach + 1);
      noOfPatches++; // Increment the patch count
    }
    else
    {
      // If the next element in nums is greater than the current maxNumCanReach + 1
      if (maxNumCanReach < nums[numsPtr] - 1)
      {
        // Add a new patch (maxNumCanReach + 1) since there is a gap
        maxNumCanReach += (maxNumCanReach + 1);
        noOfPatches++; // Increment the patch count
      }
      else
      {
        // Use the current element in nums to extend the range
        maxNumCanReach += nums[numsPtr];
        numsPtr++; // Move to the next element in nums
      }
    }
  }

  // Return the total number of patches needed
  return noOfPatches;
}

int main()
{
  int n = 5;
  vector<int> nums = {1, 2, 2};

  cout << minPatches(nums, n) << endl;

  return 0;
}