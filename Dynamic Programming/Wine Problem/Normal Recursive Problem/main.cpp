// 2-D Dynamic Programming
// Wine Problem : https://www.geeksforgeeks.org/maximum-profit-sale-wines/
// Looks greedy but not a greedy problem
// Using DP we'll reduce the time complexity from exponential to Time Complexity: O(n2), i.e. we'll avoid travelling through the entire recursion tree.

#include<bits/stdc++.h>

using namespace std;

// function that calculates the max profit :: recusrive
int maxProfit(int arr[], int begin, int end, int year) {
    // base case
    if (begin > end)
        return 0;

    // recursive case
    // sell from beginning
    int q1 = year * arr[begin] + maxProfit(arr, begin + 1, end, year + 1);
    // sell from end
    int q2 = year * arr[end] + maxProfit(arr, begin, end - 1, year + 1);

    return max(q1, q2);
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

    cout << "Max profit is:" << maxProfit(arr, 0, n - 1, 1) << endl;

    return 0;
}