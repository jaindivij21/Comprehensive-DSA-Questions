// Leetcode: Find the Difference of Two Arrays
// https://leetcode.com/problems/find-the-difference-of-two-arrays

#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution
{
public:
  vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2)
  {
    // Result vector to store the unique elements for both input arrays
    vector<vector<int>> result;

    // Frequency maps to keep track of occurrences in each array
    unordered_map<int, int> frequencyMap1;
    unordered_map<int, int> frequencyMap2;

    // Populate the frequency maps for both arrays
    for (int i = 0; i < max(nums1.size(), nums2.size()); i++)
    {
      if (i < nums1.size())
      {
        frequencyMap1[nums1[i]]++;
      }

      if (i < nums2.size())
      {
        frequencyMap2[nums2[i]]++;
      }
    }

    // Sets to store unique elements from nums1 not in nums2 and vice versa
    unordered_set<int> uniqueInNums1;
    unordered_set<int> uniqueInNums2;

    // Identify unique elements in nums1 that are not in nums2
    for (int i : nums1)
    {
      if (frequencyMap2.find(i) == frequencyMap2.end())
      {
        uniqueInNums1.insert(i);
      }
    }

    // Identify unique elements in nums2 that are not in nums1
    for (int i : nums2)
    {
      if (frequencyMap1.find(i) == frequencyMap1.end())
      {
        uniqueInNums2.insert(i);
      }
    }

    // Convert sets to vectors and add them to the result
    result.emplace_back(uniqueInNums1.begin(), uniqueInNums1.end());
    result.emplace_back(uniqueInNums2.begin(), uniqueInNums2.end());

    return result;
  }
};

int main()
{
  Solution sol;
  vector<int> nums1 = {1, 2, 3, 4, 5};
  vector<int> nums2 = {1, 2, 3, 4, 5, 6};

  vector<vector<int>> result = sol.findDifference(nums1, nums2);

  return 0;
}