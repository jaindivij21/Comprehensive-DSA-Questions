// Leetcode: Find Valid Matrix Given Row and Column Sums
// https://leetcode.com/problems/find-valid-matrix-given-row-and-column-sums

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> restoreMatrix(vector<int> &rowSum, vector<int> &colSum)
{
  vector<vector<int>> ans(rowSum.size(), vector<int>(colSum.size(), 0));
  for (int i = 0; i < ans.size(); i++)
  {
    for (int j = 0; j < ans[0].size(); j++)
    {
      ans[i][j] = min(rowSum[i], colSum[j]);
      rowSum[i] -= ans[i][j];
      colSum[j] -= ans[i][j];
    }
  }

  return ans;
}

int main()
{
  vector<int> rowSum = {3, 8};
  vector<int> colSum = {4, 7};

  vector<vector<int>> ans = restoreMatrix(rowSum, colSum);

  return 0;
}