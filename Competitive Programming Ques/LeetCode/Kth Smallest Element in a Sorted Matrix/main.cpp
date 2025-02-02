// Leetcode: Kth Smallest Element in a Sorted Matrix
// https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix
// https://www.youtube.com/watch?v=MOe7LlagCN8

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
  int kthSmallest(std::vector<std::vector<int>> &matrix, int k)
  {
    int numRows = matrix.size();
    int numCols = matrix[0].size();

    // Set the binary search range
    int left = matrix[0][0];                      // Smallest element (top-left corner)
    int right = matrix[numRows - 1][numCols - 1]; // Largest element (bottom-right corner)

    int result = -1;

    // Perform binary search on the values in the matrix
    while (left <= right)
    {
      int mid = left + (right - left) / 2; // Midpoint element value to check

      // If there are enough elements <= mid, move to the left half
      if (countSmallerOrEqual(matrix, mid) >= k)
      {
        result = mid;
        right = mid - 1; // Narrow down the search to smaller values
      }
      else
      {
        left = mid + 1; // Narrow down the search to larger values
      }
    }

    // The kth smallest element found
    return result;
  }

private:
  // Function to count how many elements in the matrix are <= mid
  int countSmallerOrEqual(const std::vector<std::vector<int>> &matrix, int mid)
  {
    int numRows = matrix.size();
    int numCols = matrix[0].size();

    int count = 0;

    // Iterate over each row and count how many elements are <= mid
    for (int row = 0; row < numRows; row++)
    {
      if (matrix[row][numCols - 1] <= mid)
      {
        // All elements in the row are <= mid
        count += numCols;
      }
      else
      {
        // Use upper_bound to count elements <= mid in the current row
        count += std::upper_bound(matrix[row].begin(), matrix[row].end(), mid) - matrix[row].begin();
      }
    }

    // Return the total number of elements <= mid
    return count;
  }
};

int main()
{
  Solution s;
  vector<vector<int>> matrix = {
      {1, 5, 9},
      {10, 11, 13},
      {12, 13, 15}};

  cout << s.kthSmallest(matrix, 8) << endl;

  return 0;
}