// Leetcode :: Find the duplicate number
// https://leetcode.com/problems/find-the-duplicate-number/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Take benefit that the numbers belong only in the range [1, n]
// O(n) time
int findDuplicate(vector<int> &nums)
{
  while (nums[0] != nums[nums[0]])
  {
    swap(nums[nums[0]], nums[0]);
  }
  return nums[0];
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

  cout << findDuplicate(nums);

  return 0;
}