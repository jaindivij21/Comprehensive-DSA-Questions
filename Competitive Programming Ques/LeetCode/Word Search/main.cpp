// Word Search :: Leetcode
// https://leetcode.com/problems/word-search/

#include<bits/stdc++.h>

using namespace std;

// main dfs function
bool dfs(vector<vector<char>> &board, pair<int, int> src, string word) {
    int i = src.first;
    int j = src.second;

    // base case
    if (word.empty()) {
        return true;    // word found
    }
    if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size()) {
        // if dfs goes out of bounds, return false
        return false;
    }
    if (board[i][j] != word[0]) {
        return false;   // the word doesn't match the board index
    }

    // recursive cases (also since we are not using another visited array we need to solve the problems of duplications)
    char temp = board[i][j];   // store the current char
    board[i][j] = '*';     // mark the index as visited by replacing it with another character :: so if we return to this char, it returns false
    string s = word.substr(1);
    bool ret =
            dfs(board, {i - 1, j}, s) ||
            dfs(board, {i + 1, j}, s) ||
            dfs(board, {i, j - 1}, s) ||
            dfs(board, {i, j + 1}, s);
    board[i][j] = temp; // after we have checked for all the places for this index, we need to unmark it (backtracking)
    return ret;
}

// need to apply simple dfs algorithm to find if the word exists in the matrix or not
bool exist(vector<vector<char>> &board, string word) {
    // gather starting coordinates of the word
    set<pair<int, int>> positions;
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            if (word[0] == board[i][j])
                positions.insert(make_pair(i, j));
        }
    }

    // after getting the starting indexes, for all such indexes (loop) apply dfs to search for the word
    for (auto i:positions) {
        // apply dfs
        bool ans = dfs(board, i, word);
        if (ans)
            return true;
    }
    return false;
}

int main() {
    // input
    int m, n;
    cin >> m, n;

    vector<vector<char>> matrix;
    for (int i = 0; i < m; i++) {
        vector<char> temp;
        for (int j = 0; j < n; j++) {
            char x;
            cin >> x;
            temp.push_back(x);
        }
        matrix.push_back(temp);
    }

    string word;
    cin >> word;

    bool ans = exist(matrix, word);
    ans ? cout << "true" : cout << "false";

    return 0;
}