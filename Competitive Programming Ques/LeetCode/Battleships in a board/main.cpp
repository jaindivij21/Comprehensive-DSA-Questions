// Leetcode : Battleships in a Board
// https://leetcode.com/problems/battleships-in-a-board/

// can be solved using DFS on the array and marking the array indexes as visited so, as to not count the same X in 2 ships!

// Time Complexity: O(M*N) -> Traverse the entire graph

#include<bits/stdc++.h>

using namespace std;

void dfs(vector<vector<char>> &board, int visited[][201], int i, int j) {
    // i, j are the indexes of the first X we have encountered of a new ship
    visited[i][j] = 1;  // mark it visited
    // for all its 4 neighbors check if it's an X and unvisited then call dfs recursively on it
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};   // displacement arrays
    for (int k = 0; k < 4; k++) {
        // the coordinate
        int m = i + dx[k];
        int n = j + dy[k];
        if (m >= 0 && m < board.size() && n >= 0 && n < board[0].size() && board[m][n] == 'X' && !visited[m][n]) {
            dfs(board, visited, m, n);
        }
    }
}

// main function
int countBattleships(vector<vector<char>> &board) {
    int count = 0;  // final ans
    // make a visited array that determines if the index has been visited
    int visited[201][201];
    memset(visited, 0, sizeof(visited));
    // traverse to all the indexes
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            // if the index is X and unvisited means it's a new ship, dfs over that and increment count
            if (board[i][j] == 'X' && !visited[i][j]) {
                dfs(board, visited, i, j);
                count++;
            }
        }
    }
    return count;
}

int main() {
    vector<vector<char>> board = {{'X', '.', '.', 'X'},
                                  {'.', '.', '.', 'X'},
                                  {'.', '.', '.', 'X'}};
    countBattleships(board);
    return 0;
}