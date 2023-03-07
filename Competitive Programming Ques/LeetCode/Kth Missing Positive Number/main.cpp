// Leetcode :  Kth Missing Positive Number
// https://leetcode.com/problems/kth-missing-positive-number/description/

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// Naive Solution : Using an unordered set
int findKthPositive(vector<int> &arr, int k)
{
  // insert all the elements into an unordered set
  unordered_set<int> set;
  for (auto i : arr)
  {
    set.insert(i);
  }

  int missingElements = 0;
  int i = 1;
  for (; missingElements != k; i++)
  {
    if (set.find(i) == set.end())
    {
      missingElements++;
    }
  }
  return i - 1;
}

int main()
{
  int size;
  int k;
  cin >> size >> k;

  vector<int> arr(size);
  for (int i = 0; i < size; i++)
  {
    cin >> arr[i];
  }

  cout << findKthPositive(arr, k) << endl;

  return 0;
};