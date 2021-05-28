// Program to find the kth Root

#include<iostream>
#include<algorithm>
#include<climits>

#define ll long long int
using namespace std;

ll root(ll n, ll k) {
    // limits
    ll l = 1;
    // we choose 8 zeros cuz max cases can be N = 10^15 & k=2 (cuz k = 1 is already considered); hence take sq root of 10^16
    ll r = 100000000;
    ll mid;
    ll ans;
    ll temp = 1;
    // binary search
    while (l <= r) {
        mid = l + (r - l) / 2;
        // mult mid k no of times w itself
        for (int i = 0; i < k; i++) {
            temp *= mid;
            // if in bw its get more than the number, break
            if (temp > n) {
                r = mid - 1;
                break;
            }
        }
        // if temp is eql to n, means mid is the ans or kth root
        if (temp == n)
            return mid;
        // other wise (if not perfect root), store mid in ans and try to find a closer ans by updating left & thus mid
        if (temp < n) {
            ans = mid;
            l = mid + 1;
        }
        // always make temp = 1 after each loops iteration 
        temp = 1;
    }
    return ans;
}

int main() {
    // test cases
    int t;
    cin >> t;
    while (t--) {
        // input the values
        ll n, k;
        cin >> n >> k;
        if (k == 1)
            cout << n << endl;
        else
            // main function
            cout << root(n, k) << endl;
    }
    return 0;
}