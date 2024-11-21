// Leetcode: Count Unguarded Cells in the Grid
// https://leetcode.com/problems/count-unguarded-cells-in-the-grid

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  int countUnguarded(int m, int n, vector<vector<int>> &guards, vector<vector<int>> &walls)
  {
    vector<vector<int>> grid(m, vector<int>(n, 0));
    int unguarded = m * n;

    // Mark walls and guards
    for (const auto &wall : walls)
    {
      grid[wall[0]][wall[1]] = -1; // Wall
      unguarded--;
    }
    for (const auto &guard : guards)
    {
      grid[guard[0]][guard[1]] = -2; // Guard
      unguarded--;
    }

    // Directions for traversal: left, right, up, down
    vector<pair<int, int>> directions = {{0, -1},
                                         {0, 1},
                                         {-1, 0},
                                         {1, 0}};

    // Mark cells guarded by each guard
    for (const auto &guard : guards)
    {
      for (const auto &dir : directions)
      {
        int x = guard[0], y = guard[1];

        while (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] != -1)
        {
          if (grid[x][y] == 0)
          {
            grid[x][y] = -3; // Guarded
            unguarded--;
          }
          x += dir.first;
          y += dir.second;
        }
      }
    }

    return unguarded;
  }
};

int main()
{
  Solution sol;

  int m = 3, n = 3;
  vector<vector<int>> guards = {{1, 1}};
  vector<vector<int>> walls = {{0, 1},
                               {1, 0},
                               {2, 1},
                               {1, 2}};
  cout << sol.countUnguarded(m, n, guards, walls) << endl;

  return 0;
}