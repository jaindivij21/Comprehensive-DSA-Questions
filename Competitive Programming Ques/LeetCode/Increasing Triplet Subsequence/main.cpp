// Leetcode: Increasing Triplet Subsequence
// https://leetcode.com/problems/increasing-triplet-subsequence

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  bool increasingTriplet(vector<int> &nums)
  {
    // Initialize the first and second numbers in the potential increasing triplet.
    int firstMin = INT_MAX;  // Smallest number encountered so far
    int secondMin = INT_MAX; // Second-smallest number that comes after firstMin

    // Iterate through each number in the array
    for (auto num : nums)
    {
      if (num <= firstMin)
      {
        // Update firstMin if the current number is smaller or equal
        // This means we found a new smallest number
        firstMin = num;
      }
      else if (num <= secondMin)
      {
        // Update secondMin if the current number is greater than firstMin
        // but smaller or equal to secondMin
        // This means we found a new potential middle number for the triplet
        secondMin = num;
      }
      else
      {
        // If we find a number greater than both firstMin and secondMin,
        // then an increasing triplet exists
        return true;
      }
    }

    // If no increasing triplet is found, return false
    return false;
  }
};

int main()
{
  Solution sol;
  vector<int> nums = {1, 5, 0, 4, 1, 3};
  cout << sol.increasingTriplet(nums) << endl;

  return 0;
}