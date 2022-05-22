// Leetcode ::  Set Matrix Zeroes
// https://leetcode.com/problems/set-matrix-zeroes/

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// main functions
// O(1) solution to store the rows and columns
void setZeroes(vector<vector<int>> &matrix)
{
  unordered_set<int> row;
  unordered_set<int> column;

  // iterate over the entire matrix and store the rows and columns with a 0 in it uniquely
  for (int i = 0; i < matrix.size(); i++)
  {
    for (int j = 0; j < matrix[0].size(); j++)
    {
      if (matrix[i][j] == 0)
      {
        row.insert(i);
        column.insert(j);
      }
    }
  }

  unordered_set<int>::iterator itr;

  // make the rows - 0
  for (itr = row.begin(); itr != row.end(); itr++)
  {
    int rowNum = *itr;
    for (int j = 0; j < matrix[0].size(); j++)
    {
      matrix[rowNum][j] = 0;
    }
  }
  // make the cols - 0
  for (itr = column.begin(); itr != column.end(); itr++)
  {
    int colNum = *itr;
    for (int i = 0; i < matrix.size(); i++)
    {
      matrix[i][colNum] = 0;
    }
  }
}

int main()
{
  // input the sizes
  int m, n;
  cin >> m >> n;

  vector<vector<int>> matrix(m, vector<int>(n));

  // input the matrix
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> matrix[i][j];
    }
  }

  // main function - if an element is 0, set its entire row and column to 0's.
  setZeroes(matrix);

  // print the matrix
  for (auto i : matrix)
  {
    for (auto j : i)
    {
      cout << j << " ";
    }
    cout << endl;
  }

  return 0;
}
