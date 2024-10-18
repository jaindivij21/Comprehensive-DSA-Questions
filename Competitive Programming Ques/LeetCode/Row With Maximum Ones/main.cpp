// Leetcode: Row With Maximum Ones
// https://leetcode.com/problems/row-with-maximum-ones

#include <iostream>

using namespace std;

class Solution
{
public:
  vector<int> rowAndMaximumOnes(vector<vector<int>> &mat)
  {
    pair<int, int> ans = {0, 0};
    for (int i = 0; i < mat.size(); i++)
    {
      int count = 0;
      for (auto j : mat[i])
      {
        if (j == 1)
          count++;
      }

      if (count > ans.second)
      {
        ans = make_pair(i, count);
      }
    }

    return {ans.first, ans.second};
  }
};

int main()
{
  vector<vector<int>> mat = {{0, 0, 0, 1},
                             {0, 1, 1, 1},
                             {1, 1, 1, 1},
                             {0, 0, 0, 0}};
  Solution solution;
  vector<int> result = solution.rowAndMaximumOnes(mat);

  return 0;
}
