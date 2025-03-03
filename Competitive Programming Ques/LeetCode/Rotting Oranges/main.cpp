// Leetcode: Rotting Oranges
// https://leetcode.com/problems/rotting-oranges

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution
{
   public:
    // Directions for moving right, down, left, and up
    vector<vector<int> > directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    // Function to determine the minimum time required to rot all oranges
    int orangesRotting(vector<vector<int> > &grid)
    {
        // Grid dimensions
        int m = grid.size();
        int n = grid[0].size();

        // Matrix to track visited cells
        vector<vector<bool> > visited(m, vector<bool>(n, false));
        queue<pair<int, int> > q;
        int freshCount = 0;

        // Initialize the queue with all rotten oranges and mark them as visited
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 2)
                {
                    q.push({i, j});
                    visited[i][j] = true;  // Mark rotten oranges as visited
                }
                else if (grid[i][j] == 1)
                {
                    freshCount++;  // Count fresh oranges
                }
            }
        }

        // If no fresh oranges are present, return 0 (nothing to rot)
        if (freshCount == 0) return 0;

        // Time counter (starts from -1 because the first level is already
        // rotten)
        int minsPassed = -1;
        int rottenCount = 0;

        // BFS traversal to spread rotting effect
        while (!q.empty())
        {
            int qSize =
                q.size();  // Number of rotten oranges in the current level
            for (int i = 0; i < qSize; i++)
            {
                auto [x, y] = q.front();
                q.pop();

                // Check all four possible directions
                for (auto direction : directions)
                {
                    int newX = x + direction[0];
                    int newY = y + direction[1];

                    // Process only valid fresh oranges
                    if (isValid(grid, newX, newY) && !visited[newX][newY])
                    {
                        visited[newX][newY] = true;
                        rottenCount++;
                        q.emplace(newX, newY);
                    }
                }
            }
            minsPassed++;  // Increment time after each BFS level
        }

        return rottenCount == freshCount ? minsPassed : -1;
    }

   private:
    // Helper function to check if a position is valid and contains a fresh
    // orange
    bool isValid(vector<vector<int> > &grid, int i, int j)
    {
        int m = grid.size();
        int n = grid[0].size();
        return (i >= 0 && i < m && j >= 0 && j < n && grid[i][j] == 1);
    }
};

int main()
{
    vector<vector<int> > grid = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
    Solution s;

    cout << s.orangesRotting(grid) << endl;

    return 0;
}
