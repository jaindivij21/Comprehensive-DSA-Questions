// Leetcode: Find Champion II
// https://leetcode.com/problems/find-champion-ii

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  int findChampion(vector<vector<int>> &grid)
  {
    int res = 0;
    int maxCount = INT_MIN;
    for (int i = 0; i < grid.size(); i++)
    {
      int count = 0;
      for (int j = 0; j < grid[0].size(); j++)
      {
        if (grid[i][j] == 1)
          count++;
      }

      if (count > maxCount)
      {
        res = i;
        maxCount = count;
      }
    }

    return res;
  }
};

int main()
{
  Solution sol;
  vector<vector<int>> grid = {{0, 1},
                              {0, 0}};

  cout << sol.findChampion(grid) << endl;

  return 0;
}