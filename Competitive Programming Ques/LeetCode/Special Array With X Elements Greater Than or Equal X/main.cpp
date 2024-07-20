// Leetcode: Special Array With X Elements Greater Than or Equal X
// https://leetcode.com/problems/special-array-with-x-elements-greater-than-or-equal-x

#include <iostream>
#include <vector>

using namespace std;

int specialArray(vector<int> &nums)
{
  // Maximum possible length of nums
  const int MAX_LEN = 1001;

  // Create a count array to store the frequency of each number in nums
  vector<int> frequency(MAX_LEN, 0);

  // Populate the frequency array
  for (int num : nums)
  {
    frequency[num]++;
  }

  // Variable to keep track of the cumulative count of elements seen so far
  int cumulativeCount = 0;
  // Total number of elements in nums
  int totalElements = nums.size();

  // Iterate through possible values of x from 0 to MAX_LEN - 1
  for (int i = 0; i < MAX_LEN; i++)
  {
    // Number of elements that are greater than or equal to x
    int elementsGreaterOrEqual = totalElements - cumulativeCount;

    // Check if x is the special number
    if (elementsGreaterOrEqual == i)
    {
      return i;
    }

    // Update the cumulative count with the frequency of the current x
    cumulativeCount += frequency[i];
  }

  // If no special number is found, return -1
  return -1;
}

int main()
{
  vector<int> nums = {3, 5};
  cout << specialArray(nums) << endl;
  return 0;
}