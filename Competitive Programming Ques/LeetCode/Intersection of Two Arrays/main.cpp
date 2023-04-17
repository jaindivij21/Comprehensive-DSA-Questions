// Leetcode: Intersection of 2 arrays
// https://leetcode.com/problems/intersection-of-two-arrays/description/

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
{
  unordered_set<int> uniques1, uniques2;
  for (auto i : nums1)
  {
    uniques1.insert(i);
  }
  for (auto i : nums2)
  {
    uniques2.insert(i);
  }

  // Iterate over uniques1, and check if each element is in uniques2 as well. If yes, then add to result array
  vector<int> ans;
  for (int unique : uniques1)
  {
    if (uniques2.find(unique) != uniques2.end())
    {
      ans.push_back(unique);
    }
  }

  return ans;
}

int main()
{
  vector<int> nums1 = {1, 2, 2, 1};
  vector<int> nums2 = {2, 2};

  vector<int> ans = intersection(nums1, nums2);

  for (auto i : ans)
  {
    cout << i << " ";
  }

  return 0;
}