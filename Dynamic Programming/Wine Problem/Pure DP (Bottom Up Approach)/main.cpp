// 2-D Dynamic Programming :: Bottom Up Approach
// Wine Problem : https://www.geeksforgeeks.org/maximum-profit-sale-wines/

// Using DP we'll reduce the time complexity from exponential (2^n) to Time Complexity: O(n2), i.e. we'll avoid travelling through the entire recursion tree.

/*
 *  IMPORTANT CONCEPT FOR 2D PURE DP
 *
 *  Here in pure DP we dont memorize the recursive tree results, rather start calculating things bottom up. I.e for example in this question, if we have 5 bottle ques,
 *  we start with calculating the max profit if only 1 bottle was present on the table i.e. in the last (5th) year for all bottles. Based on that we calculate the profits for 4th
 *  year where we have pair of bottles and so on.
 */

#include<bits/stdc++.h>

using namespace std;

// function that calculates the max profit :: uses DP - 2D Table (Bottom Up Approach)
// parameters: the array of bottles and number of bottles
int maxProfit(int arr[], int n) {
    int dp[100][100] = {};
    int year = n;   // make year the last year i.e. for n = 5 (5 bottles or 5 years)

    // considering there are total 5 bottles or 5 years

    // only one bottle on the table :: year 5
    for (int i = 0; i < n; i++) {
        dp[i][i] = year * arr[i];
    }
    year--;

    // all the other years
    // here len refers to the window size in each year :: so for example in year 4: there will be 2 bottles therefore we start with len = 2
    // max value of len is eql to 5 i.e. the max bottles on the table
    for (int len = 2; len <= n; ++len) {
        // get the start and end indexes wrt to current length
        int srt = 0;
        int end = n - len;
        // surf through all the windows or possible bottles for this length
        while (srt <= end) {
            int currWindowEnd = srt + len - 1;  // stores the end of current window

            // update the table
            dp[srt][currWindowEnd] = max(
                    year * arr[currWindowEnd] + dp[srt][currWindowEnd - 1],
                    year * arr[srt] + dp[srt + 1][currWindowEnd]
            );

            ++srt;  // go to the next window
        }
        --year; // decrement year i.e. add a bottle :: ex. now calculate max profit for 3 bottles based on result of pair of bottles
    }

    // printing the DP table to understand the problem
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << setw(3) << dp[i][j] << " ";
        }
        cout << endl;
    }

    // returning the ans
    return dp[0][n - 1];
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

    cout << "Max profit is:" << maxProfit(arr, n) << endl;


    return 0;
}