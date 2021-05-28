// https://www.geeksforgeeks.org/modular-exponentiation-power-in-modular-arithmetic/

// Modulo Exponentiation
// given a,b,c calculate (a^b)c
// Use the concept ==> (a*b)%m = ((a % m)*(b % m)) % m
// Faster way to calculate exponents is the main concept to be used

// (a^b)%c = (a*a*a) % c (let b = 3) ==> using mod properites; (a%c * a%c * a%c)%c


#include<iostream>
#define ll long long
using namespace std;

ll exponent(ll num, ll pow, ll c) {
    ll ans = 1;
    while (pow > 0) {
        ll lastBit = pow & 1;  // extract last bit of power
        if (lastBit) {
            // if lastBit of power is 1, multiply ans w value of num
            ans = (ans * num) % c;
        }
        pow >>= 1;  // make power right shift so get the next bit
        num = (num*num) % c; // sqaure the number everytime
    }
    return ans;
}

int main() {
    // input numbers
    cout << "Enter the number, power and modulo" << endl;
    ll n, p, c;
    cin >> n >> p >> c;

    // calculate the ans but use mod properties i.e. let the number be n%c and then cal the ans. also do a mod c at the end
    cout << "The ans is " << (exponent((n % c), p, c) % c) << endl;


    return 0;
}

