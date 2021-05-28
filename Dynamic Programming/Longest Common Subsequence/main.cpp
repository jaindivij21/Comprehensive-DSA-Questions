// Longest Common Subsequence
// Dynamic Programming

// Recursive Solution : TC O(2^n) but can be reduced using DP O(n^2)

/*
 *  State in the DP Solution:
 *      for (i,j) it represents the length of lcs bw str1[0,i] and str[0,j]
 *  NOTE: Whenever solving DP problems with strings always append the strings with a null character.
 */

#include<bits/stdc++.h>

using namespace std;

int recursiveSoln(char *str1, char *str2, int i, int j) {
    // base case
    if (i == strlen(str1) || j == strlen(str2)) {
        return 0;
    }
    if (str1[i] == str2[j])
        return 1 + recursiveSoln(str1, str2, i + 1, j + 1);
    // recursive cases
    int ans;
    int op1 = recursiveSoln(str1, str2, i + 1, j);
    int op2 = recursiveSoln(str1, str2, i, j + 1);
    ans = max(op1, op2);

    return ans;
}

int dpSoln(char *str1, char *str2) {
    // append the string with null char while using the dp table
    int size = max(strlen(str1), strlen(str2));
    int dp[size][size];
    int m = strlen(str1);
    int n = strlen(str2);

    // base cases i.e. first row and column :: cuz empty string doesn't have anything in common with anything else
    for (int i = 0; i <= m; i++) {
        dp[i][0] = 0;
    }
    for (int j = 0; j <= n; j++) {
        dp[0][j] = 0;
    }

    // now fill the entire dp table
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                // if the char of the string match, means add 1 to the the previous best match
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                // if the chars aren't same then just copy the max of what the longest seq uptil now
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[m][n];
}

int main() {
    char str1[100];
    char str2[100];

    cin >> str1 >> str2;

    int ans1 = recursiveSoln(str1, str2, 0, 0);
    cout << ans1 << endl;

    int ans2 = dpSoln(str1, str2);
    cout << ans2 << endl;

    return 0;
}