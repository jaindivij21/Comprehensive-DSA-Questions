// Leetcode : Max Area of Island
// https://leetcode.com/problems/max-area-of-island/

// DFS or BFS traversal over the grid to cal the area of each land and just store and finally return at last the max one.
// Using DFS in this solution for the ease of it.
// This question can be solved effectively since we dont need a visited array and we can just update the original matrix to keep track of places we have visited.

// Time Complexity : O(r*c) or simply O(n2)
// Space Complexity: O(r*c) if grid is considered which is already given (so ideally ) in the quesion otherwise only that memory would by required that is essential to the stack. Means the max height
// of the stack. The max height of the stack would be the largest island area in worst case, which again can be O(r*c) or O(n2)

#include<bits/stdc++.h>

using namespace std;

void dfs(vector<vector<int>> &grid, int &area, int i, int j) {
    // base case : mark the current index as visited and increment the area
    grid[i][j] = -1;    // visited index
    area++;

    // recursive cases :: call the dfs call on all the 4 directions
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};   // displacement vector
    for (int k = 0; k < 4; k++) {
        int m = i + dx[k];
        int n = j + dy[k];
        if (m >= 0 && m < grid.size() && n >= 0 && n < grid[0].size() && grid[m][n] == 1)
            dfs(grid, area, m, n);  // dfs call in all 4 directions
    }
}

// main function that places a dfs call over every newly discovered island
int maxAreaOfIsland(vector<vector<int>> &grid) {
    int maxArea = INT_MIN;
    // traverse over the entire matrix
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            // if we encounter a '1' means it's a part of a new unexplored island, therefore DFS on that island and explore it.
            if (grid[i][j] == 1) {
                int area = 0;
                dfs(grid, area, i, j);
                maxArea = max(area, maxArea);
            }
        }
    }
    return maxArea == INT_MIN ? 0 : maxArea;
}

int main() {
    vector<vector<int>> grid = {{0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
                                {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                                {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
                                {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
                                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                                {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
                                {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}};
    cout << maxAreaOfIsland(grid);
    return 0;
}