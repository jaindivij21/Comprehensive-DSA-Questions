// Leetcode: Regions Cut By Slashes
// https://leetcode.com/problems/regions-cut-by-slashes/

// Help: https://leetcode.com/problems/regions-cut-by-slashes/solutions/5615005/striver-s-type-dfs-code-easy-to-understand

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  int regionsBySlashes(vector<string> &grid)
  {
    // Construct the extended grid
    vector<vector<int>> extendedGrid = extendGrid(grid);

    // DFS over the extended grid and calculate number of disjoint graphs
    int noOfDisjointGraphs = 0;
    vector<vector<bool>> visited(extendedGrid.size(), vector<bool>(extendedGrid[0].size(), false));

    for (int i = 0; i < extendedGrid.size(); i++)
    {
      for (int j = 0; j < extendedGrid[i].size(); j++)
      {
        // For every edge on the extended grid, run the DFS
        if (extendedGrid[i][j] == 0 && !visited[i][j])
        {
          DFS(extendedGrid, visited, i, j);
          noOfDisjointGraphs++;
        }
      }
    }

    return noOfDisjointGraphs;
  }

private:
  static void DFS(vector<vector<int>> &extendedGrid, vector<vector<bool>> &visited, int i, int j)
  {
    if (!isInsideGrid(extendedGrid.size(), i, j) || visited[i][j] || extendedGrid[i][j] == 1)
      return;

    visited[i][j] = true;
    DFS(extendedGrid, visited, i - 1, j);
    DFS(extendedGrid, visited, i + 1, j);
    DFS(extendedGrid, visited, i, j - 1);
    DFS(extendedGrid, visited, i, j + 1);
  }

  static vector<vector<int>> extendGrid(vector<string> &grid)
  {
    int n = grid.size();
    vector<vector<int>> extendedGrid(3 * n, vector<int>(3 * n, 0));
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < grid[i].size(); j++)
      {
        if (grid[i][j] == '/')
        {
          extendedGrid[3 * i][3 * j + 2] = 1;
          extendedGrid[3 * i + 1][3 * j + 1] = 1;
          extendedGrid[3 * i + 2][3 * j] = 1;
        }
        else if (grid[i][j] == '\\')
        {
          extendedGrid[3 * i][3 * j] = 1;
          extendedGrid[3 * i + 1][3 * j + 1] = 1;
          extendedGrid[3 * i + 2][3 * j + 2] = 1;
        }
      }
    }

    return extendedGrid;
  }

  static bool isInsideGrid(int size, int r, int c)
  {
    return r >= 0 && r < size && c >= 0 && c < size;
  }
};

int main()
{
  vector<string> grid = {" /", "/ "};
  Solution solution;
  cout << solution.regionsBySlashes(grid) << endl;
  return 0;
}