// Longest Substring Problem :: LeetCode
// https://leetcode.com/problems/longest-palindromic-substring/

// Dynamic Programming :: Bottom Up Approach

#include<bits/stdc++.h>

using namespace std;

string longestPalindrome(string s) {
    // dynamic approach
    bool dp[s.length()][s.length()];
    memset(dp, false, sizeof(dp));

    pair<int, int> max; // starting index and length of the substring

    // moving across all the diagonals
    for (int g = 0; g < s.length(); g++) {
        for (int i = 0, j = g; j < s.length(); i++, j++) {
            if (g == 0) {
                // all the values will be true since a substring of len 1 will always be a palindrome
                dp[i][j] = true;
                max = make_pair(i, 1);
            } else if (g == 1) {
                if (s[i] == s[j]) {
                    dp[i][j] = true;
                    max = make_pair(i, 2);
                } else
                    dp[i][j] = false;
            } else {
                if (s[i] == s[j] && dp[i + 1][j - 1]) {
                    dp[i][j] = true;
                    max = make_pair(i, j - i + 1);
                } else {
                    dp[i][j] = false;
                }
            }
        }
    }
    return s.substr(max.first, max.second);
}

int main() {
    string str;
    cin >> str;

    string ans = longestPalindrome(str);

    cout << ans << endl;

    return 0;
}