// Leetcode : Minesweeper
// https://leetcode.com/problems/minesweeper/

// Time Complexity -> O(8*m*n) ==> O(m*n)
// Note that: if you don't pass parameters as pointers or by reference you'll get heap buffer runtime error!

#include<bits/stdc++.h>

using namespace std;

// check for border conditions
bool isValid(vector<vector<char>> &board, int i, int j) {
    return (i >= 0 && j >= 0 && i < board.size() && j < board[0].size());
}

// check all the 8 directions for the mines
int mines(vector<vector<char>> board, int i, int j, const int *x, const int *y) {
    int ans = 0;
    for (int k = 0; k < 8; k++) {
        // for all the neighboring 8 squares
        int m = i + x[k];
        int n = j + y[k];
        if (isValid(board, m, n)) {
            // check if they lie inside of board borders
            if (board[m][n] == 'M')
                ans++;
        }
    }
    return ans;
}

// dfs fx
void dfs(vector<vector<char>> &board, int i, int j, const int *x, const int *y) {
    // base case

    if (board[i][j] != 'M' && board[i][j] != 'E')
        // if the index is visited
        return;

    if (board[i][j] == 'M') {
        // if we click on mine
        board[i][j] = 'X';
        return;
    }
    // cal the number of mines around the current box and acc set the new board value i.e. either B or a number
    int noOfSurrMines = mines(board, i, j, x, y);
    if (noOfSurrMines == 0)
        board[i][j] = 'B';
    else
        board[i][j] = '0' + noOfSurrMines;

    // recursive cases

    // make a recursive call if after updation the current index is a revealed blank square
    if (board[i][j] == 'B') {
        // make a recursive call to all the 8 directions if they aren't already visited or in the boundary
        for (int k = 0; k < 8; k++) {
            int m = i + x[k];
            int n = j + y[k];
            if (isValid(board, m, n) && (board[m][n] == 'M' || board[m][n] == 'E')) {
                dfs(board, m, n, x, y);
            }
        }
    }
}

// main
vector<vector<char>> updateBoard(vector<vector<char>> &board, vector<int> &click) {
    // make a visited array
    // global : displacement vectors
    int x[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int y[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    dfs(board, click[0], click[1], x, y);
    return board;
}

int main() {
    vector<vector<char>> board = {{'E', 'E', 'E', 'E', 'E', 'E', 'E', 'E'},
                                  {'E', 'E', 'E', 'E', 'E', 'E', 'E', 'M'},
                                  {'E', 'E', 'M', 'E', 'E', 'E', 'E', 'E'},
                                  {'M', 'E', 'E', 'E', 'E', 'E', 'E', 'E'},
                                  {'E', 'E', 'E', 'E', 'E', 'E', 'E', 'E'},
                                  {'E', 'E', 'E', 'E', 'E', 'E', 'E', 'E'},
                                  {'E', 'E', 'E', 'E', 'E', 'E', 'E', 'E'},
                                  {'E', 'E', 'M', 'M', 'E', 'E', 'E', 'E'}};

    vector<int> click = {0, 0};
    updateBoard(board, click);

    for (auto i: board) {
        for (auto j: i) {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}