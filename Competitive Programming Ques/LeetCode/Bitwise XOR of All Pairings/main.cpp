// Leetcode: Bitwise XOR of All Pairings
// https://leetcode.com/problems/bitwise-xor-of-all-pairings

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  int xorAllNums(vector<int> &nums1, vector<int> &nums2)
  {
    int res = 0;

    // XOR all elements of nums1 if nums2 has an odd size
    if (nums2.size() % 2 == 1)
    {
      for (int num : nums1)
      {
        res ^= num;
      }
    }

    // XOR all elements of nums2 if nums1 has an odd size
    if (nums1.size() % 2 == 1)
    {
      for (int num : nums2)
      {
        res ^= num;
      }
    }

    return res;
  }
};

int main()
{
  Solution s;
  vector<int> nums1 = {2, 1, 3};
  vector<int> nums2 = {10, 2, 5, 0};

  cout << s.xorAllNums(nums1, nums2) << endl;

  return 0;
}