// Leetcode: 01 Matrix
// https://leetcode.com/problems/01-matrix/
// https://www.youtube.com/watch?v=edXdVwkYHF8&ab_channel=takeUforward

#include<iostream>
#include <vector>
#include<queue>

using namespace std;

// Helper method to determine if an index is within bounds and unvisited
bool isValidIndex(vector<vector<int>> &visited, int row, int col, int numOfRows, int numOfCols) {
    if (row >= 0 && row < numOfRows && col >= 0 && col < numOfCols && visited[row][col] == 0)
        return true; // Index is valid and unvisited
    else
        return false; // Index is out of bounds or already visited
}

// Function to update the matrix with distances to nearest 0s
vector<vector<int>> updateMatrix(vector<vector<int>> &mat) {
    int rows = mat.size();
    int cols = mat[0].size();

    // Create a matrix to store distances to nearest 0s
    vector<vector<int>> distance(rows, vector<int>(cols, 0));
    // Create a matrix to track visited indices
    vector<vector<int>> visited(rows, vector<int>(cols, 0));

    // Initialize a queue for BFS traversal, containing pairs of indices and distances
    queue<pair<pair<int, int>, int>> q;

    // Enqueue all 0 indices into the queue and mark them as visited
    // The crux is to apply Multi source BFS from all the 0's and move one step at a time in each direction.
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (mat[i][j] == 0) {
                q.push({{i, j}, 0}); // Enqueue index and distance
                visited[i][j] = 1;   // Mark index as visited
            }
        }
    }

    // Define offset arrays for 4 possible directions: up, right, down, left
    vector<int> rowOffset = {0, 1, 0, -1};
    vector<int> colOffset = {-1, 0, 1, 0};

    // Perform BFS traversal
    while (!q.empty()) {
        int currentRow = q.front().first.first;
        int currentCol = q.front().first.second;
        int steps = q.front().second;

        q.pop(); // Dequeue the current index

        distance[currentRow][currentCol] = steps; // Update distance matrix

        // Explore neighbors in all 4 directions
        for (int i = 0; i < 4; i++) {
            int newRow = currentRow + rowOffset[i];
            int newCol = currentCol + colOffset[i];

            // Check if the new index is valid and unvisited
            if (isValidIndex(visited, newRow, newCol, rows, cols)) {
                visited[newRow][newCol] = 1; // Mark new index as visited
                q.push({{newRow, newCol}, steps + 1}); // Enqueue new index with updated distance
            }
        }
    }

    // Return the matrix with distances to nearest 0s
    return distance;
}

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<int>> mat(m, vector<int>(n));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }

    vector<vector<int>> ans = updateMatrix(mat);

    return 0;
}