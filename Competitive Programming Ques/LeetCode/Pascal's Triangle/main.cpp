// Leetcode ::  Pascal's Triangle
// https://leetcode.com/problems/pascals-triangle/

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> generate(int numRows)
{
  vector<vector<int>> ans;
  if (numRows >= 1)
  {
    ans.push_back({1});
  }
  vector<int> prev;
  if (numRows >= 2)
  {
    prev = {1, 1};
    ans.push_back(prev);
  }
  if (numRows >= 3)
  {
    for (int i = 3; i <= numRows; i++)
    {
      vector<int> curr(i, 1);
      for (int j = 1; j <= i - 2; j++)
      {
        curr[j] = prev[j - 1] + prev[j];
      }
      prev = curr;
      ans.push_back(curr);
    }
  }
  return ans;
}

int main()
{
  // input the number of rows
  int m;
  cin >> m;

  vector<vector<int>> pascal = generate(m);

  for (auto i : pascal)
  {
    for (auto j : i)
    {
      cout << j << " ";
    }
    cout << endl;
  }

  return 0;
}
