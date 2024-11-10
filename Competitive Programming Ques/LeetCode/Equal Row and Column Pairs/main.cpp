// Leetcode: Equal Row and Column Pairs
// https://leetcode.com/problems/equal-row-and-column-pairs

#include <iostream>

using namespace std;

class Solution
{
public:
  // Brute Force
  int equalPairs(vector<vector<int>> &grid)
  {
    int count = 0;
    for (int i = 0; i < grid.size(); i++)
    {
      for (int j = 0; j < grid[0].size(); j++)
      {
        bool ifMatch = true;
        for (int k = 0; k < grid.size(); k++)
        {
          if (grid[i][k] != grid[k][j])
          {
            ifMatch = false;
            break;
          }
        }
        if (ifMatch)
          count++;
      }
    }
    return count;
  }
};

int main()
{
  Solution s;
  vector<vector<int>> grid = {{1, 2, 3},
                              {4, 5, 6},
                              {7, 8, 9}};

  cout << s.equalPairs(grid) << endl;

  return 0;
}