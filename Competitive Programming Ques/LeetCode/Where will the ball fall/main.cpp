// Leetcode : Where Will the Ball Fall
// https://leetcode.com/problems/where-will-the-ball-fall/

// Basically do a traversal (DFS) for each ball at the top. The movement is defined by the diagonal's direction

#include<bits/stdc++.h>

using namespace std;

// dfs call
int dfs(vector<vector<int>> &grid, set<pair<int, int>> &visited, int i, int j, int prev) {
    // base case
    // out left or right boundary
    if (j < 0 || j >= grid[0].size()) {
        return -1;
    }
    // if we visit the already visited
    if (visited.find(make_pair(i, j)) != visited.end()) {
        return -1;
    }
    // if we cross the bottom boundary
    if (i == grid.size())
        return j;

    // mark visited
    visited.insert(make_pair(i, j));
    // recursive cases
    if (grid[i][j] == 1) {
        // '\'
        if (prev == 1) {
            return dfs(grid, visited, i, j + 1, 3);
        } else if (prev == 2) {
            return dfs(grid, visited, i, j + 1, 3);
        } else if (prev == 3) {
            return dfs(grid, visited, i + 1, j, 1);
        }
    } else if (grid[i][j] == -1) {
        // '/'
        if (prev == 1) {
            return dfs(grid, visited, i, j - 1, 2);
        } else if (prev == 2) {
            return dfs(grid, visited, i + 1, j, 1);
        } else if (prev == 3) {
            return dfs(grid, visited, i, j - 1, 2);
        }
    }
    return -1;
}

// main function :: makes a dfs call for every ball
vector<int> findBall(vector<vector<int>> &grid) {
    vector<int> ans;    // ans vector that holds the col where the ball ended up
    set<pair<int, int>> visited;    // keep track of all the visited indexes
    // need to do a dfs traversal for all the balls
    // 1-top, 2-right, 3-left (prev position)
    for (int i = 0; i < grid[0].size(); i++) {
        int res = dfs(grid, visited, 0, i, 1);
        visited.clear();
        ans.push_back(res);
    }
    return ans;
}

int main() {
    vector<vector<int>> grid = {{1,  1,  1,  -1, -1},
                                {1,  1,  1,  -1, -1},
                                {-1, -1, -1, 1,  1},
                                {1,  1,  1,  1,  -1},
                                {-1, -1, -1, -1, -1}};
    vector<int> ans = findBall(grid);
    return 0;
}