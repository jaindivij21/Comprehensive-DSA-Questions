// Leetcode: First Completely Painted Row or Column
// https://leetcode.com/problems/first-completely-painted-row-or-column

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
public:
  int firstCompleteIndex(vector<int> &arr, vector<vector<int>> &mat)
  {
    // Store the number of rows and columns.
    int numRows = mat.size();
    int numCols = mat[0].size();

    // Map to store the indices of each number in the matrix.
    unordered_map<int, pair<int, int>> valueToIndex;
    for (int row = 0; row < numRows; row++)
    {
      for (int col = 0; col < numCols; col++)
      {
        valueToIndex[mat[row][col]] = {row, col};
      }
    }

    // Vectors to track the count of painted cells in each row and column.
    vector<int> paintedRows(numRows, 0);
    vector<int> paintedCols(numCols, 0);

    // Iterate through the numbers in the order they are painted.
    for (int step = 0; step < arr.size(); step++)
    {
      int number = arr[step];

      // Get the row and column indices for the current number.
      int row = valueToIndex[number].first;
      int col = valueToIndex[number].second;

      // Increment the count of painted cells for the respective row and column.
      paintedRows[row]++;
      paintedCols[col]++;

      // Check if the current row or column is completely painted.
      if (paintedRows[row] == numCols || paintedCols[col] == numRows)
      {
        return step; // Return the index of the step where the first row/column is fully painted.
      }
    }

    // This line will never be reached due to problem constraints.
    return -1;
  }
};

int main()
{
  Solution s;

  vector<int> arr = {1, 3, 4, 2};
  vector<vector<int>> mat = {{1, 4},
                             {2, 3}};

  cout << s.firstCompleteIndex(arr, mat) << endl;

  return 0;
}