// Sudoku Problem
// Backtracking

#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

// function to check if a number can be placed at a specific position
bool canPlace(vector<vector<int>> &grid, int i, int j, int num, int size) {
    // check for that row and column
    for (int k = 0; k < size; k++) {
        if (grid[k][j] == num || grid[i][k] == num)
            return false;
    }
    // check for the subgrid
    int sqrtRoot = sqrt(size);
    int sX = (i / sqrtRoot) * sqrtRoot;
    int sY = (j / sqrtRoot) * sqrtRoot;
    // scan through the subgrid
    for (int k = sX; k < sX + sqrtRoot; k++) {
        for (int l = sY; l < sY + sqrtRoot; l++) {
            if (grid[k][l] == num)
                return false;
        }
    }
    return true;
}


// backtracking function - returns if can be solved or not
// transversal is row wise
bool sudokuSolver(vector<vector<int>> &grid, int i, int j, int size) {
    // base case
    if (i == size) {
        // means crossed the last row (henced solved the entire sudoku)
        // print the sudoku
        for (int k = 0; k < size; k++) {
            for (int l = 0; l < size; l++) {
                cout << grid[k][l] << " ";
            }
            cout << endl;
        }
        return true;
    }
    // if row ends - move to the next row
    if (j == size) {
        return sudokuSolver(grid, i + 1, 0, size);
    }
    // skip the prefilled cells
    if (grid[i][j] != 0) {
        return sudokuSolver(grid, i, j + 1, size);
    }

    // Recursive Case
    // Fill the current cell with possible options
    for (int num = 1; num <= size; num++) {
        if (canPlace(grid, i, j, num, size)) {
            // assuming correct number
            // therefore place the number
            grid[i][j] = num;

            // check if after placing the num, recursively call the function on the remaining grid
            // check if it returns true or false(in which case you'll need to backtrack)
            bool couldWeSolve = sudokuSolver(grid, i, j + 1, size);
            if (couldWeSolve)
                return true;
        }
    }
    // Backtracing Steps
    // if the cell isn't being filled by any number from 0-9, means something is wrong in the cells before
    grid[i][j] = 0;
    return false;
}

int main() {
    // size of matrix
    int size;
    cout << "Enter the size of Sudoku - n (nxn)" << endl;
    cin >> size;

    // enter the sudoku grid
    vector<vector<int>> sudokuGrid(size, vector<int>(size));
    cout << "Enter the Sudoku Grid" << endl;

    int temp;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cin >> temp;
            sudokuGrid[i][j] = temp;
        }
    }
    cout << endl;

    // call the sudoku function
    sudokuSolver(sudokuGrid, 0, 0, size);

    return 0;
}