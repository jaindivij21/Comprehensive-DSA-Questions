// FAST EXPONENTIATION using bitwise operaors (fast)
// O(logn)-- because thats the max number of powers a number can have, and since multiplication takes unit time.

#include<iostream>

using namespace std;

int exponent(int pow, int num) {
    int ans = 1;
    while (pow > 0) {
        int lastBit = pow & 1;  // extract last bit of power
        if (lastBit) {
            // if lastBit of power is 1, multiply ans w value of num
            ans *= num;
        }
        pow >>= 1;  // make power right shift so get the next bit
        num *= num; // sqaure the number everytime
    }
    return ans;
}

int main() {
    cout << "Enter the number and the power" << endl;
    int a, n;
    cin >> n >> a;

    cout << "The ans is " << exponent(a, n) << endl;


    return 0;
}