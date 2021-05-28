// Dynamic Programming : Min Cost Path in a 2D Matrix if you are allowed only to move right or bottom
/*
 *  Recursive solution would be top down approach, i.e. start with last cell (bottom right)
 *  Other approach is bottom up approach where we calculate the min cost of each cell and move our way up to the last cell.
 */


#include<bits/stdc++.h>

using namespace std;

int minCost(int grid[][100], int rows, int col) {
    int dp[100][100];

    // base case
    dp[0][0] = grid[0][0];

    // filling 1st row
    for (int i = 1; i < col; i++) {
        dp[0][i] = dp[0][i - 1] + grid[0][i];
    }
    // fill 1st column
    for (int i = 1; i < rows; i++) {
        dp[i][0] = dp[i - 1][0] + grid[i][0];
    }
    // fill the left dp table
    for (int i = 1; i < rows; i++) {
        for (int j = 1; j < col; j++) {
            dp[i][j] = min(
                    dp[i - 1][j],
                    dp[i][j - 1]) + grid[i][j];
        }
    }

    // for ease printing the dp table
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < col; j++) {
            cout << setw(3) << dp[i][j] << " ";
        }
        cout << endl;
    }

    // return ans
    return dp[rows - 1][col - 1];

}

int main() {
    int grid[100][100] = {
            {1, 2, 3},
            {4, 8, 2},
            {1, 5, 3}
    };

    cout << "Min Cost to traverse the table is: " << minCost(grid, 3, 3) << endl;

    return 0;
}