// Leetcode ::  Next Permutation
// https://leetcode.com/problems/next-permutation/

// Good Question
// Approach :
/*
TC: 3*O(n)
Basically try to find the next biggest number in the set of given permutations, unless the given permutation is already the largest,
in which case, we have to return the smallest.

step 1: Linearly traverse given array from the end and find a number that is greater than its adjacent nums[i] > nums[i-1].
        Store the index of smaller number in breakPoint variable. If there is no such element, reverse entire array and return.
step 2: Linearly traverse from the end and this time find a number larger than nums[breakPoint]. Let's call it nums[i].
step 3: Swap nums[i] and nums[breakPoint].
step 4: Reverse the array from index breakPoint + 1 to nums.size()
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// function to find the next permutation : in the process we don't calculate all the possible permutations since that
// would be very lengthy
void nextPermutation(vector<int> &nums)
{
  int lastIndex = nums.size() - 1;
  int idx1, idx2;
  for (idx1 = lastIndex - 1; idx1 >= 0; idx1--)
  {
    // iterate towards left to search for index1
    if (nums[idx1 + 1] > nums[idx1])
      break;
  }
  // now if index1 < 0, means couldn't find the breakpoint
  if (idx1 < 0)
  {
    // just reverse the entire array
    reverse(nums.begin(), nums.end());
    return;
  }
  else
  {
    // find the next big element from index1, and swap its position from index1
    for (idx2 = lastIndex; idx2 > idx1; idx2--)
    {
      // iterate towards left to search for next bigger element than index1
      if (nums[idx2] > nums[idx1])
        break;
    }
    swap(nums[idx1], nums[idx2]);                 // swap the two numbers
    reverse(nums.begin() + idx1 + 1, nums.end()); // reverse the array after the idx1
  }
}

int main()
{
  int size;
  cin >> size;

  vector<int> v(size);

  for (int i = 0; i < size; i++)
  {
    cin >> v[i];
  }

  // find the next permutation
  nextPermutation(v);

  // print the next permutation
  for (int i = 0; i < size; i++)
  {
    cout << v[i];
  }

  return 0;
}
