// Dynamic Programming :: Minimum Steps to reduce to 1
// https://www.geeksforgeeks.org/minimum-steps-minimize-n-per-given-condition/
// TC: O(3^n) without any DP and just recursion --> O(n) using memorization

// Using the memorization DP Technique since there is are overlapping sub problems
// apply recursion first then try to apply DP on it

#include<bits/stdc++.h>

using namespace std;

// recursive function to reduce a number based on the given 3 rules
// we always check all the three conditions, thus the recursion tree will have 3 outgoing edges from each node
// Then we will choose the one with minimum number of steps
int reduce(int num, int memo[]) {
    // base case
    if (num == 1)
        return 0;
    if (memo[num] != -1) {
        // means we have already calculated it
        return memo[num];
    }

    int option1 = INT_MAX, option2 = INT_MAX, option3 = INT_MAX;
    if (num % 3 == 0) {
        // if number divisible by 3, explore this side of the tree
        option1 = 1 + reduce(num / 3, memo);
    }
    if (num % 2 == 0) {
        // if number divisible by 2, explore this side
        option2 = 1 + reduce(num / 2, memo);
    }
    option3 = 1 + reduce(num - 1, memo);

    // memorize this once the value has been calculated
    memo[num] = min(option1, min(option2, option3));
    return memo[num];
}

int main() {
    cout << "Enter the number to be reduced" << endl;
    int n;
    cin >> n;

    // array: stores the number of steps taken to reduce a number from one stage to other
    int *memo = new int[n + 1];
    fill(memo, memo + n + 1, -1); 
    cout << reduce(n, memo) << endl;

    return 0;
}