// Ladders Problem using recusion
// No of ways to reach the nth stair if he can jump either either 0,1,2....m stairs at a time
//  https://www.youtube.com/watch?v=5o-kdjv7FD0

// uses recursion

#include <bits/stdc++.h>

using namespace std;

// main function
int count(int s, int m) {
    // base case
    if (s == 0)
       {
           // if only one stair, then one way to climb it
           return 1;
       } 
    // else use recursion
    int total = 0;
    // for all the ways the person can jump the stairs, add to the total 
    for (int i = 1; i <= m; i++) {
        if (s - i >= 0) {   // this condition is to make sure s-i doesnt get -ve
            total += count(s - i, m);
        }
    }
    return total;
}

// Driver code
int main() {
    int s, m;
    cout << "Stairs?" << endl;
    cin >> s;
    cout << "No. of steps that can be taken at a time (max)" << endl;
    cin >> m;
    cout << "Number of ways = " << count(s, m);

    return 0;
}


/*  CONCEPT: It uses the same recursion tree as fibonacci
 *  Ex: s = 4, m = 2 (0,1)
 *  0 stairs = 0 ways
 *  1 stairs = 1 way
 *  2 stairs = 2 ways
 *  3 stairs = 3 ways
 *  4 stairs = 5 ways  ---> check video to be sure how are we getting these ways (9:30)
 *  
 *  therfore,
 *  for 4 stairs = ways(3 stairs) + ways(2 stairs)
 * 
 */
