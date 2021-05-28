// Program to find the GCD of a number using Euclidien Algorithm

#include<iostream>

using namespace std;

// recursive Euclidien GCD Formula
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

// LCM = a*b/gcd (formula)
int lcm(int a, int b, int gcd) {
    return (a * b) / gcd;
}

int main() {
    // Enter the numbers whose GCD is to be found
    int a, b;
    cout << "Enter the two numbers" << endl;
    cin >> a >> b;

    int gc = gcd(a, b);
    int lc = lcm(a, b, gc);

    cout << "GCD:" << gc << " & LCM:" << lc << endl;
    return 0;
}