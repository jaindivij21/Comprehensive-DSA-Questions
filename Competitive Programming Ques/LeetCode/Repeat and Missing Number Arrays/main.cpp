// https://www.interviewbit.com/problems/repeat-and-missing-number-array/

// QUESTION
// Given an array of integers from 1 to n, in which A appears 2 times and B doesn't appear. Return A and B
// Optimal Complexity: O(n) with constant space

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Marking the numbers as negative is the best approach 2*O(n)
vector<int> repeatedNumber(vector<int> &nums)
{
  vector<int> ans;
  for (int i = 0; i < nums.size(); i++)
  {
    if (nums[abs(nums[i]) - 1] >= 0)
      nums[abs(nums[i]) - 1] = nums[abs(nums[i]) - 1] * -1;
    else
      ans.push_back(abs(nums[i]));
  }
  for (int i = 0; i < nums.size(); i++)
  {
    if (nums[i] >= 0)
    {
      ans.push_back(i + 1);
    }
  }
  return ans;
}

int main()
{
  int size;
  cin >> size;
  vector<int> nums(size);
  for (int i = 0; i < size; i++)
  {
    cin >> nums[i];
  }

  vector<int> ans;
  ans = repeatedNumber(nums);

  for (auto i : ans)
  {
    cout << i << " ";
  }

  return 0;
}