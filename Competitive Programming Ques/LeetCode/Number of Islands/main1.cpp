// Leetcode : Number of Islands
// https://leetcode.com/problems/number-of-islands/

// DFS Solution : do not make a visited array rather change the given matrix only to save space

#include<bits/stdc++.h>

using namespace std;

// dfs function :: traverses the entire island and replaces it's 1's with # :: recursion
void dfs(vector<vector<char>> &grid, int i, int j) {
    grid[i][j] = '#';   // mark it as visited
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};   // displacement arrays
    for (int k = 0; k < 4; k++) {
        // for all the four directions : check if there is a connecting 1
        int m = i + dx[k];
        int n = j + dy[k];
        if (m >= 0 && m < grid.size() && n >= 0 && n < grid[0].size() && grid[m][n] == '1') {
            // if they are within the boundaries
            dfs(grid, m, n);
        }
    }
}

// main function
int numIslands(vector<vector<char>> &grid) {
    int count = 0;  // ans
    // loop to traverse through the entire island
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            if (grid[i][j] == '1') {
                // means it is a univisted island's part
                count++;
                dfs(grid, i, j);
            }
        }
    }
    return count;
}

int main() {
    int grid[4][5] = {
            {'1', '1', '1', '1', '0'},
            {'1', '1', '0', '1', '0'},
            {'1', '1', '0', '0', '0'},
            {'0', '0', '0', '0', '0'},
    };

    return 0;
}
