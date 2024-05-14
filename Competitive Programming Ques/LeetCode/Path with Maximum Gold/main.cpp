// Path with Maximum Gold
// https://leetcode.com/problems/path-with-maximum-gold/

#include <iostream>
#include <vector>

using namespace std;

// Function to recursively find the maximum possible value of gold starting from a given cell (i, j)
int findMaxPossibleValue(int i, int j, vector<vector<int>> &grid, vector<vector<bool>> &visited)
{
  // Base Cases
  if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || visited[i][j] || grid[i][j] == 0)
  {
    // If out of bounds, already visited, or cell contains no gold, return 0
    return 0;
  }

  // Recursive Code
  visited[i][j] = true; // Mark the current cell as visited

  // Recursively explore all possible adjacent cells (left, right, up, down)
  int leftSum = findMaxPossibleValue(i, j - 1, grid, visited);
  int rightSum = findMaxPossibleValue(i, j + 1, grid, visited);
  int upSum = findMaxPossibleValue(i - 1, j, grid, visited);
  int downSum = findMaxPossibleValue(i + 1, j, grid, visited);

  visited[i][j] = false; // Unmark the current cell after exploring its neighbors

  // Find the maximum sum among all possible directions and add the gold value of the current cell
  return grid[i][j] + max({leftSum, rightSum, upSum, downSum});
}

// Function to get the maximum amount of gold that can be collected
int getMaximumGold(vector<vector<int>> &grid)
{
  int numRows = grid.size();
  int numCols = grid[0].size();
  int maxGold = 0;

  // Visited array to keep track of cells that have been visited
  vector<vector<bool>> visited(numRows, vector<bool>(numCols, false));

  // Iterate through each cell in the grid
  for (int i = 0; i < numRows; i++)
  {
    for (int j = 0; j < numCols; j++)
    {
      if (grid[i][j] != 0)
      { // If the cell contains gold
        // Find the maximum possible value of gold starting from this cell
        int currentGold = findMaxPossibleValue(i, j, grid, visited);
        // Update the maximum gold collected so far
        maxGold = max(maxGold, currentGold);
      }
    }
  }

  return maxGold; // Return the maximum amount of gold that can be collected
}

int main()
{
  // Take Inputs
  int rows, cols;
  cin >> rows >> cols;

  vector<vector<int>> nums(rows, vector<int>(cols));

  // Take Input for 2D Vector
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      cin >> nums[i][j];
    }
  }

  cout << getMaximumGold(nums);

  return 0;
}