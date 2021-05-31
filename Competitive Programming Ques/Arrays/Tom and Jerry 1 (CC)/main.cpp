// https://www.codechef.com/LTIME96C/problems/TANDJ1
#include<bits/stdc++.h>

#define ll long long
using namespace std;


int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll a, b, c, d, K;
        cin >> a >> b >> c >> d >> K;

        ll x = (c - a < 0 ? -1 * (c - a) : c - a);
        ll y = (d - b < 0 ? -1 * (d - b) : d - b);
        ll shortestDistance = x + y;

        if (shortestDistance > K) {
            cout << "NO" << endl;
        } else if (shortestDistance == K) {
            cout << "YES" << endl;
        }
        else if ((K - shortestDistance) % 2 == 0)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}