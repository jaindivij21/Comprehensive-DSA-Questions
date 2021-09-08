// Leetcode : Minesweeper
// https://leetcode.com/problems/minesweeper/

// Time Complexity -> O()

#include<bits/stdc++.h>

using namespace std;

// check all the 8 directions for the mines
int mines(vector<vector<char>> &board, int i, int j, const int x[], const int y[]) {
    int ans = 0;
    for (int k = 0; k < 8; k++) {
        // for all the neighboring 8 squares
        int m = i + x[k];
        int n = j + y[k];
        if (m >= 0 && m < board.size() && n >= 0 && n <= board[0].size()) {
            // check if they lie inside of board borders
            if (board[m][n] == 'M')
                ans++;
        }
    }
    return ans;
}

// dfs fx
void dfs(vector<vector<char>> &board, int i, int j, const int x[], const int y[]) {
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
            if (m >= 0 && m < board.size() && n >= 0 && n <= board[0].size() &&
                (board[m][n] == 'M' || board[m][n] == 'E')) {
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
    vector<vector<char>> board = {{'B', '1', 'E', '1', 'B'},
                                  {'B', '1', 'M', '1', 'B'},
                                  {'B', '1', '1', '1', 'B'},
                                  {'B', 'B', 'B', 'B', 'B'}};
    vector<int> click = {1, 2};
    updateBoard(board, click);

    for (auto i: board) {
        for (auto j: i) {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}