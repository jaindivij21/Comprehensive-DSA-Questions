// Dynamic Programming
// Fibonacci Numbers

// TC: 2^n without using DP
// TC: O(N) with DP i.e. Memorization

#include<bits/stdc++.h>

using namespace std;

// fibonacci fx
int fib(int n, int arr[]) {
    // if already discovered, just return the array value
    if (arr[n] != -1) {
        return arr[n];
    } else {
        // else calculate the ans recursively but remember to store the ans in the array for further evaluation
        int ans = fib(n-1, arr)+fib(n-2, arr);
        arr[n] = ans;
        // return the ans
        return arr[n];
    }
}

int main() {
    cout << "Enter the index of fibonacci series required" << endl;
    int n;
    cin >> n;

    // make a memorization array
    int *arr = new int[n];
    // mark the array as empty
    for (int i = 0; i <= n; i++) {
        arr[i] = -1;
    }
    // initial values
    arr[0] = 0;
    arr[1] = 1;

    // ans
    int ans = fib(n, arr);

    cout << n << "th fibonacci number is " << ans;

    return 0;
}