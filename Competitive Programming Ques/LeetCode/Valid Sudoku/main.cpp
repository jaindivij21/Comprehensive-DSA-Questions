// Leetcode: Valid Sudoku
// https://leetcode.com/problems/valid-sudoku

#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
   public:
    bool isValidSudoku(const vector<vector<char> > &board)
    {
        // Use sets to track digits seen in each row, column, and 3x3 subgrid
        vector<unordered_set<int> > rows(9);
        vector<unordered_set<int> > columns(9);
        vector<unordered_set<int> > subgrids(9);

        for (int row = 0; row < 9; ++row)
        {
            for (int col = 0; col < 9; ++col)
            {
                const char cell = board[row][col];
                if (cell == '.') continue;

                int digit = cell - '0';
                const int subgridIndex = (row / 3) * 3 + (col / 3);

                // Check for duplicates
                if (rows[row].count(digit) || columns[col].count(digit) ||
                    subgrids[subgridIndex].count(digit))
                {
                    return false;
                }

                // Insert digit into respective sets
                rows[row].insert(digit);
                columns[col].insert(digit);
                subgrids[subgridIndex].insert(digit);
            }
        }

        return true;
    }
};

int main()
{
    Solution sol;
    vector<vector<int> > board = {
        {'.', '.', '4', '.', '.', '.', '6', '3', '.'},
        {'.', '.', '.', '.', '5', '.', '.', '9', '.'},
        {'.', '.', '.', '4', '.', '3', '.', '.', '.'},
        {'8', '.', '.', '.', '.', '2', '.', '.', '.'},
        {'.', '7', '.', '.', '1', '.', '5', '.', '.'},
        {'.', '1', '2', '.', '.', '6', '3', '.', '.'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '5', '2', '.', '.', '.', '7', '.'},
        {'.', '8', '.', '.', '3', '.', '.', '4', '.'}};

    cout << sol.isValidSudoku(board) << endl;

    return 0;
}
