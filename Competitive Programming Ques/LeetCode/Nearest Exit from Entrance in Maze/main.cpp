// Leetcode: Nearest Exit from Entrance in Maze
// https://leetcode.com/problems/nearest-exit-from-entrance-in-maze

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution
{
   public:
    // Possible directions to move: right, down, left, up
    vector<vector<int> > directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    // Breadth-First Search (BFS) to find the shortest path to an exit
    int nearestExit(vector<vector<char> > &maze, vector<int> &entrance)
    {
        const int m = maze.size();     // Number of rows
        const int n = maze[0].size();  // Number of columns
        vector<vector<bool> > visited(
            m, vector<bool>(n, false));  // Track visited positions

        queue<pair<int, int> > q;
        q.emplace(entrance[0], entrance[1]);  // Start BFS from the entrance
        visited[entrance[0]][entrance[1]] = true;

        int pathTravelled = 0;  // Tracks the distance from the entrance

        while (!q.empty())
        {
            int qSize = q.size();  // Number of nodes at the current BFS level

            for (int i = 0; i < qSize; i++)
            {
                auto [x, y] = q.front();
                q.pop();

                // If current position is an exit (and not the entrance), return
                // the path length
                if (isExit(maze, x, y) &&
                    (x != entrance[0] || y != entrance[1]))
                    return pathTravelled;

                // Explore all possible moves
                for (auto &direction : directions)
                {
                    int newX = x + direction[0];
                    int newY = y + direction[1];

                    // Check if the new position is valid and not visited
                    if (isValidPos(maze, newX, newY) && !visited[newX][newY] &&
                        maze[newX][newY] != '+')
                    {
                        visited[newX][newY] = true;
                        q.emplace(newX, newY);
                    }
                }
            }
            pathTravelled++;  // Increment path length after processing all
                              // nodes at this level
        }

        return -1;  // No valid exit found
    }

   private:
    // Function to check if a given position is an exit
    bool isExit(const vector<vector<char> > &maze, int i, int j)
    {
        int m = maze.size();
        int n = maze[0].size();

        return (i == 0 || i == m - 1 || j == 0 ||
                j == n - 1);  // Edge of the maze
    }

    // Function to check if a position is within maze boundaries
    bool isValidPos(const vector<vector<char> > &maze, int i, int j)
    {
        int m = maze.size();
        int n = maze[0].size();

        return (i >= 0 && i < m && j >= 0 && j < n);
    }
};

int main()
{
    vector<vector<char> > maze = {
        {'+', '+', '.', '+'}, {'.', '.', '.', '+'}, {'+', '+', '+', '.'}};
    vector<int> entrance = {1, 2};

    Solution sol;
    cout << sol.nearestExit(maze, entrance) << endl;

    return 0;
}
