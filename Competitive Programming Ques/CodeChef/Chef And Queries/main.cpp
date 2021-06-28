// CODECHEF JUNE STARTERS
// Chef and Queries
// https://www.codechef.com/START5B/problems/CHEFQUER

#include<bits/stdc++.h>

#define ll long long int

using namespace std;

int main() {
    ll n, q;
    cin >> n >> q;

    vector<ll> arr(n);
    for (ll i = 0; i < n; i++)
        cin >> arr[i];
    for (ll i = 0; i < q; i++) {
        ll qtype;
        cin >> qtype;
        vector<ll> query;
        switch (qtype) {
            case 1:
                ll l, r, x;
                cin >> l >> r >> x;
                l--;
                r--;
                for (ll k = l; k <= r; k++) {
                    arr[k] += ((x + (k + 1) - (l + 1)) * (x + (k + 1) - (l + 1)));
                }
                break;
            case 2:
                ll pos;
                cin >> pos;
                pos--;
                cout << arr[pos] << endl;
                break;
            default:
                break;
        }
    }

    return 0;
}