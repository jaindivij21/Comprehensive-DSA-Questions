// Leetcode: Maximum Number of Moves in a Grid
// https://leetcode.com/problems/maximum-number-of-moves-in-a-grid

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  int maxMoves(vector<vector<int>> &grid)
  {
    // Initialize a memoization table with -1 to signify un-computed states
    vector<vector<int>> memo(grid.size(), vector<int>(grid[0].size(), -1));

    int maxMovesFromAnyStart = 0;

    // Try starting from every cell in the first column
    for (int row = 0; row < grid.size(); row++)
    {
      int movesFromCurrentStart = calculateMaxMoves(grid, memo, row, 0, INT_MIN);
      maxMovesFromAnyStart = max(maxMovesFromAnyStart, movesFromCurrentStart);
    }

    return maxMovesFromAnyStart;
  }

private:
  int calculateMaxMoves(vector<vector<int>> &grid, vector<vector<int>> &memo, int row, int col, int prevValue)
  {
    // Base cases
    // Check for out-of-bounds, invalid moves, or non-increasing sequence or if already computed
    if (row < 0 || row >= grid.size() || col >= grid[0].size() || grid[row][col] <= prevValue)
      return 0;
    if (memo[row][col] != -1)
      return memo[row][col];

    // Recursive three possible cases
    int maxMovesFromHere = max(
        {calculateMaxMoves(grid, memo, row - 1, col + 1, grid[row][col]),
         calculateMaxMoves(grid, memo, row, col + 1, grid[row][col]),
         calculateMaxMoves(grid, memo, row + 1, col + 1, grid[row][col])});

    // If starting from the first column, use `maxMovesFromHere` directly, otherwise increment by 1
    memo[row][col] = col == 0 ? maxMovesFromHere : 1 + maxMovesFromHere;
    return memo[row][col];
  }
};

int main()
{
  Solution sol;
  vector<vector<int>> grid = {{2, 4, 3, 5},
                              {5, 4, 9, 3},
                              {3, 4, 2, 11},
                              {10, 9, 13, 15}};
  cout << sol.maxMoves(grid) << endl;

  return 0;
}