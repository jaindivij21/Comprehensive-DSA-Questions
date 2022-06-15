// Count Inversions
// https://www.geeksforgeeks.org/counting-inversions/
// Enhanced Merge Sort

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// function to merge 2 sorted arrays : its possible that the 2 arrays are empty
void merge(vector<int> &nums, int s, int e, long long int &ans)
{
  int i = s;
  int mid = (s + e) / 2;
  int j = mid + 1;
  vector<int> tmp;
  while (i <= mid && j <= e)
  {
    if (nums[i] > nums[j])
    {
      tmp.push_back(nums[j++]);
      // count all the conversions while merging
      // Ex. 1 5 6     2    ->  5,2; then 6 will also be larger than 2.
      // They will be eql to all the numbers from itself to the end of the first sorted array,
      // since they will all be larger than the number in the second array.
      ans += (mid - i + 1);
    }
    else
    {
      tmp.push_back(nums[i++]);
    }
  }
  while (i <= mid)
  {
    tmp.push_back(nums[i++]);
  }
  while (j <= e)
  {
    tmp.push_back(nums[j++]);
  }

  for (int k = s, m = 0; k <= e; k++, m++)
  {
    nums[k] = tmp[m];
  }
}

// recursive function
void mergeSort(vector<int> &nums, int s, int e, long long int &ans)
{
  if (s >= e)
  {
    return;
  }
  int mid = (s + e) / 2;
  mergeSort(nums, s, mid, ans);
  mergeSort(nums, mid + 1, e, ans);
  merge(nums, s, e, ans);
}

// main function
long long getInversions(vector<int> &nums, int n)
{
  long long int ans = 0;
  mergeSort(nums, 0, int(nums.size() - 1), ans);
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

  cout << getInversions(nums, nums.size());

  return 0;
}