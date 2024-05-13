// Score After Flipping Matrix
// https://leetcode.com/problems/score-after-flipping-matrix

#include <iostream>
#include <vector>

using namespace std;

int convertArrayIntoNumber(vector<int> &row)
{
  int num = 0;

  int powerOfTwo = 1;
  for (int i = row.size() - 1; i >= 0; i--)
  {
    if (row[i] == 1)
    {
      num += powerOfTwo;
    }
    powerOfTwo *= 2;
  }

  return num;
}

void flipRow(vector<int> &row)
{
  for (int i = 0; i < row.size(); i++)
  {
    row[i] = row[i] ^ 1;
  }
}

void flipCol(vector<vector<int>> &grid, int colIdx)
{
  for (int row = 0; row < grid.size(); row++)
  {
    grid[row][colIdx] = grid[row][colIdx] ^ 1;
  }
}

/*
Aim of this method is to maximize the sums of each number formed from the binary interpretation of each row.
Approach: We can follow the greedy approach to achieve the following result:
    1. Firstly we can invert each row whose highest bit is 0, because doing so will automatically guarantee us the largest possible number.
    2. Secondly, we loop over each column and invert it in if number of 0s are more than the 1s, which again guarantees us a larger number, since each index would represent the same power of 2.
*/
int matrixScore(vector<vector<int>> &grid)
{
  // Row Operation
  for (int row = 0; row < grid.size(); row++)
  {
    if (grid[row][0] == 0)
    {
      flipRow(grid[row]);
    }
  }

  // Column Operation
  for (int col = 0; col < grid[0].size(); col++)
  {
    int numOfOnes = 0, numOfZeros = 0;
    for (int row = 0; row < grid.size(); row++)
    {
      if (grid[row][col] == 1)
      {
        numOfOnes++;
      }
      else
      {
        numOfZeros++;
      }
    }

    if (numOfZeros > numOfOnes)
    {
      flipCol(grid, col);
    }
  }

  // Calc the sum and return the ans
  int ans = 0;
  for (int row = 0; row < grid.size(); row++)
  {
    ans += convertArrayIntoNumber(grid[row]);
  }

  return ans;
}

int main()
{
  // Take Inputs
  int rows, cols;
  cin >> rows >> cols;

  vector<vector<int>> nums(rows, vector<int>(cols));

  // Take Input for 2D Vector
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      cin >> nums[i][j];
    }
  }

  cout << matrixScore(nums);

  return 0;
}