// Regular Expression Matching :: Leetcode
// https://leetcode.com/problems/regular-expression-matching/

// Dynamic Programming
// Memorization : https://www.youtube.com/watch?v=HAA8mgxlov8
// Bottom Up : https://www.youtube.com/watch?v=DJvw8jCmxUU

#include<bits/stdc++.h>

using namespace std;

// recursive
int helper(const string &s, const string &p, int i, int j, map<pair<int, int>, int> memo) {
    // base cases
    // memorization
    if (memo.find(make_pair(i, j)) != memo.end())
        return memo.at(make_pair(i, j));
    if (i >= s.length() and j >= p.length())
        return 1;    // if both are out of bounds : they have matched
    if (j >= p.length())
        return 0;   // if only the pattern and not the string is out of bounds : impossible to match

    // recursive cases
    int match = (i < s.length()) and (s[i] == p[j] or p[j] == '.') ? 1 : 0;    // check if there is a match

    // if there is a match and successor is a *
    if (j + 1 < p.length() and p[j + 1] == '*') {
        // either dont consider the * or consider the *
        if (helper(s, p, i, j + 2, memo) || (helper(s, p, i + 1, j, memo) && match)) {
            memo[{i,j}] = 1;
        } else {
            memo[{i,j}] = 0;
        }
        return memo[{i,j}];
    }

    // if only match and no * as successor
    if (match) {
        memo[{i,j}] = helper(s, p, i + 1, j + 1, memo);
        return memo[{i,j}];
    }

    // else return false
    memo[{i,j}] = false;
    return false;
}

// Top-Down DP
bool isMatch(string s, string p) {
    map<pair<int, int>, int> memo;
    int ans = helper(s, p, 0, 0, memo);
    return ans;
}

int main() {
    string str;
    cin >> str;
    string pattern;
    cin >> pattern;

    int ans = isMatch(str, pattern);
    ans ? cout << "true" : cout << "false";

    return 0;
}