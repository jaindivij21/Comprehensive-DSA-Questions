// FAST EXPONENTIATION using bitwise operaors (fast)
// O(logn)-- because thats the max number of powers (in binary) a number can have, and since multiplication takes unit time.

#include <iostream>
#define ll long long
using namespace std;

// global variable
ll const MAX = 10e9 + 7;

// function to cal exponent modulo MAX
ll exponent(ll pow, ll num)
{
    ll ans = 1;
    while (pow > 0)
    {
        // extract last bit of power
        if (pow & 1)
        {
            // if lastBit of power is 1, multiply ans w value of num
            ans = (ans * num) % MAX;
        }
        pow >>= 1;               // make power right shift so get the next bit
        num = (num * num) % MAX; // square the number everytime
    }
    return ans;
}

int main()
{
    cout << "Enter the number and the power" << endl;
    int a, n;
    cin >> n >> a;

    cout << "The ans is " << exponent(a, n) << endl;

    return 0;
}