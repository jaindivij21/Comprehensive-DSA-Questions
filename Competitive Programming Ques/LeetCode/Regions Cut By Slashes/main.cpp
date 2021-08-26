// Leetcode : Regions Cut By Slashes
// https://leetcode.com/problems/regions-cut-by-slashes/
// https://www.youtube.com/watch?v=aY5eXeJICss&t=1154s&ab_channel=Errichto
// https://leetcode.com/problems/regions-cut-by-slashes/discuss/205680/JavaC%2B%2BPython-Split-4-parts-and-Union-Find

// This problem can be solved by dividing each 1x1 square into 4 different regions which can be separated by diagonals (2 are possible).

#include<bits/stdc++.h>

using namespace std;

// boundary check function
bool inside(int row, int col, const vector<string> &grid) {
    if (row >= 0 && row < grid.size() && col >= 0 && col < grid[0].size())
        return true;
    else
        return false;
}

// main dfs function that marks all the connected nodes as visited using dfs traversal
void dfs(const vector<string> &grid, vector<vector<vector<bool>>> &visited, int row, int col, int type) {
    // base case
    if (!inside(row, col, grid) || visited[row][col][type]) {
        return; // return for all the cases first only if the calls are out of boundary or the node has been already visited
    }

    // make the current node as visited
    visited[row][col][type] = true;

    // recursive case : dfs calls
    // intersquare traversals
    if (type == 0) {
        dfs(grid, visited, row - 1, col, 2);  // visit top
    } else if (type == 1) {
        dfs(grid, visited, row, col + 1, 3);  // visit right
    } else if (type == 2) {
        dfs(grid, visited, row + 1, col, 0);  // visit bottom
    } else if (type == 3) {
        dfs(grid, visited, row, col - 1, 1);  // visit left
    } else
        assert(false);
    // same square traversal :: very difficult and interesting
    if (grid[row][col] != '/') {
        // not equal to forward slash :: means can be a backward slash or no slash ->
        dfs(grid, visited, row, col, type ^ 1);
    }
    if (grid[row][col] != '\\') {
        // not equal to forward slash :: means can be a backward slash or no slash ->
        dfs(grid, visited, row, col, type ^ 3);
    }

}

// main function that calculates the regions cut by slashes
int regionsBySlashes(vector<string> &grid) {
    // visited 3 dimensional vector :: keeps track if each node (Here node refers to each region inside 1x1 square) has been visited or not. Resize the visited array also!
    vector<vector<vector<bool>>> visited;
    visited.resize(grid.size(), vector<vector<bool>>(grid[0].size(), vector<bool>(4)));

    // ans :: the total number of regions in the figure after drawing the diagnols
    int count = 0;

    for (int i = 0; i < grid.size(); i++) {
        // for every row
        for (int j = 0; j < grid[0].size(); j++) {
            // for every col
            // we divide each 1x1 square into 4 equal nodes/triangles or essentially 'types'
            for (int k = 0; k < 4; k++) {
                // for each type
                if (!visited[i][j][k]) {
                    // if the node is unvisited, then call dfs on that node and mark all its connected nodes as visited as well since they are a part of the same region
                    dfs(grid, visited, i, j, k);
                    count++;
                }
            }
        }
    }
    return count;
}

int main() {
    vector<string> grid = { " /", "/ " };

    cout << regionsBySlashes(grid);

    return 0;
}