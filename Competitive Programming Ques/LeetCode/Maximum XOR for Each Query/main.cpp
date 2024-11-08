// Leetcode: Maximum XOR for Each Query
// https://leetcode.com/problems/maximum-xor-for-each-query

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  vector<int> getMaximumXor(vector<int> &nums, int maximumBit)
  {
    vector<int> prefixXORs;
    int currXor = 0;

    // Calculate the prefix XOR for each element in nums and store it in prefixXORs
    for (auto num : nums)
    {
      currXor ^= num;
      prefixXORs.push_back(currXor);
    }

    vector<int> ans;
    int allSetBits = (1 << maximumBit) - 1; // Max value of k: all bits set within maximumBit

    // Traverse prefixXORs from the end to the beginning
    for (int i = prefixXORs.size() - 1; i >= 0; i--)
    {
      int maxXorWithK = prefixXORs[i] ^ allSetBits; // XOR with allSetBits for max result
      ans.push_back(maxXorWithK);
    }

    // Return the results for all queries
    return ans;
  }
};

int main()
{
  Solution sol;
  vector<int> nums = {0, 1, 1, 3};
  int maximumBit = 2;

  vector<int> result = sol.getMaximumXor(nums, maximumBit);

  return 0;
}