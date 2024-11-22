// Leetcode: Flip Columns For Maximum Number of Equal Rows
// https://leetcode.com/problems/flip-columns-for-maximum-number-of-equal-rows
// https://www.youtube.com/watch?v=MsdLjL87BEo

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  int maxEqualRowsAfterFlips(vector<vector<int>> &matrix)
  {
    // Variable to store the maximum number of identical rows (after flips)
    int maxIdenticalRows = 0;

    // A hash map to store the frequency of transformed row patterns
    unordered_map<string, int> patternFrequency;

    // Iterate over each row in the matrix
    for (const auto &row : matrix)
    {
      string transformedPattern;

      // Determine the transformation to normalize the row
      // If the first element is 0, keep the row as is.
      // Otherwise, flip all elements in the row.
      if (row[0] == 0)
      {
        for (int value : row)
        {
          transformedPattern += to_string(value); // Append each element to form the pattern
        }
      }
      else
      {
        for (int value : row)
        {
          transformedPattern += to_string(1 - value); // Append the flipped element
        }
      }

      // Increment the frequency of the transformed pattern
      patternFrequency[transformedPattern]++;

      // Update the maximum count of identical rows
      maxIdenticalRows = max(maxIdenticalRows, patternFrequency[transformedPattern]);
    }

    return maxIdenticalRows;
  }
};

int main()
{
  Solution sol;

  vector<vector<int>> matrix = {{0, 1},
                                {1, 1}};
  cout << sol.maxEqualRowsAfterFlips(matrix) << endl;

  return 0;
}