// Leetcode: Maximum Matrix Sum
// https://leetcode.com/problems/maximum-matrix-sum

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  long long maxMatrixSum(vector<vector<int>> &matrix)
  {
    // Minimum absolute value in the matrix
    int minAbsValue = INT_MAX;
    // Count of negative numbers in the matrix
    int negativeCount = 0;
    // Total sum of absolute values of all elements in the matrix
    long long totalAbsSum = 0;

    // Traverse the matrix using range-based loops
    for (const auto &row : matrix)
    {
      for (const auto &element : row)
      {
        // Update count of negative numbers
        if (element < 0)
          negativeCount++;

        // Update minimum absolute value
        minAbsValue = min(minAbsValue, abs(element));

        // Accumulate the absolute value sum
        totalAbsSum += abs(element);
      }
    }

    // Determine the maximum possible sum:
    // If the number of negatives is even, all can be flipped for maximum sum.
    // If odd, one element must remain negative, reducing the total sum by twice the smallest absolute value.
    return (negativeCount % 2 == 0) ? totalAbsSum : totalAbsSum - 2 * minAbsValue;
  }
};

int main()
{
  Solution sol;

  vector<vector<int>> matrix = {{1, -1},
                                {-1, 1}};
  cout << sol.maxMatrixSum(matrix) << endl;

  return 0;
}