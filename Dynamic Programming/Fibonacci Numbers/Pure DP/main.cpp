// Dynamic Programming :: Pure DP (Bottom Up)
// Fibonacci Series

#include <bits/stdc++.h>

using namespace std;

// fibonacci function
int fib(int n) {
    // max number that can be computed is 0-999
    int dpTable[1000] = {};

    // intial table
    dpTable[0] = 0;
    dpTable[1] = 1;

    // loop that cal fibo series in bottom up approach up til the nth number
    for (int currNum = 2; currNum <= n; currNum++) {
        dpTable[currNum] = dpTable[currNum - 1] + dpTable[currNum - 2];
    }
    // return the ans
    return dpTable[n];
}


int main() {
    cout << "Enter the index of the fibonacci series" << endl;
    int n;
    cin >> n;

    int ans = fib(n);

    cout << n << "th fibonacci number is " << ans << endl;
    return 0;
}