// Recursion in Maze (Rat in Maze)
// Use recursion BACKTRACKING
// https://www.geeksforgeeks.org/rat-in-a-maze-backtracking-2/

/*
 *  Given a MxN matrix some cells are blocked
 *  Find and print all the possible paths from src to destination
 *
 *  Take note that one can only move forward or down
 */

#include<iostream>
#include<vector>

using namespace std;

// main function
bool ratInMaze(vector<vector<char>> &maze, vector<vector<int>> &soln, int i, int j, int rowIndex, int colIndex) {
    // base case
    // if reaches the destination
    if (i == rowIndex && j == colIndex) {
        soln[i][j] = 1; // make the last element in soln array as 1

        // print the path from the soln matrix
        for (int x = 0; x <= rowIndex; x++) {
            for (int y = 0; y <= colIndex; y++) {
                cout << soln[x][y] << " ";
            }
            cout << endl;
        }
        cout<<endl;
        return true;
    }

    // corner cases
    // rat shouldn't go out of the maze
    if (i > colIndex || j > rowIndex) {
        return false;
    }
    // rat cannot travel on the wall
    if (maze[i][j] == 'X') {
        return false;
    }

    // recursive cases
    // once travelled make the index 1
    soln[i][j] = 1;
    // make the recursive cases in forward or downward direction
    bool rightSuccess = ratInMaze(maze, soln, i, j + 1, rowIndex, colIndex);
    bool downSuccess = ratInMaze(maze, soln, i + 1, j, rowIndex, colIndex);

    // BACKTRACKING STEPS (AFTER RECURSIVE CALLS)
    soln[i][j] = 0;

    // we even one path is possible return true
    if (rightSuccess || downSuccess) {
        return true;
    } else {
        return false;
    }

}

int main() {
    cout << "Enter the rows and columns of maze:" << endl;
    // input the rows of maze
    int rows;
    cin >> rows;
    // input the columns of maze
    int cols;
    cin >> cols;

    // input the maze 2D array, wall = X, empty = 0
    vector<vector<char>> maze(rows, vector<char>(cols));
    vector<vector<int>> soln(rows, vector<int>(cols));

    // set the entire soln matrix as 0
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            soln[i][j] = 0;
    }
    // input the maze
    cout << "Enter the input maze" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            cin >> maze[i][j];
    }

    // main function
    bool ans = ratInMaze(maze, soln, 0, 0, rows - 1, cols - 1);

    // if nothing is returned
    if (!ans)
        cout << "Path doesn't exist!" << endl;

    return 0;
}

