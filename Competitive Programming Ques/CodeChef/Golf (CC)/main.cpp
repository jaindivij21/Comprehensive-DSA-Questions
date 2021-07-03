// Golf  : CodeChef
// https://www.codechef.com/MAY21C/problems/LKDNGOLF

#include<bits/stdc++.h>

#define ll long long int
using namespace std;

bool solve() {
    ll n, index, jumps;
    cin >> n >> index >> jumps;

    ll tiles = n + 1;

// This method will lead to TLE (O(n))

//    // iteration forward
//    for (ll i = 0; i <= tiles; i += jumps) {
//        if (i == index)
//            return true;
//    }
//    // iteration backward
//    for (ll i = tiles; i >= 0; i -= jumps) {
//        if (i == index)
//            return true;
//    }

    // So a better way is to use mod operator O(1)

    // forward iteration
    if (index % jumps == 0)
        return true;
    // back journey
    if ((tiles - index) % jumps == 0)
        return true;
    return false;
}

int main() {
    // fast input
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        bool ans = solve();
        if (ans)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}
