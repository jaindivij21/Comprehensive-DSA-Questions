 // Dynamic Programming
// Cell Mitosis
// https://hack.codingblocks.com/app/contests/1310/546/problem

/*
 *  Minimization optimization problem since we have to minimize the cost associated with the building of cells. Therefore DP can be used.
 *  We need to recursively look at all the 3 options - doubling, +1, -1 and thus the normal TC: O(3^n). However it can be reduced using DP.
 *
 *  We can use memorization in Recursion but there is a slight CATCH in the problem thus it wouldn't reduce time complexity whole lot. Therefore its better to use bottom
 *  up approach. The catch here is that for us to compute a number, we need values more than it also i.e. i+1 which isn't common in DP.
 *
 *  Therefore we use a special approach by dividing the numbers into odd and even.
 */

#include<bits/stdc++.h>

using namespace std;

// dp table
int memo[10000];

// memorization solution
//int memorization(int curr, int n, int x, int y, int z) {
//    // base cases
//    if (curr > n || curr < 1)
//        return INT_MAX - x - y - z;
//    if (curr == n)
//        return 0;
//    if (memo[curr] != -1)
//        return memo[curr];
//
//    // recursive cases :: 3 cases
//    int q1 = x + memorization(curr * 2, n, x, y, z);
//    int q2 = y + memorization(curr + 1, n, x, y, z);
//    int q3 = z + memorization(curr - 1, n, x, y, z);
//
//    memo[curr] = min(q1, max(q2, q3));
//    return memo[curr];
//}

// pure dp bottom up solution to cal the min cost
/*
 *  This is an interesting DP problem since if we do this using normal recursion we get stuck in infinite recursion, due to the fact that our value is dependent on values
 *  both smaller and greater than it. Trick to solve this problem is to divide it into odd and even numbers. For even we reach by *2 or +1 and for odd we reach the number
 *  by +1 or *2-1
 */
int dpSol(int n, int x, int y, int z) {
    // bottom up approach
    int *dp = new int[n + 1];
    dp[0] = 0;
    dp[1] = 0;
    for (int i = 2; i <= n; i++) {
        if (i % 2 == 0) {
            // if the number is even
            dp[i] = min(dp[i / 2] + x, dp[i - 1] + y);
        } else {
            // if the number is odd
            dp[i] = min(dp[i - 1] + y, dp[(i + 1) / 2] + x + z);
        }
    }
    return dp[n];
}

int main() {
    int n;
    int x, y, z;
    cin >> n >> x >> y >> z;

//    memset(memo, -1, sizeof(memo));
//    int res1 = memorization(1, n, x, y, z);
//    cout << "The min cost to make 1 cell into n cells will be " << res1 << endl;

    int res2 = dpSol(n, x, y, z);
    cout << "The min cost to make 1 cell into n cells will be " << res2 << endl;

    return 0;
}