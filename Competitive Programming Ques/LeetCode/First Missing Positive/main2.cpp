// Leetcode: First Missing Positive
// https://leetcode.com/problems/first-missing-positive
// https://www.youtube.com/watch?v=8g78yfzMlao&t=983s

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  int firstMissingPositive(vector<int> &nums)
  {
    // The answer space is limited to 1..nums.size()
    int n = nums.size();

    // Replace the negatives with the largest integer
    for (int &num : nums)
    {
      if (num <= 0)
        num = INT_MAX;
    }

    // Now go over the numbers and if they fall in the answer space and are present, make their indices -ve
    for (int &num : nums)
    {
      int absVal = abs(num);
      if (absVal > 0 && absVal <= n)
      {
        nums[absVal - 1] *= nums[absVal - 1] > 0 ? -1 : 1;
      }
    }

    // Find the first positive index, which is the missing number
    for (int i = 0; i < n; i++)
    {
      if (nums[i] > 0)
      {
        return i + 1;
      }
    }

    // If all indices are negative, the missing number is n + 1
    return n + 1;
  }
};

int main()
{
  Solution s;
  vector<int> nums = {1, 2, 0};

  cout << s.firstMissingPositive(nums) << endl;

  return 0;
}