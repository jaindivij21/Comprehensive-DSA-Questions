// Leetcode: Find the Duplicate Number
// https://leetcode.com/problems/find-the-duplicate-number

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  int findDuplicate(vector<int> &nums)
  {
    // Initialize two pointers, both starting at the first element.
    int slow = nums[0];
    int fast = nums[0];

    // Phase 1: Detect the cycle using the Floyd's Tortoise and Hare algorithm.
    while (true)
    {
      // Move the slow pointer one step at a time.
      slow = nums[slow];
      // Move the fast pointer two steps at a time.
      fast = nums[nums[fast]];

      // If the slow and fast pointers meet, a cycle is detected.
      if (slow == fast)
      {
        break;
      }
    }

    // Phase 2: Find the entrance to the cycle, which is the duplicate number.
    // Reset one pointer to the start of the array.
    slow = nums[0];

    // Move both pointers one step at a time until they meet.
    // The meeting point is the duplicate number.
    while (slow != fast)
    {
      slow = nums[slow];
      fast = nums[fast];
    }

    // Return the duplicate number.
    return slow;
  }
};

int main()
{
  Solution s;
  vector<int> nums = {1, 3, 4, 2, 2};

  cout << s.findDuplicate(nums) << endl;

  return 0;
}