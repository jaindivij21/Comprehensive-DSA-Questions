// Leetcode: Rotating the Box
// https://leetcode.com/problems/rotating-the-box/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  vector<vector<char>> rotateTheBox(vector<vector<char>> &box)
  {
    // Matrix Size
    int m = box.size();
    int n = box[0].size();

    // Make a result n x m matrix
    vector<vector<char>> resultMatrix(n, vector<char>(m));

    // Loop over the original matrix from the end and start filling up the resultant matrix
    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        resultMatrix[j][m - 1 - i] = box[i][j];
      }
    }

    // Adjust the positions of the rocks
    for (int i = 0; i < m; i++)
    {
      int j = n - 1, k = n - 1;

      while (j >= 0)
      {
        if (resultMatrix[j][i] == '#')
        {
          // If it's a stone, place it as k and update k
          resultMatrix[j][i] = '.';
          resultMatrix[k][i] = '#';
          k--;
        }
        else if (resultMatrix[j][i] == '*')
        {
          // If it's an obstacle, update k
          k = j - 1;
        }

        j--;
      }
    }

    return resultMatrix;
  }
};

int main()
{
  Solution sol;

  vector<vector<char>> box = {{'#', '.', '*', '.'}, {'#', '#', '*', '.'}};
  vector<vector<char>> result = sol.rotateTheBox(box);

  return 0;
}