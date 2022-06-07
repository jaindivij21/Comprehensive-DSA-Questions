// Leetcode :: Rotate Image

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// function to rotate the image 90 degrees
// essentially we are converting all the rows into columns : easy with extra space (another matrix)
// but need to do in place :: Transpose the matrix and reverse each row
void rotate(vector<vector<int>> &matrix)
{
  // transpose the matrix
  for (int i = 0; i < matrix.size(); i++)
  {
    for (int j = i; j < matrix[0].size(); j++)
    {
      swap(matrix[i][j], matrix[j][i]);
    }
  }
  // reverse each row
  for (auto &i : matrix)
  {
    reverse(i.begin(), i.end());
  }
}

int main()
{
  // input
  int rows, cols;
  cin >> rows >> cols;

  vector<vector<int>> arr(rows, vector<int>(cols));
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      cin >> arr[i][j];
    }
  }
  rotate(arr);
  return 0;
}