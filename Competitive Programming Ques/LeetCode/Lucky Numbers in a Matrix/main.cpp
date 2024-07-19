// Leetcode: Lucky Numbers in a Matrix
// https://leetcode.com/problems/lucky-numbers-in-a-matrix

#include <iostream>
#include <vector>

using namespace std;

vector<int> luckyNumbers(vector<vector<int>> &matrix)
{
  int numRows = matrix.size();
  int numCols = matrix[0].size();

  // It will store the minimum element of each row in the respective column index
  // Initialize with -1 to indicate unassigned columns
  vector<int> rowMinInCol(max(numRows, numCols), -1);

  // Find the minimum element in each row and record it in rowMinInCol
  for (int row = 0; row < numRows; row++)
  {
    int minElement = INT_MAX;
    int minColIndex;
    for (int col = 0; col < numCols; col++)
    {
      if (matrix[row][col] < minElement)
      {
        minColIndex = col;
        minElement = matrix[row][col];
      }
    }
    // Store the minimum element at the corresponding column index
    rowMinInCol[minColIndex] = max(rowMinInCol[minColIndex], minElement);
  }

  vector<int> luckyNumbers;

  // Check if the minimum element in the row is also the maximum element in its column
  for (int col = 0; col < rowMinInCol.size(); col++)
  {
    if (rowMinInCol[col] == -1)
      continue; // Skip unassigned columns

    int maxElement = INT_MIN;
    for (int row = 0; row < numRows; row++)
    {
      maxElement = max(maxElement, matrix[row][col]);
    }

    // If the column's maximum element is the same as the row's minimum element, it is a lucky number
    if (maxElement == rowMinInCol[col])
    {
      luckyNumbers.push_back(maxElement);
    }
  }

  return luckyNumbers;
}

int main()
{
  vector<vector<int>> matrix = {{7, 8},
                                {1, 2}};
  cout << "Lucky numbers in the matrix are: ";
  vector<int> result = luckyNumbers(matrix);
  for (int i : result)
  {
    cout << i << " ";
  }
  cout << endl;

  return 0;
}