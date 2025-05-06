// Leetcode: Min Cost Climbing Stairs
// https://leetcode.com/problems/min-cost-climbing-stairs

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// Recursion with Memorization: Top-Down Approach
class Solution
{
   public:
    // Memoization map to store the minimum cost to reach a given stair
    unordered_map<int, int> memo;

    // Main function to find the minimum cost of climbing stairs
    int minCostClimbingStairs(vector<int> &cost)
    {
        // The minimum cost to start at either of the first two steps and reach
        // the top
        return min(minCostFromStair(0, cost), minCostFromStair(1, cost));
    }

   private:
    // Helper function to calculate the minimum cost starting from stair index
    // 'i'
    int minCostFromStair(int i, vector<int> &cost)
    {
        // If the cost for this stair has already been computed, return it
        if (memo.find(i) != memo.end())
        {
            return memo[i];
        }

        // Base case: If index exceeds or reaches the size of the cost array, no
        // more cost
        if (i >= cost.size())
        {
            return 0;
        }

        // Recursive case: Calculate the cost by moving 1 step or 2 steps ahead
        int costFromNextStair = minCostFromStair(i + 1, cost);
        int costFromTwoStairsAhead = minCostFromStair(i + 2, cost);

        // The total cost for the current stair is its cost + the minimum cost
        // from the next valid stairs
        int totalCost =
            cost[i] + min(costFromNextStair, costFromTwoStairsAhead);

        // Memoize the result for the current stair index to avoid redundant
        // calculations
        memo[i] = totalCost;

        // Return the computed minimum cost
        return totalCost;
    }
};

int main()
{
    Solution solution;
    vector<int> cost = {10, 15, 20};

    cout << "Minimum cost to reach the top: "
         << solution.minCostClimbingStairs(cost) << endl;

    return 0;
}
