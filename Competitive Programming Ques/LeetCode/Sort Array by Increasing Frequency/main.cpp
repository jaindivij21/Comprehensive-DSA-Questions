// Leetcode: Sort Array by Increasing Frequency
// https://leetcode.com/problems/sort-array-by-increasing-frequency

#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution
{
public:
  vector<int> frequencySort(vector<int> &nums)
  {
    // Create a hash map to count the frequency of each number
    unordered_map<int, int> freq;
    for (const auto &num : nums)
    {
      freq[num]++;
    }

    // Sort the array based on the custom comparator
    sort(nums.begin(), nums.end(), [&freq](int a, int b)
         {
            // If frequencies are the same, sort by value in decreasing order
            if (freq[a] == freq[b]) {
                return a > b;
            }
            // Otherwise, sort by frequency in increasing order
            return freq[a] < freq[b]; });

    return nums;
  }
};

int main()
{
  vector<int> nums = {1, 1, 2, 2, 2, 3};

  Solution s;
  vector<int> ans = s.frequencySort(nums);

  return 0;
}
