// Inclusion Exclusion Problem
// Concept of Sets

// Find the number of numbers between less than equal to N which are divisible by any of the primes below 20

#include<iostream>
#include<cmath>

#define ll long long

using namespace std;

ll calAns(ll n) {
    // make an array of primes
    ll primes[] = {2, 3, 5, 7, 11, 13, 17, 19};

    // total number of subsets that can be formed corresponding to our 8 primes (0-7)
    ll subsets = (1 << 8) - 1;
    ll ans = 0;

    // go through all the subsets and add/subtract it to the result
    for (ll i = 1; i <= subsets; i++) {
        ll denominator = 1;
        // this will contain set Bits in our subset thus helping us decide if they are odd(add) or even(sub)
        ll setBits = __builtin_popcount(i);

        // for each subset itereate through all the bits
        for (ll j = 0; j <= 7; j++) {
            if ((i & (1 << j)) > 0) {
                // means the bit is set, therefore find its corresponding prime and multiply it to denom
                denominator = denominator * primes[j];
            }
        }
        if (setBits & 1) {
            // set bits is odd
            ans += (n / denominator);
        } else {
            // set bits are even
            ans -= (n / denominator);
        }
    }
    return ans;
}


int main() {
    ll testCases;
    cout << "Enter the number of test cases" << endl;
    cin >> testCases;

    // main part
    while (testCases--) {
        ll n;
        cout << "Enter the number" << endl;
        cin >> n;

        // The number of numbers less than n which are divisible by primes less than 20 are:
        cout << "Ans: " << calAns(n) << endl;
    }

    return 0;
}