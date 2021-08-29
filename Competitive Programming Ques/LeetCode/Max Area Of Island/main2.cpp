// Leetcode : Max Area of Island
// https://leetcode.com/problems/max-area-of-island/

// DFS or BFS traversal over the grid to cal the area of each land and just store and finally return at last the max one.
// Using BFS in this solution :: Iterative Solution

#include<bits/stdc++.h>

using namespace std;

// main function that places a dfs call over every newly discovered island
int maxAreaOfIsland(vector<vector<int>> &grid) {
    int maxArea = INT_MIN;  // ans variable

    // size of the grid
    int rows = grid.size();
    int cols = grid[0].size();

    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};   // displacement vector for further use in the function

    // traverse over the entire matrix
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {

            // if we find an island continue searching for its entirety using BFS
            if (grid[i][j] == 1) {
                int area = 0;   // increment the land area
                queue<pair<int, int>> q; // queue for tracking bfs

                q.push(make_pair(i, j));    // insert the current index into the queue

                // bfs call
                while (!q.empty()) {
                    pair<int, int> p = q.front();    // extract the pair, process it and push into the queue all its 4 neighbors
                    q.pop();    // remove the read element from the queue
                    // mark the grid index as visited
                    grid[p.first][p.second] = -1;
                    area++; // increment the area

                    // push all its 4 neighbors
                    for (int k = 0; k < 4; k++) {
                        int m = p.first + dx[k];
                        int n = p.second + dy[k];   // new coordinates
                        // if the new coordinates are within the boundaries and have a value eql to 1 then add them to queue
                        if (m >= 0 && m < rows && n >= 0 && n < cols && grid[m][n] == 1) {
                            grid[m][n] = -1;    // it IS IMPORTANT TO MARK THE NODE AS VISITED BEFORE ADDING IT TO THE QUEUE
                            q.push(make_pair(m, n));
                        }
                    }
                }
                maxArea = max(area, maxArea);   // update the final ans
            }
        }
    }
    return maxArea == INT_MIN ? 0 : maxArea;    // return ans
}

int main() {
    vector<vector<int>> grid = {{1, 1, 0, 0, 0},
                                {1, 1, 0, 0, 0},
                                {0, 0, 0, 1, 1},
                                {0, 0, 0, 1, 1}};
    cout << maxAreaOfIsland(grid);
    return 0;
}