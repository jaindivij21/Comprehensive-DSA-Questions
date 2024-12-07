// Leetcode: Minimum Limit of Balls in a Bag
// https://leetcode.com/problems/minimum-limit-of-balls-in-a-bag

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  int minimumSize(vector<int> &nums, int maxOperations)
  {
    // Initialize the binary search bounds
    int l = 1, r = INT_MAX;
    for (auto i : nums)
    {
      r = max(r, i);
    }

    int currAns = r;
    while (l <= r)
    {
      int mid = l + (r - l) / 2;

      // Check if the current mid value can be a valid minimum size
      if (isPossible(nums, mid, maxOperations))
      {
        currAns = mid;
        r = mid - 1;
      }
      else
      {
        l = mid + 1;
      }
    }

    return currAns;
  }

private:
  // Helper function to check if a given minNum can be achieved within maxOperations
  bool isPossible(vector<int> &nums, int minNum, int maxOperations)
  {
    int currOperations = 0;
    for (auto i : nums)
    {
      // Calculate the number of splits required for the current number
      currOperations += (i - 1) / minNum; // Equivalent to ceil(i / minNum) - 1

      // If operations exceed the allowed maxOperations, return false
      if (currOperations > maxOperations)
      {
        return false;
      }
    }

    // All numbers can be reduced to minNum within maxOperations
    return true;
  }
};

int main()
{
  Solution sol;
  vector<int> nums = {9};
  int maxOperations = 2;
  cout << sol.minimumSize(nums, maxOperations) << endl;

  return 0;
}