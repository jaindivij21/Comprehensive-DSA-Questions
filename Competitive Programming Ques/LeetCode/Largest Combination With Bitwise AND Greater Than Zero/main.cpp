// Leetcode: Largest Combination With Bitwise AND Greater Than Zero
// https://leetcode.com/problems/largest-combination-with-bitwise-and-greater-than-zero

#include <iostream>

using namespace std;

class Solution
{
public:
  int largestCombination(vector<int> &candidates)
  {
    int ans = 0;

    for (int i = 0; i < 32; i++)
    {
      int currCount = 0;
      for (auto candidate : candidates)
      {
        if (candidate & (1 << i))
          currCount++;
      }

      ans = max(ans, currCount);
    }

    return ans;
  }
};

int main()
{
  Solution sol;
  vector<int> candidates = {8, 8};

  cout << "Largest combination with bitwise AND greater than zero: " << sol.largestCombination(candidates) << endl;

  return 0;
}