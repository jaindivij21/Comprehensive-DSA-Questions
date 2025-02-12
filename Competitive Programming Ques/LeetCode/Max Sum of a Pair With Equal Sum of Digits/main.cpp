// Leetcode: Max Sum of a Pair With Equal Sum of Digits
// https://leetcode.com/problems/max-sum-of-a-pair-with-equal-sum-of-digits

#include <iostream>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  int maximumSum(vector<int> &nums)
  {
    unordered_map<int, int> sumToMaxIdxMapping;
    int ans = -1;

    for (int i = 0; i < nums.size(); i++)
    {
      int currSum = calDigitSum(nums[i]);

      if (sumToMaxIdxMapping.find(currSum) == sumToMaxIdxMapping.end())
      {
        sumToMaxIdxMapping[currSum] = i;
      }
      else
      {
        ans = max(ans, nums[sumToMaxIdxMapping[currSum]] + nums[i]);
        if (nums[i] > nums[sumToMaxIdxMapping[currSum]])
          sumToMaxIdxMapping[currSum] = i;
      }
    }

    return ans;
  }

private:
  int calDigitSum(int num)
  {
    int sum = 0;
    while (num != 0)
    {
      sum += (num % 10);
      num /= 10;
    }

    return sum;
  }
};

int main()
{
  Solution s;
  vector<int> nums = {18, 43, 36, 13, 7};

  cout << s.maximumSum(nums) << endl;

  return 0;
}