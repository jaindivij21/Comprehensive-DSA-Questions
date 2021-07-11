// Google Kickstart-D
// Arithmetic Squares : Brute Force
// https://codingcompetitions.withgoogle.com/kickstart/round/00000000004361e3/000000000082b813

#include<bits/stdc++.h>

#define ll long long int
using namespace std;

bool ifProgression(vector<ll> &arr) {
    ll diff = arr[1] - arr[0];
    for (ll i = 2; i <= arr.size() - 1; i++) {
        if (diff != arr[i] - arr[i - 1]) {
            return false;
        }
    }
    return true;
}

ll numberOfAP(ll arr[][3]) {
    ll count = 0;
    // for every row
    for (ll i = 0; i < 3; i++) {
        vector<ll> sq;
        for (ll j = 0; j < 3; j++) {
            sq.push_back(arr[i][j]);
        }
        if (ifProgression(sq))
            count++;
    }
    // for every column
    for (ll j = 0; j < 3; j++) {
        vector<ll> sq;
        for (ll i = 0; i < 3; i++) {
            sq.push_back(arr[i][j]);
        }
        if (ifProgression(sq))
            count++;
    }
    // for both diagonals
    vector<ll> sq = {arr[0][0], arr[1][1], arr[2][2]};
    if (ifProgression(sq))
        count++;
    sq = {arr[0][2], arr[1][1], arr[2][0]};
    if (ifProgression(sq))
        count++;

    return count;
}

int main() {
    int test;
    cin >> test;
    for (ll t = 1; t <= test; t++) {
        // take input
        ll arr[3][3];
        for (ll i = 0; i < 3; i++) {
            for (ll j = 0; j < 3; j++) {
                if (i == 1 && j == 1)
                    continue;
                cin >> arr[i][j];
            }
        }

        ll ans = 0;
        // make a function that returns the number of APs
        // now for every value of mid possible return the number of AP's possible
        arr[1][1] = (arr[0][0] + arr[2][2]) / 2;
        ans = max(ans, numberOfAP(arr));
        arr[1][1] = (arr[0][2] + arr[2][0]) / 2;
        ans = max(ans, numberOfAP(arr));
        arr[1][1] = (arr[1][0] + arr[1][2]) / 2;
        ans = max(ans, numberOfAP(arr));
        arr[1][1] = (arr[0][1] + arr[2][1]) / 2;
        ans = max(ans, numberOfAP(arr));
        
        // print
        cout << "Case #" << t << ": " << ans << endl;
    }
    return 0;
}