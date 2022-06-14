// Leetcode :: Find the duplicate number
// https://leetcode.com/problems/find-the-duplicate-number/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// With modifying the array : TLE Exceeded

void bubbleSort(vector<int> &nums)
{
  // need to get n - 1 elements to their correct position
  for (int i = 1; i <= nums.size() - 1; i++)
  {
    for (int j = 0; j <= nums.size() - i - 1; j++)
    {
      if (nums[j + 1] < nums[j])
        swap(nums[j + 1], nums[j]);
    }
  }
}

// O(nlogn + n) => O(nlogn) solution => using optimal sort
// O(n2) => bubble sort
int findDuplicate(vector<int> &nums)
{
  bubbleSort(nums);
  for (int i = 0; i < nums.size() - 1; i++)
  {
    if (nums[i + 1] == nums[i])
    {
      return nums[i];
    }
  }
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