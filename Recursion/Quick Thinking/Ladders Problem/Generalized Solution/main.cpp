// Ladders Problem using recusion
// No of ways to reach the nth stair if he can jump either 1,2 or 3 stairs at a time
// https://www.geeksforgeeks.org/count-ways-reach-nth-stair/
// https://www.youtube.com/watch?v=fiPLaxkhdcQ
// https://www.youtube.com/watch?v=5o-kdjv7FD0 (best)

// Based on Fibonaaci Series Concept

#include <bits/stdc++.h>

using namespace std;

// A recursive function used by countWays
int countWaysUtil(int n, int m) {
    if (n <= 1) {
        // if the stairs are 0, then you dont have to climb anything, hence 1 way
        // if you have 1 stair, then also just one way to climb it
        return n;
    }

    int res = 0;
    for (int i = 1; i <= m && i <= n; i++) {
        res += countWaysUtil(n - i, m);
    }
    return res;
}

// Returns number of ways to reach s'th stair
int countWays(int s, int m) {
    return countWaysUtil(s + 1, m);
}

// Driver code
int main() {
    int s, m;
    cout << "Stairs?" << endl;
    cin >> s;
    cout << "No. of steps that can be taken at a time (max)" << endl;
    cin >> m;
    cout << "Number of ways = " << countWays(s, m);

    return 0;
}

