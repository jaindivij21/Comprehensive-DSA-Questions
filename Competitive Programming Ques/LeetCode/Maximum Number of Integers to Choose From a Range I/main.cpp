// Leetcode: Maximum Number of Integers to Choose From a Range I
// https://leetcode.com/problems/maximum-number-of-integers-to-choose-from-a-range-i

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution
{
public:
  int maxCount(vector<int> &banned, int n, int maxSum)
  {
    // Sort and use a set for fast lookup
    unordered_set<int> bannedSet(banned.begin(), banned.end());

    int currSum = 0, maxCount = 0;

    for (int i = 1; i <= n; i++)
    {
      // Skip banned numbers
      if (bannedSet.find(i) != bannedSet.end())
      {
        continue;
      }

      currSum += i;

      // Check if we can include the current number
      if (currSum > maxSum)
      {
        break;
      }

      maxCount++;
    }

    return maxCount;
  }
};

int main()
{
  Solution sol;
  vector<int> banned = {1, 6, 5};
  int n = 5;
  int maxSum = 6;
  cout << sol.maxCount(banned, n, maxSum) << endl;

  return 0;
}