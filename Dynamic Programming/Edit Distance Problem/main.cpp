// Edit Distance Problem
// Dynamic Programming
// https://afteracademy.com/blog/edit-distance-problem#:~:text=Solution%20steps&text=if%20the%20first%20character%20of,minimum%20of%20these%20three%20operations.

/*
 *  Example: Convert Sunday to Saturday
 *  There will be a total of 3 operations. Which include, 1 replacement and 2 insertions.
 *
 *  Normal recursive solution will have the time complexity of 3^n, however the pure dynamic solution :: bottom up can improve the TC: O(n^2)
 *  Make a 2d array where each state represents minimum number of operations reqd to convert input[0,i] to output[0,j] where input and output are strings.
 *      For each placeholder in the 2d array, we can make 3 operations in total, replacement, insertion and deletion. So we can consider all these 3 operations and build
 *  our solution bottom up. Initially we'll have the 1st row, 1st column filled which represent set of insertions and set of deletions respectively.
 */

#include<bits/stdc++.h>

using namespace std;

// global variable to count and thus compare the number of operations in just recursive and dynamic solution.
int operations = 0;

int justRecSoln(string input, string output, int i, int j) {
    // base case
    int len1 = input.length();
    int len2 = output.length();
    // means if any of the strings get over, return the left number of insertions required
    if (i == len1) {
        return len2 - j;
    }
    if (j == len2) {
        return len1 - i;
    }

    // if we get same chars
    if (input[i] == output[j]) {
        // return 0 + recursively call the next elements
        return justRecSoln(input, output, i + 1, j + 1);
    }

    // recursive cases :: there are 3 possible operations (all the operations are performed in the input string)
    // replacement :: move forward in both strings
    int op1 = 1 + justRecSoln(input, output, i + 1, j + 1);
    // insertion :: move forward only the output strings
    int op2 = 1 + justRecSoln(input, output, i, j + 1);
    // deletion :: move forward only in the input string
    int op3 = 1 + justRecSoln(input, output, i + 1, j);

    operations++;
    return min(op1, min(op2, op3));
}

int editDist(string input, string output, int dp[101][101]) {
    // fill the 1st col and row of the dp table
    int len1 = input.length();
    int len2 = output.length();

    dp[0][0] = 0;
    for (int i = 1; i < len1 + 1; i++) {
        dp[0][i] = dp[0][i - 1] + 1;
    }
    for (int j = 1; j < len2 + 1; j++) {
        dp[j][0] = dp[j - 1][0] + 1;
    }

    // now start filling the other boxes
    for (int i = 1; i < len1 + 1; i++) {
        for (int j = 1; j < len2 + 1; j++) {
            // replacement
            int q1 = dp[i - 1][j - 1];
            // insertion
            int q2 = dp[i][j - 1];
            // deletion
            int q3 = dp[i - 1][j];

            // cal the min out of the three and put in dp[i][j]. Also add 1 to the operation but only if the letters in input and output are different
            int x = (input[i - 1] != output[j - 1]) ? 1 : 0;
            operations++;
            dp[i][j] = min(q1, min(q2, q3)) + x;
        }
    }
    return dp[len1][len2];
}

int main() {
    string a;
    string b;
    cout << "Enter the input and the output string" << endl;
    cin >> a >> b;

    int ans1 = justRecSoln(a, b, 0, 0);
    cout << "Recursive Solution" << endl;
    cout << "The least possible number of operations required are: " << ans1 << endl;
    cout << "The number of operations taken to get the answer using just recursion: " << operations << endl;

    operations = 0;

    int arr[101][101];
    int ans2 = editDist(a, b, arr);
    cout << "Dynamic Solution" << endl;
    cout << "The least possible number of operations required are: " << ans2 << endl;
    cout << "The number of operations taken to get the answer using dynamic method: " << operations << endl;

    return 0;
}