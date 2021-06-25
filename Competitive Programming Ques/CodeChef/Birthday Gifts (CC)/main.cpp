// https://www.codechef.com/LTIME96C/problems/TWINGFT

#include<bits/stdc++.h>

#define ll long long
using namespace std;

bool com(ll a, ll b) {
    return a > b;
}

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;

        ll gift[n];

        ll i=0;
        for (; i < n; i++) {
            cin >> gift[i];
        }

        ll chefMax = 0;
        ll twinMax = 0;
        ll k2 = 0;

        sort(gift, gift + n, com);

        i = 0;
        ll flag = 0;
        for (; i <= 2 * k; i++) {
            if (flag == 0) {
                chefMax += gift[i];
                flag = 1;
            } else {
                // twin who moves second
                twinMax += gift[i];
                k2++;
                if (k2 == k) {
                    i++;
                    twinMax += gift[i];
                }
                flag = 0;
            }
        }
        cout << max(chefMax, twinMax) << endl;
    }
    return 0;
}