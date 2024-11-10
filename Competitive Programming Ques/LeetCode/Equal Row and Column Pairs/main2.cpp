// Leetcode: Equal Row and Column Pairs
// https://leetcode.com/problems/equal-row-and-column-pairs

#include <iostream>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  int equalPairs(vector<vector<int>> &grid)
  {
    unordered_map<string, int> rowHashes;

    for (int i = 0; i < grid.size(); i++)
    {
      string hash;
      for (int j = 0; j < grid[0].size(); j++)
      {
        hash += to_string(grid[i][j]) + ",";
      }
      rowHashes[hash]++;
    }

    int count = 0;

    for (int i = 0; i < grid[0].size(); i++)
    {
      string hash;
      for (int j = 0; j < grid.size(); j++)
      {
        hash += to_string(grid[j][i]) + ",";
      }

      if (rowHashes.find(hash) != rowHashes.end())
      {
        count += rowHashes[hash];
      }
    }

    return count;
  }
};

int main()
{
  Solution s;
  vector<vector<int>> grid = {{3, 2, 1},
                              {1, 7, 6},
                              {2, 7, 7}};

  cout << s.equalPairs(grid) << endl;

  return 0;
}