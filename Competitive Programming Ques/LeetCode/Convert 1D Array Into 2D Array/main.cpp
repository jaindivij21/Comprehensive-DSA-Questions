// Convert 1D Array Into 2D Array :: Leetcode
// https://leetcode.com/problems/convert-1d-array-into-2d-array/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  vector<vector<int>> construct2DArray(vector<int> &original, int m, int n)
  {
    if (m * n != original.size())
      return {};

    vector<vector<int>> ans;
    for (auto i = original.begin(); i != original.end(); i += n)
    {
      ans.push_back(vector<int>(i, i + n));
    }

    return ans;
  }
};