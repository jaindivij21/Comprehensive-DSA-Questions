// Leetcode: House Robber
// https://leetcode.com/problems/house-robber

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
   public:
    static int rob(const vector<int> &houses)
    {
        vector<int> memo(houses.size(), -1);
        return getMaxLoot(houses, 0, memo);  // Start from the first house
    }

   private:
    static int getMaxLoot(const vector<int> &houses, const int currentIndex,
                          vector<int> &memo)
    {
        // Base Case: If index is out of bounds, return 0 (no more houses to
        // rob)
        if (currentIndex >= houses.size()) return 0;

        // If already computed, return stored result
        if (memo[currentIndex] != -1) return memo[currentIndex];

        int maxLoot = 0;
        // Loop through the remaining houses, following your original logic
        for (int i = currentIndex; i < houses.size(); i++)
        {
            maxLoot = max(maxLoot, houses[i] + getMaxLoot(houses, i + 2, memo));
        }

        // Store result in memoization table
        memo[currentIndex] = maxLoot;
        return maxLoot;
    }
};

int main()
{
    Solution solution;

    vector<int> nums = {2, 1, 1, 2};
    cout << solution.rob(nums) << endl;

    return 0;
}
