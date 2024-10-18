// Leetcode: Form Smallest Number From Two Digit Arrays
// https://leetcode.com/problems/form-smallest-number-from-two-digit-arrays

#include <iostream>
#include <unordered_set>

using namespace std;

class Solution
{
public:
  int minNumber(vector<int> &nums1, vector<int> &nums2)
  {
    unordered_set<int> uniqs;
    int min1 = INT_MAX, min2 = INT_MAX;

    for (auto i : nums1)
    {
      min1 = min(min1, i);
      uniqs.insert(i);
    }

    int minSameEle = INT_MAX;
    for (auto i : nums2)
    {
      if (uniqs.find(i) != uniqs.end())
      {
        minSameEle = min(minSameEle, i);
      }

      min2 = min(min2, i);
    }

    if (minSameEle != INT_MAX)
      return minSameEle;

    return min1 < min2 ? min1 * 10 + min2 : min2 * 10 + min1;
  }
};

int main()
{
  Solution sol;
  vector<int> nums1 = {6, 7};
  vector<int> nums2 = {6, 0, 4};
  cout << sol.minNumber(nums1, nums2) << endl;

  return 0;
}
