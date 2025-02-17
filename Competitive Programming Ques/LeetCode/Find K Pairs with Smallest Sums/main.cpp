// Leetcode: Find K Pairs with Smallest Sums
// https://leetcode.com/problems/find-k-pairs-with-smallest-sums

#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

class Solution
{
public:
  vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
  {
    // Min-heap to store pairs based on their sum
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> minHeap;

    // Set to keep track of visited index pairs
    set<pair<int, int>> visited;

    vector<vector<int>> result;
    if (nums1.empty() || nums2.empty() || k == 0)
      return result;

    // Start with the smallest sum pair (first elements of both arrays)
    minHeap.push({nums1[0] + nums2[0], {0, 0}});
    visited.insert({0, 0});

    while (k-- && !minHeap.empty())
    {
      auto [sum, indices] = minHeap.top();
      minHeap.pop();

      int i = indices.first, j = indices.second;
      result.push_back({nums1[i], nums2[j]});

      // Push next pair (i+1, j) if within bounds and not visited
      if (i + 1 < nums1.size() && visited.insert({i + 1, j}).second)
      {
        minHeap.push({nums1[i + 1] + nums2[j], {i + 1, j}});
      }

      // Push next pair (i, j+1) if within bounds and not visited
      if (j + 1 < nums2.size() && visited.insert({i, j + 1}).second)
      {
        minHeap.push({nums1[i] + nums2[j + 1], {i, j + 1}});
      }
    }

    return result;
  }
};

int main()
{
  Solution s;
  vector<int> nums1 = {1, 7, 11};
  vector<int> nums2 = {2, 4, 6};

  vector<vector<int>> result = s.kSmallestPairs(nums1, nums2, 3);

  for (auto &i : result)
  {
    cout << i[0] << " " << i[1] << endl;
  }

  return 0;
}