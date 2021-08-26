// Leetcode : Number of Islands
// https://leetcode.com/problems/number-of-islands/
// https://dev.to/shoryu/number-of-islands-union-find-solution-4ph

// Union Find Solution :: Though gives a time limit exceeded.

#include<bits/stdc++.h>

using namespace std;

// find operation : returns the root element of the disjoint set
int findOp(int v, vector<int> parent) {
    if (parent[v] == v)
        return v;
    return findOp(parent[v], parent);
}

// union operation : merges two disjoint sets by setting up a link/edge bw them
void unionOp(int from, int to, vector<int> &parent, int &count) {
    // find the roots of both from and to nodes
    int fromRoot = findOp(from, parent);
    int toRoot = findOp(to, parent);

    if (fromRoot != toRoot) {
        parent[fromRoot] = toRoot;
        count--;
    }
}

// main function
int numIslands(vector<vector<char>> &grid) {
    // make a linear array equal to the total size of the matrix
    vector<int> parent(grid.size() * grid[0].size(), 0);
    // final ans :: number of islands
    int numberOfIslands = 0;

    // set the values of number of islands and the above vector
    // initially consider each 1 as a separate island i.e. a separate disjoint set i.e. a separate root with no children
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            // traverse over the entire grid
            if (grid[i][j] == '1') {
                numberOfIslands++;
                parent[i * grid[0].size() + j] = i * grid[0].size() + j;
            }
        }
    }

    // traverse over all the indexes of the grid and start union operation over adjoining 1's thus at the end we'll be left with only the number of actual islands
    // note that the union operation reduces the count
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            if (grid[i][j] == '1') {
                int dx[] = {0, 1};
                int dy[] = {1, 0};   // displacement arrays
                for (int k = 0; k < 2; k++) {   // since we only have to check in down are right direction
                    int m = i + dx[k];
                    int n = j + dy[k];  // new coordinates
                    if (m >= 0 && m < grid.size() && n >= 0 && n < grid[0].size() && grid[m][n] == '1') {
                        // if they are within the boundaries
                        unionOp(i * grid[0].size() + j, m * grid[0].size() + n, parent, numberOfIslands);
                    }
                }
            }
        }
    }
    return numberOfIslands;
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
