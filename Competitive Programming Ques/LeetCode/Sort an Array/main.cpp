// Leetcode: Sort an Array
// https://leetcode.com/problems/sort-an-array

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  vector<int> sortArray(vector<int> nums)
  {
    // Base Case
    if (nums.size() <= 1)
      return nums;

    int mid = nums.size() / 2;

    // Recursive Cases
    vector<int> leftSorted = sortArray(vector<int>(nums.begin(), nums.begin() + mid));
    vector<int> rightSorted = sortArray(vector<int>(nums.begin() + mid, nums.end()));

    return mergeSortedArrays(leftSorted, rightSorted);
  }

private:
  vector<int> mergeSortedArrays(vector<int> &l, vector<int> &r)
  {
    vector<int> ans;
    int i = 0, j = 0;

    while (i < l.size() && j < r.size())
    {
      if (l[i] <= r[j])
      {
        ans.push_back(l[i]);
        i++;
      }
      else
      {
        ans.push_back(r[j]);
        j++;
      }
    }

    while (i < l.size())
      ans.push_back(l[i++]);
    while (j < r.size())
      ans.push_back(r[j++]);

    return ans;
  }
};

int main()
{
  Solution s;
  vector<int> nums = {5, 2, 3, 1};

  vector<int> result = s.sortArray(nums);

  for (int i : result)
  {
    cout << i << " ";
  }

  return 0;
}