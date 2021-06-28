// https://www.codechef.com/LTIME97C/problems/UNONE
// June 2021 Lunchtime
// Unpleasant Ones

#include<bits/stdc++.h>

# define ll long long int

using namespace std;

// inner ones of a number can't change :: look at just the leftmost and rightmost bits
// for even numbers last digit is never 1, for odd both first and last are always 1 -> if we place all evens together : they will have no unpleasant ones
// also place evens before odd's otherwise there will be one extra unpleasant one
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> v(n);
        vector<ll> ans;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            if (v[i] % 2 == 0) {
                ans.push_back(v[i]);
            }
        }
        for (int i = 0; i < n; i++) {
            if (v[i] % 2 != 0)
                ans.push_back(v[i]);
        }
        for (auto i:ans)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}