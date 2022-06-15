// Leetcode :: Missing Number
// https://leetcode.com/problems/missing-number/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// O(n) time complexity with constant space
int missingNumber(vector<int> &nums)
{
  int tmp = 0;
  int tmp2 = 0;
  for (int i = 0; i < nums.size(); i++)
  {
    tmp = tmp ^ (i + 1);
    tmp2 = tmp2 ^ nums[i];
  }
  return tmp ^ tmp2;
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

  cout << missingNumber(nums);

  return 0;
}