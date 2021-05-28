// Subset Sum Problem
// Dynamic Programming :: Print out the subsets who add up to a given number k
// Will use a bottom up approach :: i.e. make a 2d array for the same!
// https://www.youtube.com/watch?v=tRpkluGqINc&ab_channel=PepcodingPepcoding

/*
 *  The rows depict the array of numbers and columns depict the integers from
 *  Here each box in the dp table would represent the
 */

#include<bits/stdc++.h>

// define a pair that stores a string i.e. path so far, and another pair that stores i and j
#define pp pair<string, pair<int,int>>

using namespace std;


// main function
void subsetSum(int arr[], int n, int k) {
    int rows = n + 1;
    int col = k + 1;
    bool dp[rows][col];   // see video, we keep the first row empty and the number of columns equals to k+1

    // loop to make the dp table
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < col; j++) {
            if (j == 0)
                // first column
                dp[i][j] = true;   // true :: cuz any subset no matter what can def make a target sum of 0 because it would contain 'phi' in it.
            else if (i == 0)
                // first row :: except for the first index all will be false, but that case has already been covered in above if statement.
                dp[i][j] = false;   // false :: cuz an empty (phi) subset can make no target sum except 0
            else {
                // if the rest of the team can make it, then its already true
                if (dp[i - 1][j] == 1) {
                    dp[i][j] = true;
                } else if (j >= arr[i - 1]) {
                    // now if the rest of the team cannot make the desired target, we need to include the row's index
                    // before that we check if the column is big enough to be added
                    if (dp[i - 1][j - arr[i - 1]])
                        // if the above row numbers can add up to make a target after subtracting the current row element
                        dp[i][j] = true;
                    else
                        dp[i][j] = false;
                } else {
                    dp[i][j] = false;
                }
            }
        }
    }

    // after we have made the DP Table, print true or false if final target sum can be formed by any subset from the array
    if (dp[rows][col])
        cout << "Yes, there exists this array's subset that sums upto the given target" << endl;
    else
        cout << "No, there doesn't exist this array's subset that sums upto the given target" << endl;

    // reverse engineer through recursion to print the subsets :: will use something like BFS
    queue<pp> q;
    q.push(make_pair("", make_pair(n, k)));
    while (!q.empty()) {
        // extract the front element from queue
        pp temp = q.front();
        q.pop();

        // current row and col index of dp table
        int r = temp.second.first;
        int c = temp.second.second;


        // if we reach the first row/column means we can print the answer
        if (r == 0 || c == 0) {
            cout << "Path " << temp.first << endl;
        } else {
            // from this node we will make 2 calls, one considering including and other excluding the current element

            // cal the including the curr element
            if (c >= arr[r - 1]) {
                // only if the current column is bigger than the row's array index can we include it
                bool include = dp[r - 1][c - arr[r - 1]];   // if this row's array element is included
                if (include) {
                    // if include is true :: i.e. after including the current element, the remaining target sum can be made :: add it to queue for further exploration
                    string str = to_string(r - 1) + " ";
                    q.push(make_pair(str.append(temp.first), make_pair(r - 1, c - arr[r - 1])));
                }
            }

            // cal the excluding the current element
            bool exclude = dp[r - 1][c];   // if this row's array element is excluded
            if (exclude) {
                // if exclude is true :: i.e even after excluding the target sum can be made :: add it to the queue to explore further
                q.push(make_pair(temp.first, make_pair(r - 1, c)));
            }
        }
    }
}

int main() {
    // input information
    cout << "Enter the number of elements in the array" << endl;
    int n;
    cin >> n;
    cout << "Enter the array elements" << endl;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << "Enter the target sum" << endl;
    int k;
    cin >> k;

    subsetSum(arr, n, k);

    return 0;
}