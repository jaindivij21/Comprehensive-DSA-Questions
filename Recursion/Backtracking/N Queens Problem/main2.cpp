// N Queens Problem
// function is void

#include<iostream>

using namespace std;

int count = 0;

bool isSafe(int board[][10], int i, int j, int n) {
    // check if column has no other queen
    for (int row = 0; row < i; row++) {
        // if there is a queen
        if (board[row][j] == 1)
            return false;
    }
    int x = i;
    int y = j;
    // check for right diagnol
    while (x >= 0 && y < n) {
        if (board[x][y] == 1)
            return false;
        x--;
        y++;
    }
    x = i;
    y = j;
    // check for left diagnol
    while (x >= 0 && y >= 0) {
        if (board[x][y] == 1)
            return false;
        x--;
        y--;
    }
    return true;
}

// recursive funciton (i is iterator -- no of queens placed)
void solveNQueen(int board[][10], int i, int n) {
    // base case
    if (i == n) {
        // you have set all the n queens therefore print the board
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (board[j][k] == 1)
                    cout << "Q ";
                else
                    cout << "_ ";
            }
            cout << endl;
        }
        cout << endl;
        count++;
    }

    // recursive case
    // assume n-1 queens/rows will be placed on its own

    // hence try to place the queen in current row and recursively call for other rows
    // iterate over all the columns
    for (int j = 0; j < n; j++) {
        // check if current index is safe to place the queen
        if (isSafe(board, i, j, n)) {
            // if safe place the queen
            board[i][j] = 1;
            // ask recursively if we are able to print the next queen
            solveNQueen(board, i + 1, n);
            board[i][j] = 0;    // BACKTRACK
        }
    }
}

int main() {
    cout << "Enter the number of queens" << endl;
    int n;
    cin >> n;

    // try to take input from the user using vectors (2d arrays)
    // but for ease we'll just take a normal 2d array

    // board with all values as 0
    int board[10][10] = {0};

    // main function call
    solveNQueen(board, 0, n);
    cout << count << endl;
    return 0;
}