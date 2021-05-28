// 2-D Dynamic Programming :: Memorization
// Wine Problem : https://www.geeksforgeeks.org/maximum-profit-sale-wines/

// Looks greedy but not a greedy problem
// Using DP we'll reduce the time complexity from exponential (2^n) to Time Complexity: O(n2), i.e. we'll avoid travelling through the entire recursion tree.

/*
 *  IMPORTANT CONCEPT FOR 2D DP
 *
 *  To understand what we need to memorize is we need to understand the concept of state!! Here a state is a pair of a begin and end position.
 *
 *  We know in DP generally the number of states is equal to the time complexity, in this case the TC is O(n2) because we can have n2 states represented by the 2D array.
 *  The 2D array basically represents *begin X end* i.e. all the cases where we each index in array corresponds to one begin and end position eg. in 2 3 5 1 4;
 *  max Profit from 2 to 1 bottles will be stores in index 2,1.
 * 
 *  Also an important thing to note is half the 2D array will remain empty : cuz the condition begin < end must be enforced. for eg in the above example 
 *  the index (3,2) will remain unused.
 */

#include<bits/stdc++.h>

using namespace std;

// global variable to cal the difference bw use of dp and a simple recursive solution
int cnt = 0;

// function that calculates the max profit :: recusrive
int maxProfit(int arr[], int begin, int end, int year, int memo[][100]) {
    cnt++;
    // base case
    if (begin > end)
        return 0;
    // if found in the memo table
    if (memo[begin][end] != -1)
        return memo[begin][end];

    // recursive case
    // sell from beginning
    int q1 = year * arr[begin] + maxProfit(arr, begin + 1, end, year + 1, memo);
    // sell from end
    int q2 = year * arr[end] + maxProfit(arr, begin, end - 1, year + 1, memo);

    // store in the memo table
    memo[begin][end] = max(q1, q2);

    return memo[begin][end];
}

int main() {
    cout << "Enter the number of bottles" << endl;
    int n;
    cin >> n;
    int arr[n];

    cout << "Enter the bottles" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // memorization table
    int memo[100][100];
    // fill with -1
    memset(memo, -1, sizeof(memo));

    cout << "Max profit is:" << maxProfit(arr, 0, n - 1, 1, memo) << endl;
    cout << "The number of computations (count):" << cnt << endl;

    return 0;
}