// Leetcode: Sort the Jumbled Numbers
// https://leetcode.com/problems/sort-the-jumbled-numbers

#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
  static vector<int> sortJumbled(vector<int> &mapping, vector<int> &nums)
  {
    // Vector to hold the mapped values
    vector<pair<int, int>> mappedValues;

    // Map each number to its mapped value
    for (int num : nums)
    {
      int mappedNum = _getMappedNum(mapping, num);
      mappedValues.emplace_back(mappedNum, num);
    }

    // Sort based on the mapped values
    sort(mappedValues.begin(), mappedValues.end(), [](const pair<int, int> &a, const pair<int, int> &b)
         { return a.first < b.first; });

    // Extract the sorted numbers
    vector<int> sortedNums;
    for (const auto &p : mappedValues)
    {
      sortedNums.push_back(p.second);
    }

    return sortedNums;
  }

private:
  static int _getMappedNum(const vector<int> &mapping, int num)
  {
    if (num == 0)
      return mapping[0];

    int ans = 0;
    int power = 1;

    while (num > 0)
    {
      int digit = num % 10;
      int mappedDigit = mapping[digit];
      ans += power * mappedDigit;

      num /= 10;
      power *= 10;
    }

    return ans;
  }
};

int main()
{
  vector<int> mapping = {8, 9, 4, 0, 2, 1, 3, 5, 7, 6};
  vector<int> nums = {991, 338, 38};

  Solution s;
  vector<int> ans = Solution::sortJumbled(mapping, nums);

  return 0;
}
