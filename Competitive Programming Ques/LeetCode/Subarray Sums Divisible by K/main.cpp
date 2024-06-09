// Leetcode: Subarray Sums Divisible by K
// https://leetcode.com/problems/subarray-sums-divisible-by-k

#include <iostream>
#include <vector>

using namespace std;

// Brute Force Solution
int subarraysDivByK(vector<int> &nums, int k)
{
  int totalCount = 0; // To store the total count of subarrays
  for (int start = 0; start < nums.size(); start++)
  {
    int currentSum = 0; // To store the sum of the current subarray
    for (int end = start; end < nums.size(); end++)
    {
      currentSum += nums[end];
      if (currentSum % k == 0)
      {
        totalCount++;
      }
    }
  }
  return totalCount;
}

int main()
{
  int k = 5;
  vector<int> nums = {4, 5, 0, -2, -3, 1};

  cout << subarraysDivByK(nums, k) << endl;
  return 0;
}