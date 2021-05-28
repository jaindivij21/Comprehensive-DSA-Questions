 // Dynamic Programming :: Minimum Steps to reduce to 1
// https://www.geeksforgeeks.org/minimum-steps-minimize-n-per-given-condition/
// TC: Without using the DP : 3^n --> but using top down approach reduces the TC to O(n)

#include<bits/stdc++.h>

using namespace std;

// recursive function to reduce a number based on the given 3 rules
// we always check all the three conditions, thus the recursion tree will have 3 outgoing edges from each node
// Then we will choose the one with minimum number of steps
int reduce(int num) {
    int *dpTable = new int[10000];

    // initial values
    dpTable[0] = 0;
    dpTable[1] = 0;
    dpTable[2] = 1;
    dpTable[3] = 1;

    // compute ans for the n
    for (int currNum = 4; currNum <= num; currNum++) {
        int op1 = INT_MAX;
        int op2 = INT_MAX;
        int op3 = INT_MAX;

        if (currNum % 3 == 0) {
            op1 = 1 + dpTable[currNum / 3];
        }
        if (currNum % 2 == 0) {
            op2 = 1 + dpTable[currNum / 2];
        }
        op3 = 1 + dpTable[currNum - 1];

        dpTable[currNum] = min(op1, min(op2, op3));
    }
    return dpTable[num];
  }

int main() {
    cout << "Enter the number to be reduced" << endl;
    int n;
    cin >> n;

    cout << reduce(n) << endl;

    return 0;
}